#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
    vector<int> peopleWithSecret = {0, firstPerson};
    vector<bool> hasSecret(n, false);
    hasSecret[0] = true;
    hasSecret[firstPerson] = true;

    vector<vector<int>> meetingConnections(n, vector<int>(1, 0));
    vector<int> peopleWithSecretInMeetings;
    int meetingTime;
    int meetingNumber = 0;
    int person;

    sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[2] > b[2];
    });

    for(n = meetings.size() - 1; n > -1; --n) {
        meetingTime = meetings[n][2];
        ++meetingNumber;

        while(n > -1 && meetings[n][2] == meetingTime) {
            if(meetingConnections[meetings[n][0]][0] < meetingNumber) {
                meetingConnections[meetings[n][0]].resize(1);
                meetingConnections[meetings[n][0]][0] = meetingNumber;
            }

            if(meetingConnections[meetings[n][1]][0] < meetingNumber) {
                meetingConnections[meetings[n][1]].resize(1);
                meetingConnections[meetings[n][1]][0] = meetingNumber;
            }

            meetingConnections[meetings[n][0]].push_back(meetings[n][1]);
            meetingConnections[meetings[n][1]].push_back(meetings[n][0]);

            if(hasSecret[meetings[n][0]]) {
                peopleWithSecretInMeetings.push_back(meetings[n][0]);
            }

            if(hasSecret[meetings[n][1]]) {
                peopleWithSecretInMeetings.push_back(meetings[n][1]);
            }

            --n;
        }
        ++n;

        while(!peopleWithSecretInMeetings.empty()) {
            person = peopleWithSecretInMeetings.back();
            peopleWithSecretInMeetings.pop_back();

            for(firstPerson = meetingConnections[person].size() - 1; firstPerson > 0; --firstPerson) {
                if(!hasSecret[meetingConnections[person][firstPerson]]) {
                    hasSecret[meetingConnections[person][firstPerson]] = true;
                    peopleWithSecret.push_back(meetingConnections[person][firstPerson]);
                    peopleWithSecretInMeetings.push_back(meetingConnections[person][firstPerson]);
                }
            }

            meetingConnections[person].resize(1);
        }
    }

    return peopleWithSecret;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(int n, vector<vector<int>> meetings, int firstPerson, vector<int> expected) {
    cout << "n: " << n << endl;

    cout << "Meetings: ";
    for(vector<int> meeting : meetings) {
        cout << "[" << meeting[0] << ", " << meeting[1] << ", " << meeting[2] << "] ";
    }
    cout << endl;

    cout << "First person: " << firstPerson << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(findAllPeople(n, meetings, firstPerson));

    cout << endl;
}

int main() {
    test(6, {{1,2,5},{2,3,8},{1,5,10}}, 1, {0,1,2,3,5});
    test(4, {{3,1,3},{1,2,2},{0,3,3}}, 3, {0,3,1});
    test(5, {{3,4,2},{1,2,1},{2,3,1}}, 1, {0,1,2,3,4});
    test(3, {{1,2,1},{0,2,1}}, 1, {0,1,2});
    test(4, {{1,2,5},{2,3,10},{0,3,10}}, 1, {0,1,2,3});

    return 0;
}
