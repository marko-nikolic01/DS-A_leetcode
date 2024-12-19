#include <iostream>

using namespace std;

int numWaterBottles(int numBottles, int numExchange) {
    return numBottles-- + numBottles / --numExchange;
}

void test(int numBottles, int numExchange, int expected) {
    cout << "Bottles: " << numBottles << endl;

    cout << "Exchange: " << numExchange << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numWaterBottles(numBottles, numExchange) << endl;

    cout << endl;
}

int main() {
    test(9, 3, 13);
    test(15, 4, 19);
    test(5, 6, 5);
    test(5, 5, 6);
    test(10, 2, 19);
    test(17, 4, 22);
    test(1, 2, 1);

    return 0;
}
