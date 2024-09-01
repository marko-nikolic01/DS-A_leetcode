#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> newIntervals;

    int n = intervals.size();
    int i = 0;

    while(i < n && intervals[i][1] < newInterval[0]) {
        newIntervals.push_back(intervals[i++]);
    }

    while(i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i++][1]);
    }
    newIntervals.push_back(newInterval);

    for(i; i < n; ++i) {
        newIntervals.push_back(intervals[i]);
    }

    return newIntervals;
}

void printIntervals(const vector<vector<int>>& intervals) {
    for (const auto& interval : intervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
}

void testInsert(vector<vector<int>> intervals, vector<int> newInterval, vector<vector<int>> expected) {
    cout << "Intervals: ";
    printIntervals(intervals);

    cout << "New Interval: [" << newInterval[0] << ", " << newInterval[1] << "]" << endl;


    cout << "Expected: ";
    printIntervals(expected);

    cout << "Result:   ";
    printIntervals(insert(intervals, newInterval));

    cout << endl;
}

int main() {
    vector<vector<int>> intervals1 = {{1, 3}, {6, 9}};
    vector<int> newInterval1 = {2, 5};
    vector<vector<int>> expected1 = {{1, 5}, {6, 9}};
    testInsert(intervals1, newInterval1, expected1);

    vector<vector<int>> intervals2 = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
    vector<int> newInterval2 = {4, 8};
    vector<vector<int>> expected2 = {{1, 2}, {3, 10}, {12, 16}};
    testInsert(intervals2, newInterval2, expected2);

    vector<vector<int>> intervals3 = {{1, 5}};
    vector<int> newInterval3 = {2, 7};
    vector<vector<int>> expected3 = {{1, 7}};
    testInsert(intervals3, newInterval3, expected3);

    vector<vector<int>> intervals4 = {{1, 2}, {3, 4}, {5, 6}};
    vector<int> newInterval4 = {0, 0};
    vector<vector<int>> expected4 = {{0, 0}, {1, 2}, {3, 4}, {5, 6}};
    testInsert(intervals4, newInterval4, expected4);

    return 0;
}
