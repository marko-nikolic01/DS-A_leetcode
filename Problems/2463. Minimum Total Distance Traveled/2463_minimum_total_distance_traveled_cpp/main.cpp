#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long minimumTotalDistance(vector<int>& robots, vector<vector<int>>& factories) {
    vector<int> factoryPositions;

    sort(begin(robots), end(robots));
    sort(begin(factories), end(factories));

    int i;
    short n = factories.size();
    for(i = 0; i < n; ++i) {
        while(--factories[i][1] > -1) {
            factoryPositions.push_back(factories[i][0]);
        }
    }

    n = robots.size();
    int m = factoryPositions.size();
    vector<long> next(++m, 0);
    vector<long> current(m--, 0);
    long assign;
    long skip;

    current[m--] = 1000000000000;

    while(--n > -1) {
        for(i = m; i > -1; --i) {
            current[i] = min(abs(robots[n] - factoryPositions[i]) + next[i + 1], current[i + 1]);
        }

        next = current;
    }

    return current[0];
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> robots, vector<vector<int>> factories, long long expected) {
    cout << "Robots: ";
    printArray(robots);

    cout << "Factories: ";
    for(vector<int> factory : factories) {
        cout << "[" << factory[0] << ", " << factory[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minimumTotalDistance(robots, factories) << endl;

    cout << endl;
}

int main() {
    test({0, 4, 6}, {{2, 2}, {6, 2}}, 4);
    test({1, -1}, {{-2, 1}, {2, 1}}, 2);
    test({5}, {{5, 1}}, 0);
    test({0}, {{3, 1}}, 3);
    test({1, 3}, {{2, 2}}, 2);

    return 0;
}
