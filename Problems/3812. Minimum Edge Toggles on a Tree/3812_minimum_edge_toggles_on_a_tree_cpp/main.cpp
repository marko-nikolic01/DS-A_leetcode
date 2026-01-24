#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void minimumFlips(vector<vector<pair<int, int>>>& tree, vector<int>& flips, string& start, string& target, int parent, int node, int edge) {
    for(int i = tree[node].size() - 1; i > -1; --i) {
        if(tree[node][i].first != parent) {
            minimumFlips(tree, flips, start, target, node, tree[node][i].first, tree[node][i].second);
        }
    }

    if(start[node] != target[node]) {
        if(parent < 0) {
            flips.resize(1);
            flips[0] = -1;
        } else {
            flips.push_back(edge);
            start[node] = start[node] == '0' ? '1' : '0';
            start[parent] = start[parent] == '0' ? '1' : '0';
        }
    }
}

vector<int> minimumFlips(int n, vector<vector<int>>& edges, string start, string target) {
    vector<int> flips;
    vector<vector<pair<int, int>>> tree(n);

    for(int i = edges.size() - 1; i > -1; --i) {
        tree[edges[i][0]].push_back({edges[i][1], i});
        tree[edges[i][1]].push_back({edges[i][0], i});
    }

    minimumFlips(tree, flips, start, target, -1, 0, 0);
    sort(flips.begin(), flips.end());

    return flips;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(int n, vector<vector<int>> edges, string start, string target, vector<int> expected) {
    cout << "n: " << n << endl;

    cout << "Edges: ";
    for(vector<int> edge : edges) {
        cout << "[" << edge[0] << ", " << edge[1] << "] ";
    }
    cout << endl;

    cout << "Start: " << start << endl;

    cout << "Target: " << target << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(minimumFlips(n, edges, start, target));

    cout << endl;
}

int main() {
    test(3, {{0, 1}, {1, 2}}, "010", "100", {0});
    test(7, {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {3, 5}, {1, 6}}, "0011000", "0010001", {1, 2, 5});
    test(2, {{0, 1}}, "00", "01", {-1});
    test(5, {{0, 1}, {0, 2}, {1, 3}, {1, 4}}, "10101", "10101", {});
    test(4, {{0, 1}, {1, 2}, {2, 3}}, "0000", "1010", {0, 1});

    return 0;
}
