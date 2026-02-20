#include <iostream>

using namespace std;

short totalWaviness(int num) {
    short waviness = 0;
    short digit1;
    short digit2;
    short digit3;

    digit2 = num % 10;
    num /= 10;
    digit3 = num % 10;
    num /= 10;

    while(num > 0) {
        digit1 = digit2;
        digit2 = digit3;
        digit3 = num % 10;
        num /= 10;

        if((digit1 < digit2 && digit3 < digit2) || (digit1 > digit2 && digit3 > digit2)) {
            ++waviness;
        }
    }

    return waviness;
}

int totalWaviness(int num1, int num2) {
    int waviness = 0;

    if(--num1 < 100) {
        num1 = 100;
    }

    while(++num1 <= num2) {
        waviness += totalWaviness(num1);
    }

    return waviness;
}

void test(int num1, int num2, int expected) {
    cout << "Number 1: " << num1 << endl;

    cout << "Number 2: " << num2 << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << totalWaviness(num1, num2) << endl;

    cout << endl;
}

int main() {
    test(120, 130, 3);
    test(198, 202, 3);
    test(4848, 4848, 2);
    test(100, 105, 5);
    test(121, 131, 3);

    return 0;
}
