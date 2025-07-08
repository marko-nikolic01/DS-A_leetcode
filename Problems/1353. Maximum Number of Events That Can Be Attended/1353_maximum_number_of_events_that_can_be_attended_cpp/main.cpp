#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int maxEvents(vector<vector<int>>& events) {
    int n = events.size();
    int maxDay = 0;

    int i;
    for(i = 0; i < n; ++i) {
        if(events[i][1] > maxDay) {
            maxDay = events[i][1];
        }
    }

    priority_queue<int, vector<int>, greater<>> pq;
    sort(events.begin(), events.end());
    int eventsAttended = 0;

    int j = 0;
    for(i = 0; i <= maxDay; ++i) {
        while(j < n && events[j][0] <= i) {
            pq.push(events[j][1]);
            ++j;
        }

        while(!pq.empty() && pq.top() < i) {
            pq.pop();
        }

        if(!pq.empty()) {
            pq.pop();
            ++eventsAttended;
        }
    }

    return eventsAttended;
}

void test(vector<vector<int>> events, int expected) {
    cout << "Events: ";
    for(vector<int> event : events) {
        cout << "[" << event[0] << ", " << event[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxEvents(events) << endl;

    cout << endl;
}

int main() {
    test({{1, 2}, {3, 4}, {5, 6}}, 3);
    test({{1, 3}, {1, 3}, {1, 3}}, 3);
    test({{1, 1}, {1, 1}, {1, 1}}, 1);
    test({{1, 2}, {5, 6}, {10, 11}}, 3);
    test({{1, 3}, {2, 4}, {3, 5}, {6, 6}}, 4);

    return 0;
}
