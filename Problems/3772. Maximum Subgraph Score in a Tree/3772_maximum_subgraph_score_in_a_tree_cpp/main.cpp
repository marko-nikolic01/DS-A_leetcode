#include <iostream>
#include <vector>

using namespace std;

void maxSubgraphScore(vector<vector<int>>& tree, vector<int>& good, int node, int previous) {
    if(good[node] < 1) {
        --good[node];
    }

    for(int i = tree[node].size() - 1; i > -1; --i) {
        if(tree[node][i] != previous) {
            maxSubgraphScore(tree, good, tree[node][i], node);

            if(good[tree[node][i]] > 0) {
                good[node] += good[tree[node][i]];
            }
        }
    }
}

void maxSubgraphScore(vector<int>& good, vector<vector<int>>& tree, int node, int previous) {
    if(previous > -1 && good[previous] > good[node]) {
        if(good[node] < 1) {
            good[node] += good[previous];
        } else {
            good[node] = good[previous];
        }
    }

    for(int i = tree[node].size() - 1; i > -1; --i) {
        if(tree[node][i] != previous) {
            maxSubgraphScore(good, tree, tree[node][i], node);
        }
    }
}

vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) {
    vector<vector<int>> tree(n);

    for(n = edges.size() - 1; n > -1; --n) {
        tree[edges[n][0]].push_back(edges[n][1]);
        tree[edges[n][1]].push_back(edges[n][0]);
    }

    maxSubgraphScore(tree, good, 0, -1);
    maxSubgraphScore(good, tree, 0, -1);

    return good;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(int n, vector<vector<int>> edges, vector<int> good, vector<int> expected) {
    cout << "n: " << n << endl;

    cout << "Edges: ";
    for(vector<int> edge : edges) {
        cout << "[" << edge[0] << ", " << edge[1] << "] ";
    }
    cout << endl;

    cout << "Nodes: ";
    printArray(good);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(maxSubgraphScore(n, edges, good));

    cout << endl;
}

int main() {
    test(3, {{0, 1}, {1, 2}}, {1, 0, 1}, {1, 1, 1});
    test(5, {{1, 0}, {1, 2}, {1, 3}, {3, 4}}, {0, 1, 0, 1, 1}, {2, 3, 2, 3, 3});
    test(2, {{0, 1}}, {0, 0}, {-1, -1});
    test(2, {{0, 1}}, {0, 1}, {0, 1});
    test(2, {{0, 1}}, {1, 0}, {1, 0});
    test(2, {{0, 1}}, {1, 1}, {2, 2});

    return 0;
}
