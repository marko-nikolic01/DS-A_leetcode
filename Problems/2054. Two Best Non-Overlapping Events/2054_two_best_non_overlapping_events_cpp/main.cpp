#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxTwoEvents(vector<vector<int>>& events) {
    int twoEvents = 0;
    vector<pair<int, int>> previousEvents;
    int previousEvent = 0;
    int left;
    int right;
    int middle;

    previousEvents.push_back({-1, 0});
    sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] != b[1] ? a[1] > b[1] : a[0] > b[0];
    });

    int n;
    for(int i = events.size() - 1; i > -1; --i) {
        n = previousEvents.size();
        left = 0;
        right = --n;
        while(left <= right){
            middle = (left + right) >> 1;

            if(previousEvents[middle].first < events[i][0]) {
                if(middle == n || previousEvents[middle + 1].first >= events[i][0]) {
                    break;
                }

                left = ++middle;
            } else {
                right = --middle;
            }
        }

        if(previousEvents[middle].second + events[i][2] > twoEvents) {
            twoEvents = previousEvents[middle].second + events[i][2];
        }

        if(events[i][2] > previousEvent) {
            previousEvent = events[i][2];
        }

        if(events[i][1] > previousEvents[n].first) {
            previousEvents.push_back({events[i][1], previousEvent});
        } else if(previousEvent > previousEvents[n].second) {
            previousEvents[n].second = previousEvent;
        }
    }

    return twoEvents;
}

void test(vector<vector<int>> events, int expected) {
    cout << "Events: ";
    for(vector<int> event : events) {
        cout << "[" << event[0] << ", " << event[1] << ", " << event[2] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxTwoEvents(events) << endl;

    cout << endl;
}

int main() {
    test({{1, 3, 2}, {4, 5, 2}, {2, 4, 3}}, 4);
    test({{1, 3, 2}, {4, 5, 2}, {1, 5, 5}}, 5);
    test({{1, 5, 3}, {1, 5, 1}, {6, 6, 5}}, 8);
    test({{1, 2, 4}, {3, 4, 3}, {2, 3, 1}, {5, 6, 5}}, 9);
    test({{1, 4, 5}, {2, 4, 3}, {5, 7, 4}, {6, 8, 6}}, 11);

    return 0;
}
