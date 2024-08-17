#include <iostream>

using namespace std;

int arrangeCoins(int n) {
    int rows = 0;

    while(n > rows) {
        rows++;
        n -= rows;
    }

    return rows;
}

void testArrangeCoins(int n, int expected) {
    int result = arrangeCoins(n);
    cout << "Coins: " << n << ", Expected: " << expected << ", Result: " << result << endl << endl;
}

int main() {
    testArrangeCoins(5, 2);
    testArrangeCoins(8, 3);
    testArrangeCoins(10, 4);
    testArrangeCoins(1, 1);
    testArrangeCoins(0, 0);
    testArrangeCoins(15, 5);

    return 0;
}
