#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimumEffort(vector<vector<int>>& tasks) {
    int effort = 0;

    sort(tasks.begin(), tasks.end(), [&](vector<int>& a, vector<int>& b) {
        return a[1] - a[0] > b[1] - b[0];
    });

    for(int i = tasks.size() - 1; i > -1; --i) {
        effort = max(effort + tasks[i][0], tasks[i][1]);
    }

    return effort;
}

void test(vector<vector<int>> tasks, int expected) {
    cout << "Tasks: ";
    for(vector<int> task : tasks) {
        cout << "[" << task[0] << ", " << task[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minimumEffort(tasks) << endl;

    cout << endl;
}

int main() {
    test({{1, 2}, {2, 4}, {4, 8}}, 8);
    test({{1, 3}, {2, 4}, {10, 11}, {10, 12}, {8, 9}}, 32);
    test({{1, 7}, {2, 8}, {3, 9}, {4, 10}, {5, 11}, {6, 12}}, 27);
    test({{5, 5}}, 5);
    test({{3, 5}, {2, 6}, {4, 7}}, 11);

    return 0;
}
