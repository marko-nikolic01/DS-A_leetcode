#include <iostream>

using namespace std;

bool isStrictlyPalindromic(int n) {
    return false;
}

void test(int n, bool expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (isStrictlyPalindromic(n) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test(9, false);
    test(4, false);
    test(5, false);
    test(7, false);
    test(100, false);
    test(100000, false);

    return 0;
}
