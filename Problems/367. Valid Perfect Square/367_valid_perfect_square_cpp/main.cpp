#include <iostream>

using namespace std;

bool isPerfectSquare(int num) {
    int a = 0;
    int b = num;

    while(a <= b) {
        int c = (a + b) / 2;

        long square = (long)c * c;
        if(square == num) {
            return true;
        } else if(square < num) {
            a = ++c;
        } else {
            b = --c;
        }
    }

    return false;
}

void testIsPerfectSquare(int num, bool expected) {
    bool result = isPerfectSquare(num);
    cout << "Number: " << num << endl;
    cout << "Expected: " << (expected ? "true" : "false") << endl;
    cout << "Result: " << (result ? "true" : "false") << endl;
    cout << endl;
}

int main() {
    testIsPerfectSquare(16, true);
    testIsPerfectSquare(14, false);
    testIsPerfectSquare(25, true);
    testIsPerfectSquare(1, true);
    testIsPerfectSquare(0, true);
    testIsPerfectSquare(100000000, true);
    testIsPerfectSquare(1000000000, false);

    return 0;
}
