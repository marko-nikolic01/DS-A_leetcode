#include <iostream>
#include <vector>

using namespace std;

int findChampion(int n, vector<vector<int>>& edges) {
    vector<bool> isChampion(n, true);

    for(short i = edges.size() - 1; i > -1; --i) {
        if(isChampion[edges[i][1]]) {
            --n;
            isChampion[edges[i][1]] = false;
        }
    }

    if(n > 1) {
        return -1;
    }

    n = 0;
    while(!isChampion[n]) {
        ++n;
    }

    return n;
}

void test(int n, vector<vector<int>> edges, int expected) {
    cout << "n: " << n << endl;

    cout << "Teams: ";
    for(vector<int> edge : edges) {
        cout << "[" << edge[0] << ", " << edge[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << findChampion(n, edges) << endl;

    cout << endl;
}

int main() {
    test(3, {{0, 1}, {1, 2}}, 0);
    test(4, {{0, 2}, {1, 3}, {1, 2}}, -1);
    test(1, {}, 0);
    test(3, {{0, 1}, {0, 2}}, 0);
    test(4, {{0, 1}, {2, 3}}, -1);

    return 0;
}
