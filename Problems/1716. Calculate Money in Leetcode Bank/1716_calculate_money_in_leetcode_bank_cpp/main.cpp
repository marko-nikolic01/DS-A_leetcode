#include <iostream>

using namespace std;

int totalMoney(int n) {
    short remainingDays = n % 7;
    short weeks = n / 7;

    return weeks * 21 + 7 * ((weeks * (weeks + 1)) >> 1) + remainingDays * (weeks + 1) + ((remainingDays * (remainingDays - 1)) >> 1);
}

void test(int n, int expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << totalMoney(n) << endl;

    cout << endl;
}

int main() {
    test(4, 10);
    test(10, 37);
    test(20, 96);
    test(7, 28);
    test(15, 66);
    test(1, 1);
    test(100, 1060);
    test(1000, 74926);

    return 0;
}
