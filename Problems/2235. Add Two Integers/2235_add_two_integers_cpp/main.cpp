#include <iostream>

using namespace std;

int sum(int num1, int num2) {
    return num1 + num2;
}

void printTestCase(int num1, int num2, int expected) {
    cout << "Number 1: " << num1 << endl;

    cout << "Number 2: " << num2 << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << sum(num1, num2) << endl;

    cout << endl;
}

int main() {
    printTestCase(2, 3, 5);
    printTestCase(-1, 1, 0);
    printTestCase(0, 0, 0);
    printTestCase(100, 200, 300);
    printTestCase(-50, 50, 0);
    printTestCase(123, 456, 579);
    printTestCase(69, 69, 138);

    return 0;
}
