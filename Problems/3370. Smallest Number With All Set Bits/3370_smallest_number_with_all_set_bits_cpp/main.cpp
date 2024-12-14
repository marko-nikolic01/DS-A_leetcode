#include <iostream>

using namespace std;

int smallestNumber(int n) {
    int number = 1;

    while(number < n) {
        number <<= 1;
        ++number;
    }

    return number;
}

void printTestCase(int n, int expected) {
    cout << "n = " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << smallestNumber(n) << endl;

    cout << endl;
}

int main() {
    printTestCase(1, 1);
    printTestCase(2, 3);
    printTestCase(5, 7);
    printTestCase(10, 15);
    printTestCase(20, 31);
    printTestCase(100, 127);

    return 0;
}
