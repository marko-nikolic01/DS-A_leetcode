#include <iostream>

using namespace std;

int minMaxDifference(int num) {
    int numCopy = num;

    int powerOf10 = 1;
    while(powerOf10 <= num) {
        powerOf10 *= 10;
    }
    powerOf10 /= 10;
    int powerOf10Copy = powerOf10;

    int difference = 0;
    short digit = num / powerOf10;
    while(num > 0) {
        if(num / powerOf10 != digit) {
            difference -= num - num % powerOf10;
        }

        num %= powerOf10;
        powerOf10 /= 10;
    }

    while(powerOf10Copy > 0) {
        if(numCopy / powerOf10Copy < 9) {
            digit = numCopy / powerOf10Copy;
            break;
        } else {
            difference += 9 * powerOf10Copy;
        }

        numCopy %= powerOf10Copy;
        powerOf10Copy /= 10;
    }
    while(powerOf10Copy > 0) {
        if(numCopy / powerOf10Copy != digit) {
            difference += numCopy - numCopy % powerOf10Copy;
        } else {
            difference += 9 * powerOf10Copy;
        }

        numCopy %= powerOf10Copy;
        powerOf10Copy /= 10;
    }

    return difference;
}

void test(int num, int expected) {
    cout << "Number: " << num << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minMaxDifference(num) << endl;

    cout << endl;
}

int main() {
    test(11891, 99009);
    test(90, 99);
    test(100000000, 900000000);
    test(123456, 900000);
    test(99999999, 99999999);

    return 0;
}
