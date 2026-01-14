#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long separateSquares(vector<pair<long, long>>& intervals) {
    sort(intervals.begin(), intervals.end());

    long totalWidth = 0;
    long rightmost = (long)-1e18;

    int n = intervals.size();
    for(int i = 0; i < n; ++i) {
        if(intervals[i].first > rightmost) {
            totalWidth += intervals[i].second - intervals[i].first;
            rightmost = intervals[i].second;
        } else if(intervals[i].second > rightmost) {
            totalWidth += intervals[i].second - rightmost;
            rightmost = intervals[i].second;
        }
    }

    return totalWidth;
};

double separateSquares(vector<vector<int>>& squares) {
    vector<tuple<long, int, long, long>> events;

    int i;
    vector<pair<long, long>>::iterator it;
    int n = squares.size();
    for(i = 0; i < n; ++i) {
        events.push_back({squares[i][1], 1, squares[i][0], squares[i][0] + squares[i][2]});
        events.push_back({squares[i][1] + squares[i][2], -1, squares[i][0], squares[i][0] + squares[i][2]});
    }

    sort(events.begin(), events.end());

    vector<pair<long, long>> activeIntervals;
    long previousY = get<0>(events[0]);
    long totalArea = 0;
    vector<tuple<long, long, long>> horizontalSlices;
    long height;
    long width;

    n = events.size();
    for(i = 0; i < n; ++i) {
        if(get<0>(events[i]) > previousY && !activeIntervals.empty()) {
            height = get<0>(events[i]) - previousY;
            width = separateSquares(activeIntervals);
            horizontalSlices.push_back({previousY, height, width});
            totalArea += height * width;
        }

        if(get<1>(events[i]) == 1) {
            activeIntervals.push_back({get<2>(events[i]), get<3>(events[i])});
        } else {
            it = find(activeIntervals.begin(), activeIntervals.end(), make_pair(get<2>(events[i]), get<3>(events[i])));

            if(it != activeIntervals.end()) {
                activeIntervals.erase(it);
            }
        }

        previousY = get<0>(events[i]);
    }

    double half = (double)totalArea / 2.0;
    double accumulated = 0.0;
    double sliceArea;

    n = horizontalSlices.size();
    for(i = 0; i < n; ++i) {
        sliceArea = (double)get<1>(horizontalSlices[i]) * (double)get<2>(horizontalSlices[i]);

        if(accumulated + sliceArea >= half) {
            return (double)get<0>(horizontalSlices[i]) + (half - accumulated) / (double)get<2>(horizontalSlices[i]);
        }

        accumulated += sliceArea;
    }

    return (double)previousY;
}

void test(vector<vector<int>> squares, double expected) {
    cout << "Squares: ";
    for(vector<int> square : squares) {
        cout << "[" << square[0] << ", " << square[1] << ", " << square[2] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << separateSquares(squares) << endl;

    cout << endl;
}

int main() {
    test({{0, 0, 1}, {2, 2, 1}}, 1);
    test({{0, 0, 2}, {1, 1, 1}}, 1);
    test({{0, 0, 2}}, 1);
    test({{0, 0, 2}, {0, 1, 2}}, 1.5);
    test({{0, 0, 10}, {2, 2, 3}, {4, 4, 2}}, 5);

    return 0;
}
