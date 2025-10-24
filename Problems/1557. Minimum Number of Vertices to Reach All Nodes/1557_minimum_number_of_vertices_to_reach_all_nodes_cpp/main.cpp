#include <iostream>
#include <vector>

using namespace std;

vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
    vector<bool> isRoot(n, true);

    for(int i = edges.size() - 1; i > -1; --i) {
        isRoot[edges[i][1]] = false;
    }

    vector<int> roots;

    for(--n; n > -1; --n) {
        if(isRoot[n]) {
            roots.push_back(n);
        }
    }

    return roots;
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
    printArray(findSmallestSetOfVertices(n, edges));

    cout << endl;
}

int main() {
    test(6, {{0, 1}, {0, 2}, {2, 5}, {3, 4}, {4, 2}}, {3, 0});
    test(5, {{0, 1}, {2, 1}, {3, 1}, {1, 4}, {2, 4}}, {3, 2, 0});
    test(4, {{0, 1}, {1, 2}, {2, 3}}, {0});
    test(4, {{1, 0}, {2, 0}, {3, 1}, {3, 2}}, {3});
    test(5, {{1, 2}, {3, 4}}, {3, 1, 0});

    return 0;
}
