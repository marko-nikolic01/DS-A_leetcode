#include <iostream>

using namespace std;

bool checkDivisibility(int n) {
    int number = n;
    short digitSum = 0;
    int digitProduct = 1;
    short digit;

    while(number > 0) {
        digit = number % 10;
        number /= 10;
        digitSum += digit;
        digitProduct *= digit;
    }

    return n % (digitSum + digitProduct) < 1;
}

void test(int n, bool expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (checkDivisibility(n) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test(99, true);
    test(23, false);
    test(1, false);
    test(36, false);
    test(121, false);

    return 0;
}
