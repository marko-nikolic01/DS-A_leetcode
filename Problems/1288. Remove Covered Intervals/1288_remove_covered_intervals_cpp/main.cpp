#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int removeCoveredIntervals(vector<vector<int>>& intervals) {
    short remainingIntervals = 0;
    int end = -1;

    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
    });

    for(short i = intervals.size() - 1; i > -1; --i) {
        if(intervals[i][1] > end) {
            ++remainingIntervals;
            end = intervals[i][1];
        }
    }

    return remainingIntervals;
}

void test(vector<vector<int>> intervals, int expected) {
    cout << "Intervals: ";
    for(vector<int> interval : intervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << removeCoveredIntervals(intervals) << endl;

    cout << endl;
}

int main() {
    test({{1, 4}, {3, 6}, {2, 8}}, 2);
    test({{1, 4}, {2, 3}}, 1);
    test({{1, 2}}, 1);
    test({{1, 5}, {2, 4}, {3, 6}}, 2);
    test({{1, 10}, {2, 3}, {4, 5}, {6, 7}}, 1);

    return 0;
}
