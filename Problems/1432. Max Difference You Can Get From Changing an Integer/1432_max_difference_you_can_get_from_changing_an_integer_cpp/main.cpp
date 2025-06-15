#include <iostream>

using namespace std;

int maxDiff(int num, int powerOf10, short digit, short replacementDigit) {
    int replacedNumber = num;

    while(powerOf10 > 0) {
        if(num / powerOf10 == digit) {
            replacedNumber += (replacementDigit - num / powerOf10) * powerOf10;
        }

        num %= powerOf10;
        powerOf10 /= 10;
    }

    return replacedNumber;
}

int maxDiff(int num) {
    int difference = -num + 9;
    short replacementDigit;
    int numCopy = num;

    int powerOf10 = 1;
    while(powerOf10 <= num) {
        powerOf10 *= 10;
    }
    powerOf10 /= 10;
    int powerOf10Copy = powerOf10;

    short firstDigit = num / powerOf10;

    if(firstDigit < 2) {
        while(powerOf10Copy > 0) {
            if(numCopy / powerOf10Copy > 1) {
                difference = -maxDiff(num, powerOf10, numCopy / powerOf10Copy, 0) + 9;
                break;
            }

            numCopy %= powerOf10Copy;
            powerOf10Copy /= 10;
        }
    } else {
        difference = -maxDiff(num, powerOf10, firstDigit, 1) + 9;
    }

    numCopy = num;
    powerOf10Copy = powerOf10;

    if(firstDigit > 8) {
        while(powerOf10Copy > 0) {
            if(numCopy / powerOf10Copy < 9) {
                difference += maxDiff(num, powerOf10, numCopy / powerOf10Copy, 9) - 9;
                break;
            }

            numCopy %= powerOf10Copy;
            powerOf10Copy /= 10;
        }
    } else {
        difference += maxDiff(num, powerOf10, firstDigit, 9) - 9;
    }

    return difference;
}

void test(int num, int expected) {
    cout << "Number: " << num << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxDiff(num) << endl;

    cout << endl;
}

int main() {
    test(555, 888);
    test(9, 8);
    test(123456, 820000);
    test(10000, 80000);
    test(9288, 8700);

    return 0;
}
