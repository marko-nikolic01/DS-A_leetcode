#include <iostream>

using namespace std;

bool validDigit(int n, int x) {
    bool isValid = false;

    while(n > 9) {
        if(n % 10 == x) {
            isValid = true;
        }

        n /= 10;
    }

    return isValid && n != x;
}

void test(int n, int x, bool expected) {
    cout << "n: " << n << endl;

    cout << "x: " << x << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (validDigit(n, x) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test(101, 0, true);
    test(232, 2, false);
    test(5, 1, false);
    test(200, 2, false);
    test(212, 2, false);
    test(911, 1, true);

    return 0;
}
