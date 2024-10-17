#include <iostream>
#include <vector>

using namespace std;

int findCenter(vector<vector<int>>& edges) {
    return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] ? edges[0][0] : edges[0][1];
}

void test(vector<vector<int>> edges, int expected) {
    cout << "Graph: ";
    for (auto edge : edges) {
        cout << "[" << edge[0] << ", " << edge[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << findCenter(edges) << endl;

    cout << endl;
}

int main() {
    test({{1, 2}, {2, 3}, {2, 4}}, 2);
    test({{1, 3}, {1, 2}, {4, 1}}, 1);
    test({{5, 1}, {1, 2}, {1, 3}, {4, 1}}, 1);
    test({{10, 20}, {20, 30}, {20, 40}}, 20);

    return 0;
}
