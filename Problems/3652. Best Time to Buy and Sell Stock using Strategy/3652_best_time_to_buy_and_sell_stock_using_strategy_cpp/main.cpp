#include <iostream>
#include <vector>

using namespace std;

long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
    long profit = 0;
    long maxAdditionalProfit = 0;
    long additionalProfit = 0;

    int i;
    int j = k >> 1;
    int n = prices.size();
    for(i = 0; i < j; ++i) {
        profit += strategy[i] * prices[i];

        if(strategy[i] < 0) {
            additionalProfit += prices[i];
        } else if(strategy[i] > 0) {
            additionalProfit -= prices[i];
        }
    }

    for(i; i < k; ++i) {
        profit += strategy[i] * prices[i];

        if(strategy[i] < 0) {
            additionalProfit += prices[i] << 1;
        } else if(strategy[i] < 1) {
            additionalProfit += prices[i];
        }
    }

    maxAdditionalProfit = additionalProfit;

    for(i; i < n; ++i) {
        profit += strategy[i] * prices[i];

        if(strategy[i - k] < 0) {
            additionalProfit -= prices[i - k];
        } else if(strategy[i - k] > 0) {
            additionalProfit += prices[i - k];
        }

        additionalProfit -= prices[i - j];

        if(strategy[i] < 0) {
            additionalProfit += prices[i] << 1;
        } else if(strategy[i] < 1) {
            additionalProfit += prices[i];
        }

        if(additionalProfit > maxAdditionalProfit) {
            maxAdditionalProfit = additionalProfit;
        }
    }

    return maxAdditionalProfit > 0 ? profit + maxAdditionalProfit : profit;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> prices, vector<int> strategy, int k, long long expected) {
    cout << "Prices: ";
    printArray(prices);

    cout << "Strategy: ";
    printArray(strategy);

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxProfit(prices, strategy, k) << endl;

    cout << endl;
}

int main() {
    test({4, 2, 8}, {-1, 0, 1}, 2, 10);
    test({5, 4, 3}, {1, 1, 0}, 2, 9);
    test({3, 6, 9, 12}, {-1, -1, -1, -1}, 4, 21);
    test({2, 5, 1, 7}, {1, 0, 1, 0}, 2, 9);
    test({10, 1, 8, 2, 9}, {-1, 0, 1, -1, 0}, 4, 10);

    return 0;
}
