#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
    vector<int> userActiveMinutes(k, 0);
    unordered_map<int, unordered_set<int>> activity;

    for(k = logs.size() - 1; k > -1; --k) {
        activity[logs[k][0]].insert(logs[k][1]);
    }

    for(unordered_map<int, unordered_set<int>>::iterator it = activity.begin(); it != activity.end(); ++it) {
        ++userActiveMinutes[it->second.size() - 1];
    }

    return userActiveMinutes;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<vector<int>> logs, int k, vector<int> expected) {
    cout << "Logs: ";
    for(vector<int> log : logs) {
        cout << "[" << log[0] << " " << log[1] << "] ";
    }
    cout << endl;

    cout << "k: " << k << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(findingUsersActiveMinutes(logs, k));

    cout << endl;
}

int main() {
    test({{0, 5}, {1, 2}, {0, 2}, {0, 5}, {1, 3}}, 5, {0, 2, 0, 0, 0});
    test({{1, 1}, {2, 2}, {2, 3}}, 4, {1, 1, 0, 0});
    test({{5, 10}, {5, 10}, {5, 10}}, 3, {1, 0, 0});
    test({{1, 1}, {1, 2}, {1, 3}, {2, 1}, {3, 2}, {3, 3}}, 3, {1, 1, 1});
    test({{1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {2, 2}, {2, 2}}, 6, {1, 0, 0, 0, 1, 0});

    return 0;
}
