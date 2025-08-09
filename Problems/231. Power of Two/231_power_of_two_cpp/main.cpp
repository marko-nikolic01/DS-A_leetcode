#include <iostream>

using namespace std;

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) < 1;
}

void test(int n, bool expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (isPowerOfTwo(n) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test(1, true);
    test(2, true);
    test(3, false);
    test(4, true);
    test(5, false);
    test(16, true);
    test(31, false);
    test(64, true);
    test(0, false);
    test(-16, false);

    return 0;
}
