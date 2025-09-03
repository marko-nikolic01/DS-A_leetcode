#include <iostream>
#include <vector>

using namespace std;

int getLeastFrequentDigit(int n) {
    vector<short> digits(10, 0);
    short digit;

    while(n > 0) {
        ++digits[n % 10];
        n /= 10;
    }

    for(n = 0; n < 10; ++n) {
        if(digits[n] > 0) {
            digit = n;
            break;
        }
    }

    for(n = 0; n < 10; ++n) {
        if(digits[n] > 0 && digits[n] < digits[digit]) {
            digit = n;
        }
    }

    return digit;
}

void test(int n, int expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << getLeastFrequentDigit(n) << endl;

    cout << endl;
}

int main() {
    test(1553322, 1);
    test(723344511, 2);
    test(19, 1);
    test(7, 7);
    test(9876543210, 0);
    test(111, 1);

    return 0;
}
