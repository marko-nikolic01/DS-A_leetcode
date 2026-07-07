#include <iostream>

using namespace std;

long long sumAndMultiply(int n) {
    int concatenation = 0;
    short sum = 0;
    short digit;
    long powerOf10 = 1;

    while(n > 0) {
        digit = n % 10;
        n /= 10;

        if(digit > 0) {
            concatenation += powerOf10 * digit;
            sum += digit;
            powerOf10 *= 10;
        }
    }

    return (long)concatenation * sum;
}

void test(int n, long long expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << sumAndMultiply(n) << endl;

    cout << endl;
}

int main() {
    test(10203004, 12340);
    test(1000, 1);
    test(0, 0);
    test(5, 25);
    test(999, 26973);

    return 0;
}
