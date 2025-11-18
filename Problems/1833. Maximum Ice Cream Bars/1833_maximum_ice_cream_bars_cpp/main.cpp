#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxIceCream(vector<int>& costs, int coins) {
    sort(costs.begin(), costs.end());

    int i;
    int n = costs.size();
    for(i = 0; i < n; ++i) {
        if(costs[i] > coins) {
            break;
        }

        coins -= costs[i];
    }

    return i;
}

void printArray(vector<int> array) {
    for (int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> costs, int coins, int expected) {
    cout << "Costs: ";
    printArray(costs);

    cout << "Coins: " << coins << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxIceCream(costs, coins) << endl;

    cout << endl;
}

int main() {
    test({1, 3, 2, 4, 1}, 7, 4);
    test({10, 6, 8, 7, 7, 8}, 5, 0);
    test({1, 6, 3, 1, 2, 5}, 20, 6);
    test({5, 5, 5, 5, 5}, 10, 2);
    test({2, 1, 2, 1, 2, 1}, 3, 3);

    return 0;
}
