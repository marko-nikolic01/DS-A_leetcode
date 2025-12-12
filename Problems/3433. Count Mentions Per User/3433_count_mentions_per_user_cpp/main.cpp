#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
    vector<int> mentions(numberOfUsers, 0);
    vector<int> offline(numberOfUsers--, 0);

    short n = events.size();
    vector<int> time(n, 0);
    vector<short> sortedEvents(n);

    short i;
    short j;
    short m;
    for(i = 0; i < n; ++i) {
        sortedEvents[i] = i;

        m = events[i][1].length();
        for(j = 0; j < m; ++j) {
            time[i] = 10 * time[i] + events[i][1][j] - '0';
        }
    }

    sort(sortedEvents.begin(), sortedEvents.end(), [&](short& a, short& b) {
        return time[a] != time[b] ? time[a] > time[b] : (events[a][0][0] < 'N' ? true : false);
    });

    while(--n > -1) {
        if(events[sortedEvents[n]][0][0] < 'N') {
            m = events[sortedEvents[n]][2].length();
            for(i = 0; i < m; ++i) {
                if(events[sortedEvents[n]][2][i] < 'B') {
                    for(j = numberOfUsers; j > -1; --j) {
                        ++mentions[j];
                    }

                    i += 3;
                } else if(events[sortedEvents[n]][2][i] < 'I') {
                    for(j = numberOfUsers; j > -1; --j) {
                        if(time[sortedEvents[n]] > offline[j]) {
                            ++mentions[j];
                        }
                    }

                    i += 4;
                } else {
                    i += 2;
                    j = events[sortedEvents[n]][2][i] - '0';

                    while(++i < m && events[sortedEvents[n]][2][i] > '/') {
                        j = 10 * j + events[sortedEvents[n]][2][i] - '0';
                    }

                    ++mentions[j];
                }
            }
        } else {
            j = events[sortedEvents[n]][2][0] - '0';

            m = events[sortedEvents[n]][2].length();
            for(i = 1; i < m; ++i) {
                j = 10 * j + events[sortedEvents[n]][2][i] - '0';
            }

            offline[j] = time[sortedEvents[n]] + 59;
        }
    }

    return mentions;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(int numberOfUsers, vector<vector<string>> events, vector<int> expected) {
    cout << "Number of users: " << numberOfUsers << endl;

    cout << "Events: ";
    for(vector<string> event : events) {
        cout << "[" << "\"" << event[0] << "\"" << ", " << "\"" << event[1] << "\"" << ", " << "\"" << event[2] << "\"" << "] ";
    }
    cout << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(countMentions(numberOfUsers, events));

    cout << endl;
}

int main() {
    test(2, {{"MESSAGE", "10", "id1 id0"}, {"OFFLINE", "11", "0"}, {"MESSAGE", "71", "HERE"}}, {2, 2});
    test(2, {{"MESSAGE", "10", "id1 id0"}, {"OFFLINE", "11", "0"}, {"MESSAGE", "12", "ALL"}}, {2, 2});
    test(2, {{"OFFLINE", "10", "0"}, {"MESSAGE", "12", "HERE"}}, {0, 1});
    test(3, {{"MESSAGE", "1", "ALL"}, {"OFFLINE", "66", "1"}, {"MESSAGE", "66", "HERE"}, {"OFFLINE", "5", "1"}}, {2, 1, 2});
    test(3, {{"MESSAGE", "2", "HERE"}, {"OFFLINE", "2", "1"}, {"OFFLINE", "1", "0"}, {"MESSAGE", "61", "HERE"}}, {1, 0, 2});

    return 0;
}
