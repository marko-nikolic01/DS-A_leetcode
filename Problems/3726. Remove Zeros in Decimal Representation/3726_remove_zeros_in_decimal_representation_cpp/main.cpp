#include <iostream>

using namespace std;

long long removeZeros(long long n) {
    long number = 0;
    long powerOf10 = 1;
    short digit;

    while(n > 0) {
        digit = n % 10;

        if(digit > 0) {
            number += digit * powerOf10;
            powerOf10 *= 10;
        }

        n /= 10;
    }

    return number;
}

void test(long long n, long long expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << removeZeros(n) << endl;

    cout << endl;
}

int main() {
    test(1020030, 123);
    test(1, 1);
    test(1000, 1);
    test(909090, 999);
    test(1002003004005, 12345);

    return 0;
}
