#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

int mostBooked(int n, vector<vector<int>>& meetings) {
    vector<int> meetingsHeld(n, 0);
    set<short> availableRooms;
    short nAvailableRooms = n;
    short room;

    int i;
    for(i = n - 1; i > -1; --i) {
        availableRooms.insert(i);
    }

    sort(meetings.begin(), meetings.end());

    auto cmp = [](const pair<short, long>& a, const pair<short, long>& b) {
        return a.second != b.second ? a.second > b.second : a.first > b.first;
    };
    priority_queue<pair<short, long>, vector<pair<short, long>>, decltype(cmp)> ongoingMeetings(cmp);
    vector<long> delayedMeetings;
    int iDelayedMeetings = 0;
    int nDelayedMeetings = 0;

    int m = meetings.size();
    for(i = 0; i < m; ++i) {
        while(!ongoingMeetings.empty() && ongoingMeetings.top().second <= meetings[i][0]) {
            if(iDelayedMeetings < nDelayedMeetings) {
                room = ongoingMeetings.top().first;
                delayedMeetings[iDelayedMeetings] += ongoingMeetings.top().second;
                ongoingMeetings.pop();

                ongoingMeetings.push({room, delayedMeetings[iDelayedMeetings++]});
                ++meetingsHeld[room];
            } else {
                availableRooms.insert(ongoingMeetings.top().first);
                ++nAvailableRooms;
                ongoingMeetings.pop();
            }
        }

        if(nAvailableRooms > 0) {
            ongoingMeetings.push({*availableRooms.begin(), meetings[i][1]});
            ++meetingsHeld[*availableRooms.begin()];
            availableRooms.erase(*availableRooms.begin());
            --nAvailableRooms;
        } else {
            delayedMeetings.push_back(meetings[i][1] - meetings[i][0]);
            ++nDelayedMeetings;
        }
    }

    while(iDelayedMeetings < nDelayedMeetings) {
        room = ongoingMeetings.top().first;
        delayedMeetings[iDelayedMeetings] += ongoingMeetings.top().second;
        ongoingMeetings.pop();

        ongoingMeetings.push({room, delayedMeetings[iDelayedMeetings++]});
        ++meetingsHeld[room];
    }

    room = --n;

    for(--n; n > -1; --n) {
        if(meetingsHeld[n] >= meetingsHeld[room]) {
            room = n;
        }
    }

    return room;
}

void test(int n, vector<vector<int>> meetings, int expected) {
    cout << "Rooms: " << n << endl;

    cout << "Meetings: ";
    for(vector<int> meeting : meetings) {
        cout << "[" << meeting[0] << ", " << meeting[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << mostBooked(n, meetings) << endl;

    cout << endl;
}

int main() {
    test(2, {{0,10}, {1,5}, {2,7}, {3,4}}, 0);
    test(3, {{1,20}, {2,10}, {3,5}, {4,9}, {6,8}}, 1);
    test(1, {{0,5}, {5,10}, {10,15}}, 0);
    test(2, {{0,10}, {1,11}, {2,12}, {3,13}}, 0);
    test(5, {{0,3}, {1,4}, {2,5}, {3,6}, {4,7}}, 0);

    return 0;
}
