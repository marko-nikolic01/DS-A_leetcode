#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Edge {
    int u;
    int v;
    int w;
    int type;

    Edge() {}
    Edge(const vector<int>& e) : u(e[0]), v(e[1]), w(e[2]), type(e[3]) {}
};

class DSU {
public:
    vector<int> parent;

    DSU(const vector<int>& p) : parent(p) {}

    int find(int x) {
        return parent[x] == x ? x : (parent[x] = find(parent[x]));
    }

    void join(int x, int y) {
        int px = find(x);
        int py = find(y);

        if(px != py) {
            parent[px] = py;
        }
    }
};

int maxStability(int n, vector<vector<int>>& edges, int k) {
    if(edges.size() < --n) {
        return -1;
    }

    int stability = -1;
    int m = edges.size();
    vector<Edge> sortedEdges(m);
    vector<Edge> mustEdges;
    vector<Edge> optionalEdges;

    int i;
    for(i = 0; i < m; ++i) {
        sortedEdges[i] = Edge(edges[i]);
    }

    for(i = 0; i < m; ++i) {
        if (sortedEdges[i].type == 1) {
            mustEdges.push_back(sortedEdges[i]);
        } else {
            optionalEdges.push_back(sortedEdges[i]);
        }
    }

    if(mustEdges.size() > n) {
        return -1;
    }

    sort(optionalEdges.begin(), optionalEdges.end(), [](const Edge& a, const Edge& b) {
        return b.w < a.w;
    });

    int selectedInit = 0;
    int mustMinStability = 200000;
    vector<int> initialParent(n + 1);
    iota(initialParent.begin(), initialParent.end(), 0);
    DSU dsuInit(initialParent);

    m = mustEdges.size();
    for(i = 0; i < m; ++i) {
        if(dsuInit.find(mustEdges[i].u) == dsuInit.find(mustEdges[i].v) || selectedInit == n) {
            return -1;
        }

        dsuInit.join(mustEdges[i].u, mustEdges[i].v);
        ++selectedInit;
        mustMinStability = min(mustMinStability, mustEdges[i].w);
    }

    int l = 0;
    int r = mustMinStability;
    int middle;
    int selected;
    int doubledCount;

    m = optionalEdges.size();
    while(l < r) {
        middle = l + ((r - l + 1) >> 1);
        DSU dsu(dsuInit.parent);
        selected = selectedInit;
        doubledCount = 0;

        for(i = 0; i < m; ++i) {
            if(dsu.find(optionalEdges[i].u) == dsu.find(optionalEdges[i].v)) {
                continue;
            }

            if(optionalEdges[i].w >= middle) {
                dsu.join(optionalEdges[i].u, optionalEdges[i].v);
                ++selected;
            } else if(doubledCount < k && optionalEdges[i].w * 2 >= middle) {
                ++doubledCount;
                dsu.join(optionalEdges[i].u, optionalEdges[i].v);
                ++selected;
            } else {
                break;
            }

            if(selected == n) {
                break;
            }
        }

        if(selected != n) {
            r = middle - 1;
        } else {
            stability = middle;
            l = middle;
        }
    }

    return stability;
}

void test(int n, vector<vector<int>> edges, int k, int expected) {
    cout << "n: " << n << endl;

    cout << "Edges: ";
    for(vector<int> edge : edges) {
        cout << "[" << edge[0] << ", " << edge[1] << ", " << edge[2] << ", " << edge[3] << "] ";
    }
    cout << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxStability(n, edges, k) << endl;

    cout << endl;
}

int main() {
    test(3, {{0, 1, 2, 1}, {1, 2, 3, 0}}, 1, 2);
    test(3, {{0, 1, 4, 0}, {1, 2, 3, 0}, {0, 2, 1, 0}}, 2, 6);
    test(3, {{0, 1, 1, 1}, {1, 2, 1, 1}, {2, 0, 1, 1}}, 0, -1);
    test(4, {{0, 1, 5, 0}, {1, 2, 4, 0}, {2, 3, 3, 0}, {0, 3, 2, 0}}, 1, 4);
    test(2, {{0, 1, 7, 1}}, 0, 7);

    return 0;
}
