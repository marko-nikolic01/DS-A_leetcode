#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    int low = prices[0];
    int profit = 0;

    for(int i = 1; i < prices.size(); ++i) {
        if(prices[i] < low) {
            low = prices[i];
        } else if(prices[i] - low > profit) {
            profit = prices[i] - low;
        }
    }

    return profit;
}

void printTestCase(vector<int> prices, int expected) {
    int result = maxProfit(prices);

    cout << "Prices: ";
    for (int price : prices) {
        cout << price << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;
    cout << "Result: " << result << endl;

    cout << (result == expected ? "PASS" : "FAIL") << endl;
    cout << "------------------------" << endl;
}

int main() {
    printTestCase({7, 1, 5, 3, 6, 4}, 5);
    printTestCase({7, 6, 4, 3, 1}, 0);
    printTestCase({1, 2, 3, 4, 5}, 4);
    printTestCase({2, 4, 1}, 2);
    printTestCase({3, 2, 6, 5, 0, 3}, 4);

    return 0;
}
