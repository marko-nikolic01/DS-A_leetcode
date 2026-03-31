#include <iostream>

using namespace std;

int minCost(int n) {
    return n-- * n >> 1;
}

void test(int n, int expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minCost(n) << endl;

    cout << endl;
}

int main() {
    test(3, 3);
    test(4, 6);
    test(1, 0);
    test(2, 1);
    test(5, 10);
    test(10, 45);
    test(50, 1225);
    test(100, 4950);
    test(499, 124251);
    test(500, 124750);

    return 0;
}
