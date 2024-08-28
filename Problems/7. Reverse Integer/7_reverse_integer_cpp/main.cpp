#include <iostream>
#include <climits>

using namespace std;

int reverse(int x) {
    long reversed = 0;
    long longX = x;

    bool isNegative = x < 0;
    if(isNegative) {
        longX = -longX;
    }

    while(longX > 0) {
        reversed *= 10;
        reversed += longX % 10;
        longX /= 10;
    }

    if(reversed > INT_MAX) {
        return 0;
    }

    return isNegative ? -reversed : reversed;
}

void testReverse(int input, int expected) {
    cout << "Input: " << input << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << reverse(input) << endl;

    cout << endl;
}

int main() {
    testReverse(123, 321);
    testReverse(-123, -321);
    testReverse(120, 21);
    testReverse(0, 0);
    testReverse(1534236469, 0);

    return 0;
}
