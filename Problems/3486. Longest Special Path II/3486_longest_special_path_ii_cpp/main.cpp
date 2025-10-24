#include <iostream>
#include <vector>

using namespace std;

void longestSpecialPath(vector<vector<pair<int, int>>>& tree, vector<int>& nodes, vector<int>& occurences, int duplicate, vector<int>& path, int& longestPath, int& longestPathNodes, int currentPath, int node, int parent, int edge, int i) {
    path.push_back(edge);
    currentPath += edge;
    int previous = occurences[nodes[node]];
    occurences[nodes[node]] = path.size() - 1;

    int j = min(previous, duplicate);
    while(i <= j) {
        currentPath -= path[++i];
    }

    if(previous > -1) {
        duplicate = max(duplicate, previous);
    }

    if(currentPath > longestPath) {
        longestPath = currentPath;
        longestPathNodes = path.size() - i;
    } else if(currentPath == longestPath && path.size() - i < longestPathNodes) {
        longestPathNodes = path.size() - i;
    }

    for(j = tree[node].size() - 1; j > -1; --j) {
        if(tree[node][j].first != parent) {
            longestSpecialPath(tree, nodes, occurences, duplicate, path, longestPath, longestPathNodes, currentPath, tree[node][j].first, node, tree[node][j].second, i);
        }
    }

    path.pop_back();
    occurences[nodes[node]] = previous;
}

vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
    int n = nums.size();
    vector<vector<pair<int, int>>> tree(n);

    for(n = edges.size() - 1; n > -1; --n) {
        tree[edges[n][0]].push_back({edges[n][1], edges[n][2]});
        tree[edges[n][1]].push_back({edges[n][0], edges[n][2]});
    }

    vector<int> occurences(50001, -1);
    vector<int> path;
    int longestPath = 0;
    int longestPathNodes = 0;

    longestSpecialPath(tree, nums, occurences, -1, path, longestPath, longestPathNodes, 0, 0, -1, 0, 0);

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
    test({{0, 1, 1}, {1, 2, 3}, {1, 3, 1}, {2, 4, 6}, {4, 7, 2}, {3, 5, 2}, {3, 6, 5}, {6, 8, 3}}, {1, 1, 0, 3, 1, 2, 1, 1, 0}, {9, 3});
    test({{1, 0, 3}, {0, 2, 4}, {0, 3, 5}}, {1, 1, 0, 2}, {5, 2});
    test({{0, 1, 5}}, {1, 1}, {5, 2});
    test({{0, 1, 7}}, {2, 3}, {7, 2});
    test({{0, 1, 9}}, {4, 4}, {9, 2});

    return 0;
}
