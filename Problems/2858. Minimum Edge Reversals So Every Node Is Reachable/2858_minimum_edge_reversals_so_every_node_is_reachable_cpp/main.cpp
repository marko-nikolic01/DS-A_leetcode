#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int minEdgeReversals(unordered_map<int, unordered_map<int, int>>& g, int i, int j) {
    int current = 0;

    unordered_map<int, int>::iterator end = g[j].end();
    for(unordered_map<int, int>::iterator it = g[j].begin(); it != end; ++it) {
        if(it->first != i) {
            current += minEdgeReversals(g, j, it->first) + it->second;
        }
    }

    return current;
}

void minEdgeReversals(vector<int>& reversals, unordered_map<int, unordered_map<int, int>>& g, int i, int j) {
        reversals[i] = j;

        unordered_map<int, int>::iterator end = g[i].end();
        for(unordered_map<int, int>::iterator it = g[i].begin(); it != end; ++it) {
            if(reversals[it->first] < 0) {
                minEdgeReversals(reversals, g, it->first, j - it->second + g[it->first][i]);
            }
        }
}

vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
    vector<int> reversals(n, -1);
    unordered_map<int, unordered_map<int, int>> g;

    n = edges.size();
    for(int i = 0; i < n; ++i) {
        g[edges[i][0]][edges[i][1]] = 0;
        g[edges[i][1]][edges[i][0]] = 1;
    }

    minEdgeReversals(reversals, g, 0, minEdgeReversals(g, -1, 0));

    return reversals;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(int n, vector<vector<int>> edges, vector<int> expected) {
    cout << "n: " << n << endl;

    cout << "Edges: ";
    for(vector<int> edge : edges) {
        cout << "[" << edge[0] << ", " << edge[1] << "] ";
    }
    cout << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(minEdgeReversals(n, edges));

    cout << endl;
}

int main() {
    test(4, {{2, 0}, {2, 1}, {1, 3}}, {1, 1, 0, 2});
    test(3, {{1, 2}, {2, 0}}, {2, 0, 1});
    test(4, {{0, 1}, {1, 2}, {2, 3}}, {0, 1, 2, 3});
    test(4, {{3, 2}, {2, 1}, {1, 0}}, {3, 2, 1, 0});
    test(5, {{0, 1}, {1, 2}, {1, 3}, {3, 4}}, {0, 1, 2, 2, 3});

    return 0;
}
