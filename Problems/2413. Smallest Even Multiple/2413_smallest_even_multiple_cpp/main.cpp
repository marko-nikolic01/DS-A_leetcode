#include <iostream>

using namespace std;

int smallestEvenMultiple(int n) {
    return (n & 1) < 1 ? n : n << 1;
}

void test(int n, int expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << smallestEvenMultiple(n) << endl;

    cout << endl;
}

int main() {
    test(1, 2);
    test(2, 2);
    test(3, 6);
    test(4, 4);
    test(5, 10);
    test(6, 6);
    test(150, 150);

    return 0;
}
