#include <iostream>

using namespace std;

int maxProduct(int n) {
    short digit1 = 0;
    short digit2 = 0;
    short digit;

    while(n > 0) {
        digit = n % 10;
        n /= 10;

        if(digit > digit1) {
            digit2 = digit1;
            digit1 = digit;
        } else if(digit > digit2) {
            digit2 = digit;
        }
    }

    return digit1 * digit2;
}

void test(int n, int expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxProduct(n) << endl;

    cout << endl;
}

int main() {
    test(31, 3);
    test(22, 4);
    test(124, 8);
    test(987, 72);
    test(505, 25);
    return 0;
}
