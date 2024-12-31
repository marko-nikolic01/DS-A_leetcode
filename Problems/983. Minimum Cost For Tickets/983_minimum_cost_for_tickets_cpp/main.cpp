#include <iostream>
#include <vector>

using namespace std;

int mincostTickets(vector<int>& days, vector<int>& costs) {
    int n = days.size();
    vector<int> dp(n, 0);

    int start7 = 0;
    int start30 = 0;

    for(int i = 0; i < n; ++i) {
        while(days[i] - days[start7] > 6) {
            ++start7;
        }

        while(days[i] - days[start30] > 29) {
            ++start30;
        }

        dp[i] = i > 0 ? dp[i - 1] + costs[0] : costs[0];

        int cost = start7 > 0 ? dp[start7 - 1] + costs[1] : costs[1];
        if(cost < dp[i]) {
            dp[i] = cost;
        }

        cost = start30 > 0 ? dp[start30 - 1] + costs[2] : costs[2];
        if(cost < dp[i]) {
            dp[i] = cost;
        }
    }

    return dp[--n];
}

void test(vector<int> days, vector<int> costs, int expected) {
    cout << "Days: ";
    for (int day : days) {
        cout << day << " ";
    }
    cout << endl;

    cout << "Costs: ";
    for (int cost : costs) {
        cout << cost << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << mincostTickets(days, costs) << endl;

    cout << endl;
}

int main() {
    test({1, 4, 6, 7, 8, 20}, {2, 7, 15}, 11);
    test({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31}, {2, 7, 15}, 17);
    test({1, 3, 5, 7, 8, 10, 15, 20, 25}, {3, 10, 25}, 25);
    test({1, 10, 20, 30, 40, 50}, {1, 5, 10}, 6);
    test({1, 3, 7, 8, 14, 20, 30}, {3, 10, 25}, 21);

    return 0;
}
