#include <iostream>
#include <vector>

using namespace std;

void specialNodes(vector<vector<int>>& tree, vector<tuple<int, int, int>>& distances, int distance, int node, int parent) {
    if(++distance < get<0>(distances[node])) {
        get<2>(distances[node]) = get<1>(distances[node]);
        get<1>(distances[node]) = get<0>(distances[node]);
        get<0>(distances[node]) = distance;
    } else if(distance < get<1>(distances[node])) {
        get<2>(distances[node]) = get<1>(distances[node]);
        get<1>(distances[node]) = distance;
    } else if(distance < get<2>(distances[node])) {
        get<2>(distances[node]) = distance;
    }

    for(int i = tree[node].size() - 1; i > -1; --i) {
        if(tree[node][i] != parent) {
            specialNodes(tree, distances, distance, tree[node][i], node);
        }
    }
}

int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
    vector<vector<int>> tree(n);
    vector<tuple<int, int, int>> distances(n, {n, n, n});

    for(int i = edges.size() - 1; i > -1; --i) {
        tree[edges[i][0]].push_back(edges[i][1]);
        tree[edges[i][1]].push_back(edges[i][0]);
    }

    specialNodes(tree, distances, -1, x, -1);
    specialNodes(tree, distances, -1, y, -1);
    specialNodes(tree, distances, -1, z, -1);
    x = 0;

    while(--n > -1) {
        if((long)get<0>(distances[n]) * get<0>(distances[n]) + (long)get<1>(distances[n]) * get<1>(distances[n]) == (long)get<2>(distances[n]) * get<2>(distances[n])) {
            ++x;
        }
    }

    return x;
}

void test(int n, vector<vector<int>> edges, int x, int y, int z, int expected) {
    cout << "n: " << n << endl;

    cout << "Edges: ";
    for(vector<int> edge : edges) {
        cout << "[" << edge[0] << ", " << edge[1] << "] ";
    }
    cout << endl;

    cout << "x: " << x << endl;

    cout << "y: " << y << endl;

    cout << "z: " << z << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << specialNodes(n, edges, x, y, z) << endl;

    cout << endl;
}

int main() {
    test(4, {{0, 1}, {0, 2}, {0, 3}}, 1, 2, 3, 3);
    test(4, {{0, 1}, {1, 2}, {2, 3}}, 0, 3, 2, 0);
    test(4, {{0, 1}, {1, 2}, {1, 3}}, 1, 3, 0, 1);
    test(4, {{0, 1}, {1, 2}, {2, 3}}, 0, 1, 2, 1);
    test(4, {{0, 1}, {0, 2}, {2, 3}}, 0, 2, 3, 1);

    return 0;
}
