#include <iostream>

using namespace std;

bool checkGoodInteger(int n) {
    short sum = 0;
    short digit;

    while(n > 0) {
        digit = n % 10;
        n /= 10;
        sum += digit * digit - digit;
    }

    return sum > 49;
}

void test(int n, bool expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (checkGoodInteger(n) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test(1000, false);
    test(19, true);
    test(99, true);
    test(123, false);
    test(79, true);

    return 0;
}
