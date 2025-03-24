#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countDays(int days, vector<vector<int>>& meetings) {
    sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    });

    int left = meetings[0][0];
    int right = meetings[0][1];

    int n = meetings.size();
    for(int i = 0; i < n; ++i) {
        if(meetings[i][0] > right) {
            --days -= right - left;

            left = meetings[i][0];
            right = meetings[i][1];
        } else if(meetings[i][1] > right) {
            right = meetings[i][1];
        }
    }

    return --days - right + left;
}

void test(int days, vector<vector<int>> meetings, int expected) {
    cout << "Days: " << days << endl;

    cout << "Meetings: ";
    for(vector<int> meeting : meetings) {
        cout << "[" << meeting[0] << ", " << meeting[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countDays(days, meetings) << endl;

    cout << endl;
}

int main() {
    test(10, {{5,7},{1,3},{9,10}}, 2);
    test(5, {{2,4},{1,3}}, 1);
    test(6, {{1,6}}, 0);
    test(8, {{2,3},{3,5},{8,8}}, 3);
    test(57, {{3,49},{23,44},{21,56},{26,55},{23,52},{2,9},{1,48},{3,31}}, 1);
    test(7, {{5, 5}}, 6);
    return 0;
}
