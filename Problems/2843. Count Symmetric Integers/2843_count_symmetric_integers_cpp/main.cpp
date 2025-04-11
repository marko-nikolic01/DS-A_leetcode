#include <iostream>

using namespace std;

int countSymmetricIntegers(int low, int high) {
    short count = 0;
    short current;
    short digitSum;
    short powerOf10;

    if(low < 100) {
        count = min(100, high) / 11 - (low - 1) / 11;
    }

    high = min(9999, high);
    for(low = max(1000, low); low <= high; ++low) {
        current = low;

        digitSum = current / 1000;
        current %= 1000;

        digitSum += current / 100;
        current %= 100;

        digitSum -= current / 10;
        current %= 10;

        digitSum -= current;

        if(digitSum == 0) {
            ++count;
        }
    }

    return count;
}

void test(int low, int high, int expected) {
    cout << "Low: " << low << endl;

    cout << "High: " << high << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countSymmetricIntegers(low, high) << endl;

    cout << endl;
}

int main() {
    test(1, 100, 9);
    test(1200, 1230, 4);
    test(10, 10, 0);
    test(1000, 1009, 1);
    test(1, 10000, 624);

    return 0;
}
