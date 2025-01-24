#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
    unordered_set<long long> isLampTurnedOn;

    unordered_map<int, int> illuminatedRows;
    unordered_map<int, int> illuminatedCoulmns;
    unordered_map<int, int> illuminatedForwardDiagonals;
    unordered_map<int, int> illuminatedBackwardDiagonals;

    for (int i = lamps.size() - 1; i > -1; --i) {
        if (isLampTurnedOn.find((long long)lamps[i][0] * n + lamps[i][1]) == isLampTurnedOn.end()) {
            isLampTurnedOn.insert((long long)lamps[i][0] * n + lamps[i][1]);

            ++illuminatedRows[lamps[i][0]];
            ++illuminatedCoulmns[lamps[i][1]];
            ++illuminatedForwardDiagonals[lamps[i][0] + lamps[i][1]];
            ++illuminatedBackwardDiagonals[lamps[i][0] - lamps[i][1]];
        }
    }

    int m = queries.size();
    vector<int> result(m);

    for (int i = 0; i < m; ++i) {
        if (illuminatedRows[queries[i][0]] > 0 || illuminatedCoulmns[queries[i][1]] > 0 ||
            illuminatedForwardDiagonals[queries[i][0] + queries[i][1]] > 0 ||
            illuminatedBackwardDiagonals[queries[i][0] - queries[i][1]] > 0) {
            result[i] = 1;

            queries[i][0] += 2;
            queries[i][1] += 2;

            for (int x = queries[i][0] - 3; x < queries[i][0]; ++x) {
                for (int y = queries[i][1] - 3; y < queries[i][1]; ++y) {
                    if (x >= 0 && x < n && y >= 0 && y < n &&
                        isLampTurnedOn.find((long long)x * n + y) != isLampTurnedOn.end()) {
                        isLampTurnedOn.erase((long long)x * n + y);

                        --illuminatedRows[x];
                        --illuminatedCoulmns[y];
                        --illuminatedForwardDiagonals[x + y];
                        --illuminatedBackwardDiagonals[x - y];
                    }
                }
            }
        } else {
            result[i] = 0;
        }
    }

    return result;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void runTestCase(int n, vector<vector<int>> lamps, vector<vector<int>> queries, vector<int> expected) {
    cout << "n: " << n << endl;

    cout << "Lamps: ";
    for(vector<int> lamp : lamps) {
        cout << "[" << lamp[0] << " " << lamp[1] << "] ";
    }
    cout << endl;

    cout << "Queries: ";
    for(vector<int> query : queries) {
        cout << "[" << query[0] << " " << query[1] << "] ";
    }
    cout << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result:   ";
    printArray(gridIllumination(n, lamps, queries));

    cout << endl;
}

int main() {
    runTestCase(5, {{0, 0}, {4, 4}}, {{1, 1}, {1, 0}}, {1, 0});
    runTestCase(5, {{0, 0}, {4, 4}}, {{1, 1}, {1, 1}}, {1, 1});
    runTestCase(5, {{0, 0}, {0, 4}}, {{0, 4}, {0, 1}, {1, 4}}, {1, 1, 0});
    runTestCase(5, {{0, 0}, {2, 2}, {4, 4}}, {{3, 3}, {4, 4}, {0, 0}}, {1, 1, 1});
    runTestCase(7, {{3, 3}, {5, 5}, {2, 4}}, {{3, 3}, {2, 4}, {6, 6}}, {1, 0, 1});

    return 0;
}
