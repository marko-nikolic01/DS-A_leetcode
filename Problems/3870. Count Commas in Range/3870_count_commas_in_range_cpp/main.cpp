#include <iostream>

using namespace std;

int countCommas(int n) {
    return n > 999 ? n - 999 : 0;
}

void test(int n, int expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countCommas(n) << endl;

    cout << endl;
}

int main() {
    test(998,   0);
    test(1002,  3);
    test(1000,  1);
    test(9999,  9000);
    test(100000, 99001);
    test(1, 0);

    return 0;
}
