#include <iostream>
#include <vector>

using namespace std;

long long getDescentPeriods(vector<int>& prices) {
    long periods = 1;
    int period = 1;

    for(int i = prices.size() - 2; i > -1; --i) {
        if(prices[i] - 1 == prices[i + 1]) {
            ++period;
        } else {
            period = 1;
        }

        periods += period;
    }

    return periods;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> prices, long long expected) {
    cout << "Prices: ";
    printArray(prices);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << getDescentPeriods(prices) << endl;

    cout << endl;
}

int main() {
    test({3, 2, 1, 4}, 7);
    test({8, 6, 7, 7}, 4);
    test({1}, 1);
    test({5, 4, 3, 2, 1}, 15);
    test({10, 9, 8, 10, 9}, 9);

    return 0;
}
