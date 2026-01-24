#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
    int starSum = INT_MIN;
    int n = vals.size();
    vector<vector<int>> stars(n);

    int i;
    for(i = edges.size() - 1; i > -1; --i) {
        stars[edges[i][0]].push_back(vals[edges[i][1]]);
        stars[edges[i][1]].push_back(vals[edges[i][0]]);
    }

    int m;
    while(--n > -1) {
        sort(stars[n].begin(), stars[n].end(), greater<int>());

        m = min(k, (int)stars[n].size());
        for(i = 0; i < m && stars[n][i] > 0; ++i) {
            vals[n] += stars[n][i];
        }

        if(vals[n] > starSum) {
            starSum = vals[n];
        }
    }

    return starSum;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> vals, vector<vector<int>> edges, int k, int expected) {
    cout << "Values: ";
    printArray(vals);

    cout << "Edges: ";
    for(vector<int> edge : edges) {
        cout << "[" << edge[0] << ", " << edge[1] << "] ";
    }
    cout << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxStarSum(vals, edges, k) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 3, 4, 10, -10, -20}, {{0, 1}, {1, 2}, {1, 3}, {3, 4}, {3, 5}, {3, 6}}, 2, 16);
    test({-5}, {}, 0, -5);
    test({1, -8, 0}, {{1, 0}, {2, 1}}, 2, 1);
    test({17, 49, -34, -17, -7, -23, 24}, {{3, 1}, {5, 1}, {0, 3}, {4, 6}, {1, 4}, {3, 4}, {6, 3}, {2, 6}, {5, 2}, {1, 6}, {6, 0}, {2, 3}, {3, 5}, {2, 1}, {0, 2}, {5, 0}, {0, 4}}, 6, 90);
    test({5, -2, 3, -1}, {{0, 1}, {0, 2}, {0, 3}}, 3, 8);

    return 0;
}
