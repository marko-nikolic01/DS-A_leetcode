#include <iostream>

using namespace std;

int addDigits(int num) {
    int next = 0;

    while(num > 0) {
        next += num % 10;
        num /= 10;
    }

    return next < 10 ? next : addDigits(next);
}

void runTestCase(int num, int expected) {
    int result = addDigits(num);
    cout << "Number: " << num << endl;
    cout << "Expected: " << expected << endl;
    cout << "Result: " << result << endl;
    cout << (result == expected ? "Pass" : "Fail") << endl << endl;
}

int main() {
    runTestCase(38, 2);
    runTestCase(0, 0);
    runTestCase(12345, 6);
    runTestCase(9999, 9);

    return 0;
}
