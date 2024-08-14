#include <iostream>

using namespace std;

bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
}

void printTestCase(int n, bool expected) {
    bool result = isPowerOfTwo(n);

    cout << "Test case: " << n << endl;
    cout << "Expected: " << (expected ? "true" : "false") << endl;
    cout << "Result: " << (result ? "true" : "false") << endl << endl;
}

int main() {
    printTestCase(1, true);
    printTestCase(2, true);
    printTestCase(3, false);
    printTestCase(4, true);
    printTestCase(5, false);
    printTestCase(16, true);
    printTestCase(31, false);
    printTestCase(64, true);
    printTestCase(0, false);
    printTestCase(-16, false);

    return 0;
}
