#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
   sort(intervals.begin(), intervals.end());

    vector<vector<int>> mergedIntervals = {intervals[0]};

   int n = intervals.size();
   for(int i = 1; i < n; ++i) {
        if(mergedIntervals.back()[1] >= intervals[i][0]) {
            if(intervals[i][1] > mergedIntervals.back()[1]) {
                mergedIntervals.back()[1] = intervals[i][1];
            }
        } else {
            mergedIntervals.push_back(intervals[i]);
        }
   }

   return mergedIntervals;
}

void printIntervals(const vector<vector<int>>& intervals) {
    for (const auto& interval : intervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
}

void runTest(vector<vector<int>>& intervals, const vector<vector<int>>& expected) {
    cout << "Intervals: ";
    printIntervals(intervals);
    cout << endl;

    cout << "Expected:  ";
    printIntervals(expected);
    cout << endl;

    cout << "Result:   ";
    printIntervals(merge(intervals));
    cout << endl;

    cout << endl;
}

int main() {
    vector<vector<int>> test1 = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> expected1 = {{1, 6}, {8, 10}, {15, 18}};
    runTest(test1, expected1);

    vector<vector<int>> test2 = {{1, 4}, {4, 5}};
    vector<vector<int>> expected2 = {{1, 5}};
    runTest(test2, expected2);

    vector<vector<int>> test3 = {{1, 4}, {2, 3}};
    vector<vector<int>> expected3 = {{1, 4}};
    runTest(test3, expected3);

    vector<vector<int>> test4 = {{1, 3}};
    vector<vector<int>> expected4 = {{1, 3}};
    runTest(test4, expected4);

    return 0;
}
