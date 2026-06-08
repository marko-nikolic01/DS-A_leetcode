#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());

    long i;
    int iCurrent = 0;
    n = intervals.size();
    for(i = 1; i < n; ++i) {
        if(intervals[i][0] > intervals[iCurrent][1]) {
            intervals[++iCurrent][0] = intervals[i][0];
            intervals[iCurrent][1] = intervals[i][1];
        } else if(intervals[i][1] > intervals[iCurrent][1]) {
            intervals[iCurrent][1] = intervals[i][1];
        }
    }

    i = 0;
    while(iCurrent > -1) {
        i += ++intervals[iCurrent][1] - intervals[iCurrent--][0];
    }

    return i * ((brightness + 2) / 3);
}

void test(int n, int brightness, vector<vector<int>> intervals, long long expected) {
    cout << "n: " << n << endl;

    cout << "Brightness: " << brightness << endl;

    cout << "Intervals: ";
    for(vector<int> interval : intervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minEnergy(n, brightness, intervals) << endl;

    cout << endl;
}

int main() {
    test(5, 5, {{6, 12}}, 14);
    test(2, 1, {{0, 0}, {2, 2}}, 2);
    test(4, 2, {{1, 3}, {2, 4}}, 4);
    test(6, 4, {{0, 5}, {3, 8}}, 18);
    test(10, 7, {{0, 2}, {5, 7}, {10, 12}}, 27);

    return 0;
}
