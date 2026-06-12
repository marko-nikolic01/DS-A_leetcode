#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class LCA {
    private:
        int n;
        int m;
        vector<int> d;
        vector<vector<int>> e;
        vector<vector<int>> f;

    public:
        LCA(vector<vector<int>>& edges, int root = 1) {
            n = edges.size() + 1;
            m = (log(n) / log(2)) + 1;
            e.resize(n + 1);
            d.resize(n + 1);
            f.resize(n + 1, vector<int>(m, 0));

            for(auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                e[u].push_back(v);
                e[v].push_back(u);
            }

            dfs(root, 0);

            for(int i = 1; i < m; ++i) {
                for(int x = 1; x <= n; ++x) {
                    f[x][i] = f[f[x][i - 1]][i - 1];
                }
            }
        }

        void dfs(int x, int fa) {
            f[x][0] = fa;

            for(auto& y : e[x]) {
                if(y != fa) {
                    d[y] = d[x] + 1;
                    dfs(y, x);
                }
            }
        }

        int lca(int x, int y) {
            if(d[x] > d[y]) {
                swap(x, y);
            }

            for(int i = m - 1; i > -1; --i) {
                if(d[x] <= d[f[y][i]]) {
                    y = f[y][i];
                }
            }

            if(x == y) {
                return x;
            }

            for(int i = m - 1; i > -1; --i) {
                if(f[y][i] != f[x][i]) {
                    x = f[x][i];
                    y = f[y][i];
                }
            }

            return f[x][0];
        }

        int dis(int x, int y) {
            return d[x] + d[y] - d[lca(x, y)] * 2;
        }
};

vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
    LCA lca(edges, 1);
    int m = queries.size();
    vector<int> res(m);
    int p2[100010];
    int x;
    int y;

    p2[0] = 1;
    for(x = 1; x < 100010; ++x) {
        p2[x] = p2[x - 1] * 2 % 1000000007;
    }

    for(int i = 0; i < m; i++) {
        x = queries[i][0];
        y = queries[i][1];

        if(x != y) {
            res[i] = p2[lca.dis(x, y) - 1];
        }
    }

    return res;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<vector<int>> edges, vector<vector<int>> queries, vector<int> expected) {
    cout << "Edges: ";
    for(vector<int> edge : edges) {
        cout << "[" << edge[0] << ", " << edge[1] << "] ";
    }
    cout << endl;

    cout << "Queries: ";
    for(vector<int> query : queries) {
        cout << "[" << query[0] << ", " << query[1] << "] ";
    }
    cout << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(assignEdgeWeights(edges, queries));

    cout << endl;
}

int main() {
    test({{1, 2}}, {{1, 1}, {1, 2}}, {0, 1});
    test({{1, 2}, {1, 3}, {3, 4}, {3, 5}}, {{1, 4}, {3, 4}, {2, 5}}, {2, 1, 4});
    test({{1, 2}, {2, 3}, {3, 4}, {4, 5}}, {{1, 5}}, {8});
    test({{1, 2}, {1, 3}}, {{2, 3}}, {2});
    test({{1, 2}, {2, 3}, {3, 4}, {3, 5}}, {{1, 5}}, {4});

    return 0;
}
