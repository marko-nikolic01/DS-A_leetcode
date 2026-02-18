#include <iostream>

using namespace std;

bool hasAlternatingBits(int n) {
    bool isZero = (n & 1) < 1;
    n >>= 1;

    while(n > 0) {
        if(isZero == (n % 2 == 0)) {
            return false;
        }

        n >>= 1;
        isZero = !isZero;
    }

    return true;
}

void test(int n, bool expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (hasAlternatingBits(n) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test(5, true);
    test(7, false);
    test(10, true);
    test(11, false);
    test(1, true);
    test(0, true);

    return 0;
}
