#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int intersectionSizeTwo(vector<vector<int>>& intervals) {
    short length = 0;
    int left = -1;
    int right = -1;

    sort(intervals.begin(), intervals.end(), [&](auto &a, auto &b) {
        return a[1] == b[1] ? a[0] < b[0] : a[1] > b[1];
    });

    for(short i = intervals.size() - 1; i > -1; --i) {
        if(intervals[i][0] > right) {
            right = intervals[i][1];
            left = --intervals[i][1];
            length += 2;
        } else if(intervals[i][0] > left) {
            left = right;
            right = intervals[i][1];
            ++length;
        }
    }

    return length;
}

void test(vector<vector<int>> intervals, int expected) {
    cout << "Intervals: ";
    for(vector<int> interval : intervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << intersectionSizeTwo(intervals) << endl;

    cout << endl;
}

int main() {
    test({{1, 3}, {3, 7}, {8, 9}}, 5);
    test({{1, 3}, {1, 4}, {2, 5}, {3, 5}}, 3);
    test({{1, 2}, {2, 3}, {2, 4}, {4, 5}}, 5);
    test({{1, 10}, {2, 9}, {3, 8}, {4, 7}}, 2);
    test({{1, 2}, {3, 4}, {5, 6}, {7, 8}}, 8);

    return 0;
}
