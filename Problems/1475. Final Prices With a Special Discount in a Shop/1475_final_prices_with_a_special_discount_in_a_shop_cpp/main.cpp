#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> finalPrices(vector<int>& prices) {
    queue<int> unchangedPrices;

    int n = prices.size();

    int nUnchanged = 0;

    for(int i = 1; i < n; ++i) {
        int nChanged = 0;

        for(int j = 0; j < nUnchanged; ++j) {
            if(prices[i] <= prices[unchangedPrices.front()]) {
                prices[unchangedPrices.front()] -= prices[i];
                unchangedPrices.pop();
                ++nChanged;
            } else {
                unchangedPrices.push(unchangedPrices.front());
                unchangedPrices.pop();
            }
        }

        nUnchanged -= nChanged;

        if(prices[i] <= prices[i - 1]) {
            prices[i - 1] -= prices[i];
        } else {
            unchangedPrices.push(i - 1);
            ++nUnchanged;
        }
    }

    return prices;
}

void test(vector<int> prices, vector<int> expected) {
    cout << "Prices: ";
    for (int price : prices) {
        cout << price << " ";
    }
    cout << endl;

    cout << "Expected: ";
    for (int exp : expected) {
        cout << exp << " ";
    }
    cout << endl;

    cout << "Result: ";
    for (int result : finalPrices(prices)) {
        cout << result << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    test({8, 4, 6, 2, 3}, {4, 2, 4, 2, 3});
    test({1, 2, 3, 4, 5}, {1, 2, 3, 4, 5});
    test({10, 1, 1, 6}, {9, 0, 1, 6});
    test({4, 3, 2, 1}, {1, 1, 1, 1});
    test({5}, {5});
    test({7, 2, 8, 1, 6}, {5, 1, 7, 1, 6});
    test({5, 4}, {1, 4});
    test({5, 6}, {5, 6});

    return 0;
}
