#include <iostream>

using namespace std;

int rotatedDigits(int n) {
    short goodIntegers = 0;
    short digit;
    bool isGood;
    bool isDifferent;

    for(short i = n; i > 1; --i) {
        isGood = true;
        isDifferent = false;

        n = i;
        while(n > 0) {
            digit = n % 10;
            n /= 10;

            if(digit == 3 || digit == 4 || digit == 7) {
                isGood = false;

                break;
            } else if(digit == 2 || digit == 5 || digit == 6 || digit == 9) {
                isDifferent = true;
            }
        }

        if(isGood && isDifferent) {
            ++goodIntegers;
        }
    }

    return goodIntegers;
}

void test(int n, int expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << rotatedDigits(n) << endl;

    cout << endl;
}

int main() {
    test(10, 4);
    test(1, 0);
    test(2, 1);
    test(100, 40);
    test(10000, 2320);

    return 0;
}
