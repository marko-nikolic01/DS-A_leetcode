#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
    unordered_map<int, pair<int, int>> verticals;
    unordered_map<int, pair<int, int>> horizontals;

    int i;
    n = buildings.size();
    for(i = --n; i > -1; --i) {
        if(verticals.find(buildings[i][0]) == verticals.end()) {
            verticals[buildings[i][0]] = {buildings[i][1], buildings[i][1]};
        } else if(buildings[i][1] < verticals[buildings[i][0]].first) {
            verticals[buildings[i][0]].first = buildings[i][1];
        } else if(buildings[i][1] > verticals[buildings[i][0]].second) {
            verticals[buildings[i][0]].second = buildings[i][1];
        }

        if(horizontals.find(buildings[i][1]) == horizontals.end()) {
            horizontals[buildings[i][1]] = {buildings[i][0], buildings[i][0]};
        } else if(buildings[i][0] < horizontals[buildings[i][1]].first) {
            horizontals[buildings[i][1]].first = buildings[i][0];
        } else if(buildings[i][0] > horizontals[buildings[i][1]].second) {
            horizontals[buildings[i][1]].second = buildings[i][0];
        }
    }

    for(n; n > -1; --n) {
        if(buildings[n][0] > horizontals[buildings[n][1]].first && buildings[n][0] < horizontals[buildings[n][1]].second && buildings[n][1] > verticals[buildings[n][0]].first && buildings[n][1] < verticals[buildings[n][0]].second) {
            ++i;
        }
    }

    return ++i;
}

void test(int n, vector<vector<int>> buildings, int expected) {
    cout << "n: " << n << endl;

    cout << "Buildings: ";
    for(vector<int> building : buildings) {
        cout << "[" << building[0] << ", " << building[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countCoveredBuildings(n, buildings) << endl;

    cout << endl;
}

int main() {
    test(3, {{1, 2}, {2, 2}, {3, 2}, {2, 1}, {2, 3}}, 1);
    test(3, {{1, 1}, {1, 2}, {2, 1}, {2, 2}}, 0);
    test(5, {{1, 3}, {3, 2}, {3, 3}, {3, 5}, {5, 3}}, 1);
    test(4, {{2, 4}, {1, 2}, {3, 1}, {1, 4}, {2, 3}, {3, 3}, {2, 2}, {1, 3}}, 1);
    test(6, {{2, 3}, {2, 5}, {4, 3}, {4, 5}, {3, 2}, {3, 6}, {3, 4}}, 0);

    return 0;
}
