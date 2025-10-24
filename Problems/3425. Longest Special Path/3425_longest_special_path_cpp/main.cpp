#include <iostream>
#include <vector>

using namespace std;

void longestSpecialPath(vector<vector<pair<int, int>>>& tree, vector<int>& nodes, vector<int>& occurences, vector<int>& path, int& longestPath, int& longestPathNodes, int node, int parent, int edge, int i) {
    int previous = occurences[nodes[node]];

    occurences[nodes[node]] = path.size();
    path.push_back(path.back() + edge);

    if(previous >= i) {
        i = previous + 1;
    }

    if(path.back() - path[i] > longestPath) {
        longestPath = path.back() - path[i];
        longestPathNodes = path.size() - i;
    } else if(path.back() - path[i] == longestPath && path.size() - i < longestPathNodes) {
        longestPathNodes = path.size() - i;
    }

    for(int j = tree[node].size() - 1; j > -1; --j) {
        if(tree[node][j].first != parent) {
            longestSpecialPath(tree, nodes, occurences, path, longestPath, longestPathNodes, tree[node][j].first, node, tree[node][j].second, i);
        }
    }

    occurences[nodes[node]] = previous;
    path.pop_back();
}

vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
    int n = nums.size();
    vector<vector<pair<int, int>>> tree(n);

    for(n = edges.size() - 1; n > -1; --n) {
        tree[edges[n][0]].push_back({edges[n][1], edges[n][2]});
        tree[edges[n][1]].push_back({edges[n][0], edges[n][2]});
    }

    vector<int> occurences(50001, -1);
    vector<int> path(1, 0);
    int longestPath = -1;
    int longestPathNodes = 0;

    longestSpecialPath(tree, nums, occurences, path, longestPath, longestPathNodes, 0, -1, 0, 1);

    return {longestPath, longestPathNodes};
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<vector<int>> edges, vector<int> nums, vector<int> expected) {
    cout << "Edges: ";
    for(vector<int> edge : edges) {
        cout << "[" << edge[0] << ", " << edge[1] << "] ";
    }
    cout << endl;

    cout << "Nodes: ";
    printArray(nums);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(longestSpecialPath(edges, nums));

    cout << endl;
}

int main() {
    test({{0, 1, 2}, {1, 2, 3}, {1, 3, 5}, {1, 4, 4}, {2, 5, 6}}, {2, 1, 2, 1, 3, 1}, {6, 2});
    test({{1, 0, 8}}, {2, 2}, {0, 1});
    test({{4, 0, 2}, {3, 1, 8}, {3, 2, 9}, {3, 4, 8}}, {5, 5, 1, 3, 3}, {9, 2});
    test({{0, 1, 7}}, {4, 5}, {7, 2});
    test({{0, 1, 10}}, {3, 3}, {0, 1});

    return 0;
}
