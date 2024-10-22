#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void numOfMinutes(unordered_map<int, vector<int>>& managers, vector<int>& informTimes, int& informTime, int headID, int currentTime) {
    currentTime += informTimes[headID];

    if(managers.find(headID) == managers.end()) {
        if(currentTime > informTime) {
            informTime = currentTime;
        }
        return;
    }

    for(int i = managers[headID].size() - 1; i > -1; --i) {
        numOfMinutes(managers, informTimes, informTime, managers[headID][i], currentTime);
    }
}

int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    if(n == 1) {
        return 0;
    }

    unordered_map<int, vector<int>> managers;

    for(int i = manager.size() - 1; i > -1; --i) {
        if(managers.find(manager[i]) == managers.end()) {
            managers[manager[i]] = {i};
        } else {
            managers[manager[i]].push_back(i);
        }
    }

    int maxInformTime = 0;
    numOfMinutes(managers, informTime, maxInformTime, headID, 0);

    return maxInformTime;
}

void test(int n, int headID, vector<int> manager, vector<int> informTime, int expected) {
    cout << "n: " << n << endl;

    cout << "Head ID: " << headID << endl;

    cout << "Managers: ";
    for(int i = 0; i < manager.size(); i++) {
        cout << manager[i] << " ";
    }
    cout << endl;

    cout << "Inform times: ";
    for(int i = 0; i < informTime.size(); i++) {
        cout << informTime[i] << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numOfMinutes(n, headID, manager, informTime) << endl;

    cout << endl;
}

int main() {
    test(1, 0, {-1}, {0}, 0);
    test(7, 3, {1, 2, 3, -1, 2, 3, 4}, {0, 6, 5, 4, 2, 1, 1}, 15);
    test(4, 1, {2, -1, 2, 1}, {1, 2, 3, 4}, 6);
    test(8, 4, {5, 5, 4, 4, -1, -1, 1, 1}, {0, 0, 1, 2, 3, 3, 1, 1}, 5);

    return 0;
}
