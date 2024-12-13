#include <iostream>
#include <vector>

using namespace std;

int buttonWithLongestTime(vector<vector<int>>& events) {
    int button = events[0][0];
    int longestTime = events[0][1];

    events[0][0] = events.size();
    for(int i = 1; i < events[0][0]; ++i) {
        if(events[i][1] - events[i - 1][1] > longestTime) {
            button = events[i][0];
            longestTime = events[i][1] - events[i - 1][1];
        } else if(events[i][1] - events[i - 1][1] == longestTime && events[i][0] < button) {
            button = events[i][0];
        }
    }

    return button;
}

void printTestCase(vector<vector<int>>& events, int expected) {
    cout << "Events: ";
    for (vector<int> event : events) {
        cout << "[" << event[0] << ", " << event[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << buttonWithLongestTime(events) << endl;

    cout << endl;
}

int main() {
    vector<vector<int>> test1 = {{1, 2}, {2, 4}, {3, 6}, {4, 8}};
    int expected1 = 1;
    printTestCase(test1, expected1);

    vector<vector<int>> test2 = {{1, 1}, {2, 3}, {3, 7}, {4, 10}};
    int expected2 = 3;
    printTestCase(test2, expected2);

    vector<vector<int>> test3 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    int expected3 = 1;
    printTestCase(test3, expected3);

    vector<vector<int>> test4 = {{1, 5}, {2, 7}, {3, 9}, {4, 12}};
    int expected4 = 1;
    printTestCase(test4, expected4);

    vector<vector<int>> test5 = {{1, 5}, {2, 6}, {3, 8}, {4, 11}, {5, 14}};
    int expected5 = 1;
    printTestCase(test5, expected5);

    vector<vector<int>> test6 = {{1, 1}, {2, 3}, {3, 5}, {4, 7}, {5, 9}};
    int expected6 = 2;
    printTestCase(test6, expected6);

    return 0;
}
