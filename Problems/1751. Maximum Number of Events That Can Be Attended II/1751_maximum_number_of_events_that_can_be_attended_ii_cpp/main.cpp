#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxValue(int currentStart, vector<vector<int>>& events) {
    int left = 0, right = events.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (events[mid][1] < currentStart) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

int maxValue(vector<vector<int>>& events, int k) {
    sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    });

    int n = events.size();
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    int prev;

    int j;
    for(int i = 1; i <= n; ++i) {
        prev = maxValue(events[i - 1][0], events);

        for(j = 1; j <= k; ++j) {
            dp[i][j] = max(dp[i - 1][j], dp[prev + 1][j - 1] + events[i - 1][2]);
        }
    }

    return dp[n][k];
}


void test(vector<vector<int>> events, int k, int expected) {
    cout << "Events: ";
    for(vector<int> event : events) {
        cout << "[" << event[0] << ", " << event[1] << ", " << event[2] << "] ";
    }
    cout << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxValue(events, k) << endl;

    cout << endl;
}

int main() {
    test({{1, 2, 4}, {3, 4, 3}, {2, 3, 1}}, 2, 7);
    test({{1, 2, 4}, {3, 4, 3}, {2, 3, 10}}, 2, 10);
    test({{1, 1, 1}, {2, 2, 2}, {3, 3, 3}, {4, 4, 4}}, 3, 9);
    test({{1, 10, 5}, {2, 3, 6}, {11, 12, 10}}, 2, 16);
    test({{1, 3, 2}, {2, 5, 4}, {6, 9, 6}}, 2, 10);

    return 0;
}
