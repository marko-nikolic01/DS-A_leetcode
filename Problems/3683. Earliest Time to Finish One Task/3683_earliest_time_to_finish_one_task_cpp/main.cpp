#include <iostream>
#include <vector>

using namespace std;

int earliestTime(vector<vector<int>>& tasks) {
    short time = 200;

    for(short i = tasks.size() - 1; i > -1; --i) {
        if(tasks[i][0] + tasks[i][1] < time) {
            time = tasks[i][0] + tasks[i][1];
        }
    }

    return time;
}

void test(vector<vector<int>> tasks, int expected) {
    cout << "Tasks: ";
    for(vector<int> task : tasks) {
        cout << "[" << task[0] << ", " << task[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << earliestTime(tasks) << endl;

    cout << endl;
}


int main() {
    test({{1, 6}, {2, 3}}, 5);
    test({{100, 100}, {100, 100}, {100, 100}}, 200);
    test({{5, 10}, {3, 12}, {8, 2}}, 10);
    test({{7, 5}}, 12);
    test({{1, 5}, {2, 3}, {3, 3}}, 5);

    return 0;
}
