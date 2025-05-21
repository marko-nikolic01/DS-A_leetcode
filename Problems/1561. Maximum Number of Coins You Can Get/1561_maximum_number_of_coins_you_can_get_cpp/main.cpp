#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxCoins(vector<int>& piles) {
    sort(piles.begin(), piles.end());

    int coins = 0;
    int me = piles.size();

    for(int i = me / 3; i > 0; --i) {
        me -= 2;
        coins += piles[me];
    }

    return coins;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> piles, int expected) {
    cout << "Piles: ";
    printArray(piles);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxCoins(piles) << endl;

    cout << endl;
}

int main() {
    test({2, 4, 1, 2, 7, 8}, 9);
    test({2, 4, 5}, 4);
    test({9, 8, 7, 6, 5, 1, 2, 3, 4}, 18);
    test({1, 1, 1, 1, 1, 1}, 2);
    test({10000, 1, 10000, 1, 10000, 1}, 10001);

    return 0;
}
