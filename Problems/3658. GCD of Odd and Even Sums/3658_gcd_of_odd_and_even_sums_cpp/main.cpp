#include <iostream>

using namespace std;

int gcdOfOddEvenSums(int n) {
    return n;
}

void test(int n, int expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << gcdOfOddEvenSums(n) << endl;

    cout << endl;
}

int main() {
    test(4, 4);
    test(5, 5);
    test(1, 1);
    test(2, 2);
    test(3, 3);
    test(10, 10);
    test(100, 100);
    test(500, 500);
    test(999, 999);
    test(1000, 1000);

    return 0;
}
