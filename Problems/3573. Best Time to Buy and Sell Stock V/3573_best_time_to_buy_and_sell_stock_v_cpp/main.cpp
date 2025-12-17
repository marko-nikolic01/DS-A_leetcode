#include <iostream>
#include <vector>

using namespace std;

long long maximumProfit(vector<int>& prices, int k) {
    vector<vector<long>> profit(k + 1, vector<long>(3));

    short i;
    short n = prices.size();
    for(i = 1; i <= k; ++i) {
        profit[i][1] -= prices[0];
        profit[i][2] = prices[0];
    }

    short j;
    for(i = 1; i < n; ++i) {
        for(j = k; j > 0; --j) {
            if(profit[j][1] + prices[i] > profit[j][0]) {
                if(profit[j][1] + prices[i] > profit[j][2] - prices[i]) {
                    profit[j][0] = profit[j][1] + prices[i];
                } else {
                    profit[j][0] = profit[j][2] - prices[i];
                }
            } else if(profit[j][2] - prices[i] > profit[j][0]) {
                profit[j][0] = profit[j][2] - prices[i];
            }

            if(profit[j - 1][0] - prices[i] > profit[j][1]) {
                profit[j][1] = profit[j - 1][0] - prices[i];
            }

            if(profit[j - 1][0] + prices[i] > profit[j][2]) {
                profit[j][2] = profit[j - 1][0] + prices[i];
            }
        }
    }

    return profit[k][0];
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> prices, int k, long long expected) {
    cout << "Prices: ";
    printArray(prices);

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maximumProfit(prices, k) << endl;

    cout << endl;
}

int main() {
    test({1, 7, 9, 8, 2}, 2, 14);
    test({12, 16, 19, 19, 8, 1, 19, 13, 9}, 3, 36);
    test({1, 2, 3, 4, 5, 6}, 2, 5);
    test({10, 8, 6, 4, 2}, 2, 8);
    test({5, 1, 5, 1, 5}, 2, 8);

    return 0;
}
