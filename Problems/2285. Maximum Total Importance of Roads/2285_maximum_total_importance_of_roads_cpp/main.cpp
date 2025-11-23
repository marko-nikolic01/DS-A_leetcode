#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long maximumImportance(int n, vector<vector<int>>& roads) {
    long importance = 0;
    vector<int> cities(n, 0);

    for(int i = roads.size() - 1; i > -1; --i) {
        ++cities[roads[i][0]];
        ++cities[roads[i][1]];
    }

    sort(cities.begin(), cities.end());

    while(n > 0) {
        importance += (long)n * cities[--n];
    }

    return importance;
}

void test(int n, vector<vector<int>> roads, long long expected) {
    cout << "n: " << n << endl;

    cout << "Roads: ";
    for(vector<int> road : roads) {
        cout << "[" << road[0] << ", " << road[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maximumImportance(n, roads) << endl;

    cout << endl;
}

int main() {
    test(5, {{0, 1}, {1, 2}, {2, 3}, {0, 2}, {1, 3}, {2, 4}}, 43);
    test(5, {{0, 3}, {2, 4}, {1, 3}}, 20);
    test(4, {{0, 1}, {1, 2}, {2, 3}}, 17);
    test(3, {{0, 1}, {1, 2}, {0, 2}}, 12);
    test(6, {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}}, 45);

    return 0;
}
