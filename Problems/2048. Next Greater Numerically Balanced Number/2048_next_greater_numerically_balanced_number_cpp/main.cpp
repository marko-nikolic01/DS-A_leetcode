#include <iostream>
#include <vector>

using namespace std;

bool nextBeautifulNumber(int n, vector<short>& digits) {
    short digit;
    for(digit = 0; digit < 10; ++digit) {
        digits[digit] = 0;
    }

    while(n > 0) {
        ++digits[n % 10];
        n /= 10;
    }

    for(digit = 0; digit < 10; ++digit) {
        if(digits[digit] > 0 && digits[digit] != digit) {
            return false;
        }
    }

    return true;
}

int nextBeautifulNumber(int n) {
    vector<short> digits(10, 0);

    while(true) {
        if(nextBeautifulNumber(++n, digits)) {
            break;
        }
    }

    return n;
}

void test(int n, int expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << nextBeautifulNumber(n) << endl;

    cout << endl;
}


int main() {
    test(1, 22);
    test(1000, 1333);
    test(3000, 3133);
    test(20, 22);
    test(120, 122);

    return 0;
}
