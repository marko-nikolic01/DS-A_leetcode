#include <iostream>
#include <vector>

using namespace std;

int maximalNetworkRank(int n, vector<vector<int>>& roads) {
    short rank = 0;
    vector<short> cities(n, 0);
    vector<vector<bool>> connections(n, vector<bool>(n, false));

    short i;
    for(i = roads.size() - 1; i > -1; --i) {
        ++cities[roads[i][0]];
        ++cities[roads[i][1]];
        connections[roads[i][0]][roads[i][1]] = true;
        connections[roads[i][1]][roads[i][0]] = true;
    }

    while(--n > 0) {
        for(i = n - 1; i > -1; --i) {
            if(connections[n][i]) {
                if(cities[n] + cities[i] - 1 > rank) {
                    rank = cities[n] + cities[i] - 1;
                }
            } else if(cities[n] + cities[i] > rank) {
                rank = cities[n] + cities[i];
            }
        }
    }

    return rank;
}

void test(int n, vector<vector<int>> roads, int expected) {
    cout << "n: " << n << endl;

    cout << "Roads: ";
    for(vector<int> road : roads) {
        cout << "[" << road[0] << ", " << road[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maximalNetworkRank(n, roads) << endl;

    cout << endl;
}

int main() {
    test(4, {{0, 1}, {0, 3}, {1, 2}, {1, 3}}, 4);
    test(5, {{0, 1}, {0, 3}, {1, 2}, {1, 3}, {2, 3}, {2, 4}}, 5);
    test(8, {{0, 1}, {1, 2}, {2, 3}, {2, 4}, {5, 6}, {5, 7}}, 5);
    test(2, {}, 0);
    test(6, {{0, 1}, {2, 3}, {4, 5}}, 2);
    return 0;
}
