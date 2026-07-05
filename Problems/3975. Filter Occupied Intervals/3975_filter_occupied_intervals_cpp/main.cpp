#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
    vector<vector<int>> intervals;
    int start;
    int end;

    sort(occupiedIntervals.begin(), occupiedIntervals.end());
    --freeStart;
    ++freeEnd;

    unsigned short n = occupiedIntervals.size();
    for(unsigned short i = 0; i < n; ++i) {
        start = occupiedIntervals[i][0];
        end = occupiedIntervals[i][1];

        while(++i < n && occupiedIntervals[i][0] - 1 <= end) {
            if(occupiedIntervals[i][1] > end) {
                end = occupiedIntervals[i][1];
            }
        }
        --i;

        if(freeStart >= start) {
            intervals.push_back({start, min(end, freeStart)});
        }

        if(freeEnd <= end) {
            intervals.push_back({max(start, freeEnd), end});
        }
    }

    return intervals;
}

void test(vector<vector<int>> occupiedIntervals, int freeStart, int freeEnd, vector<vector<int>> expected) {
    cout << "Occupied intervals: ";
    for(vector<int> occupiedInterval : occupiedIntervals) {
        cout << "[" << occupiedInterval[0] << ", " << occupiedInterval[1] << "] ";
    }
    cout << endl;

    cout << "Free time start: " << freeStart << endl;

    cout << "Free time end: " << freeEnd << endl;

    cout << "Expected: ";
    for(vector<int> e : expected) {
        cout << "[" << e[0] << ", " << e[1] << "] ";
    }
    cout << endl;

    cout << "Result: ";
    for(vector<int> result : filterOccupiedIntervals(occupiedIntervals, freeStart, freeEnd)) {
        cout << "[" << result[0] << ", " << result[1] << "] ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    test({{2, 6}, {4, 8}, {10, 10}, {10, 12}, {14, 16}}, 7, 11, {{2, 6}, {12, 12}, {14, 16}});
    test({{1, 5}, {2, 3}}, 3, 8, {{1, 2}});
    test({{1, 1}, {2, 2}}, 100, 100, {{1, 2}});
    test({{5, 10}}, 5, 10, {});
    test({{1, 3}, {10, 12}}, 5, 7, {{1, 3}, {10, 12}});

    return 0;
}
