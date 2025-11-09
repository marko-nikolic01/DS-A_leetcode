#include <iostream>

using namespace std;

int countOperations(int num1, int num2) {
    int operations = 0;

    while(num1 > 0 && num2 > 0) {
        if(num1 < num2) {
            num2 -= num1;
        } else {
            num1 -= num2;
        }

        ++operations;
    }

    return operations;
}

void test(int num1, int num2, int expected) {
    cout << "Number 1: " << num1 << endl;

    cout << "Number 2: " << num2 << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countOperations(num1, num2) << endl;

    cout << endl;
}

int main() {
    test(2, 3, 3);
    test(10, 10, 1);
    test(5, 4, 5);
    test(0, 7, 0);
    test(12, 4, 3);

    return 0;
}
