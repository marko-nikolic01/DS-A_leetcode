#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    int maximumProfit = 0;
    int n = startTime.size();
    vector<int> jobs(n);
    vector<pair<int, int>> profits(1, {0, 0});
    int left;
    int right;
    int middle;

    int i;
    for(i = 0; i < n; ++i) {
        jobs[i] = i;
    }

    sort(jobs.begin(), jobs.end(), [&](int a, int b) {
        return endTime[a] != endTime[b] ? endTime[a] < endTime[b] : startTime[a] < startTime[b];
    });

    int nProfits;
    for(i = 0; i < n; ++i) {
        nProfits = profits.size();
        left = 0;
        right = --nProfits;

        while(left <= right) {
            middle = (left + right) >> 1;

            if(profits[middle].first <= startTime[jobs[i]]) {
                if(middle == nProfits || profits[middle + 1].first > startTime[jobs[i]]) {
                    break;
                }

                left = ++middle;
            } else {
                right = --middle;
            }
        }

        if(profits[middle].second + profit[jobs[i]] > maximumProfit) {
            maximumProfit = profits[middle].second + profit[jobs[i]];
        }

        if(endTime[jobs[i]] > profits[nProfits].first) {
            profits.push_back({endTime[jobs[i]], maximumProfit});
        } else {
            profits[nProfits].second = maximumProfit;
        }
    }

    return maximumProfit;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> startTime, vector<int> endTime, vector<int> profit, int expected) {
    cout << "Start times: ";
    printArray(startTime);

    cout << "End times: ";
    printArray(endTime);

    cout << "Profits: ";
    printArray(profit);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << jobScheduling(startTime, endTime, profit) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 3, 3}, {3, 4, 5, 6}, {50, 10, 40, 70}, 120);
    test({1, 2, 3, 4, 6}, {3, 5, 10, 6, 9}, {20, 20, 100, 70, 60}, 150);
    test({1, 1, 1}, {2, 3, 4}, {5, 6, 4}, 6);
    test({1, 3, 6, 9}, {3, 6, 9, 12}, {10, 20, 30, 40}, 100);
    test({1, 2, 3, 4}, {10, 3, 4, 5}, {100, 20, 20, 20}, 100);

    return 0;
}
