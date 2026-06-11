#include <iostream>
#include <vector>

using namespace std;

int assignEdgeWeights(vector<vector<int>>& tree, int node, int parent) {
    int depth = 0;
    int childDepth;

    for(int i = tree[node].size() - 1; i > -1; --i) {
        if(tree[node][i] != parent) {
            childDepth = assignEdgeWeights(tree, tree[node][i], node);

            if(++childDepth > depth) {
                depth = childDepth;
            }
        }
    }

    return depth;
}

int assignEdgeWeights(vector<vector<int>>& edges) {
    int n = edges.size();
    vector<vector<int>> tree(++n);

    for(n -= 2; n > -1; --n) {
        tree[--edges[n][0]].push_back(--edges[n][1]);
        tree[edges[n][1]].push_back(edges[n][0]);
    }

    int depth = assignEdgeWeights(tree, 0, -1);

    n = 1;
    while(--depth > 0) {
        n = (n << 1) % 1000000007;
    }

    return n;
}

void test(vector<vector<int>> edges, int expected) {
    cout << "Edges: ";
    for(vector<int> edge : edges) {
        cout << "[" << edge[0] << ", " << edge[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << assignEdgeWeights(edges) << endl;

    cout << endl;
}

int main() {
    test({{1, 2}}, 1);
    test({{1, 2}, {1, 3}, {3, 4}, {3, 5}}, 2);
    test({{1, 2}, {2, 3}, {3, 4}, {4, 5}}, 8);
    test({{1, 2}, {1, 3}, {1, 4}, {1, 5}}, 1);
    test({{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}}, 32);

    return 0;
}
