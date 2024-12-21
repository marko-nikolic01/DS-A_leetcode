#include <iostream>
#include <vector>

using namespace std;

int maxKDivisibleComponents(vector<vector<int>>& tree, vector<int>& values, int k, int node, int parent, int& components) {
    int value = values[node] % k;

    for (int i = tree[node].size() - 1; i > -1; --i) {
        if(tree[node][i] != parent) {
            value += maxKDivisibleComponents(tree, values, k, tree[node][i], node, components);
            value %= k;
        }
    }

    if(value == 0) {
        ++components;
        return 0;
    }
    return value;
}

int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
    if(n == 1) {
        return 1;
    }

    vector<vector<int>> tree(n);
    for(int i = edges.size() - 1; i > -1; --i) {
        tree[edges[i][0]].push_back(edges[i][1]);
        tree[edges[i][1]].push_back(edges[i][0]);
    }

    n = 0;
    maxKDivisibleComponents(tree, values, k, tree[0][0], -1, n);

    return n;
}

void test(int n, vector<vector<int>> edges, vector<int> values, int k, int expected) {
    cout << "n: " << n << endl;

    cout << "Edges: ";
    for (vector<int> edge : edges) {
        cout << "[" << edge[0] << "," << edge[1] << "] ";
    }
    cout << endl;

    cout << "Values: ";
    for (int value : values) {
        cout << value << " ";
    }
    cout << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxKDivisibleComponents(n, edges, values, k) << endl;

    cout << endl;
}

int main() {
    test(3, {{0, 1}, {1, 2}}, {3, 6, 9}, 3, 3);
    test(5, {{0, 1}, {1, 2}, {1, 3}, {3, 4}}, {5, 10, 5, 15, 15}, 5, 5);
    test(6, {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {4, 5}}, {6, 3, 9, 12, 3, 3}, 6, 3);
    test(7, {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}}, {2, 4, 6, 8, 10, 12, 14}, 4, 4);
    test(5, {{0, 2}, {1, 2}, {1, 3}, {2, 4}}, {1, 8, 1, 4, 4}, 6, 2);
    test(7, {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}}, {3, 0, 6, 1, 5, 2, 1}, 3, 3);
    test(1, {}, {6}, 3, 1);

    return 0;
}
