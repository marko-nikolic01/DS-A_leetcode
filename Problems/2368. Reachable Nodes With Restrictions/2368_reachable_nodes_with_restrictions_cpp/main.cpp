#include <iostream>
#include <vector>

using namespace std;

void reachableNodes(vector<vector<int>>& tree, vector<bool>& unrestricted, int node, int& reachable) {
    ++reachable;

    for(int i = tree[node].size() - 1; i > -1; --i) {
        if(unrestricted[tree[node][i]]) {
            unrestricted[tree[node][i]] = false;
            reachableNodes(tree, unrestricted, tree[node][i], reachable);
        }
    }
}

int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
    vector<vector<int>> tree(n);
    vector<bool> unrestricted(n, true);

    for(n -= 2; n > -1; --n) {
        tree[edges[n][0]].push_back(edges[n][1]);
        tree[edges[n][1]].push_back(edges[n][0]);
    }

    for(int i = restricted.size() - 1; i > -1; --i) {
        unrestricted[restricted[i]] = false;
    }

    unrestricted[0] = false;
    reachableNodes(tree, unrestricted, 0, ++n);

    return n;
}

void test(int n, vector<vector<int>> edges, vector<int> restricted, int expected) {
    cout << "n: " << n << endl;

    cout << "Edges: ";
    for (vector<int> edge : edges) {
        cout << "[" << edge[0] << " " << edge[1] << "] ";
    }
    cout << endl;

    cout << "Restricted: ";
    for (int node : restricted) {
        cout << node << " ";
    }

    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << reachableNodes(n, edges, restricted) << endl;

    cout << endl;
}

int main() {
    test(7, {{0,1},{1,2},{3,1},{4,0},{0,5},{5,6}}, {4,5}, 4);
    test(7, {{0,1},{0,2},{0,5},{0,4},{3,2},{6,5}}, {4,2,1}, 3);
    test(4, {{0,1},{1,2},{2,3}}, {3}, 3);
    test(5, {{0,1},{0,2},{1,3},{2,4}}, {3,4}, 3);
    test(6, {{0,1},{1,2},{1,3},{3,4},{4,5}}, {2,3}, 2);
    test(8, {{0,1},{1,2},{2,3},{0,4},{4,5},{5,6},{6,7}}, {5,6,7}, 5);

    return 0;
}
