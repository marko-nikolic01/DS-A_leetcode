#include <iostream>
#include <climits>

using namespace std;

int divide(int dividend, int divisor) {
    if(dividend == divisor){
        return 1;
    }

    bool isDividendNegative = dividend < 0;
    bool isDivisorNegative = divisor < 0;

    unsigned int d1 = abs(dividend);
    unsigned int d2 = abs(divisor);

    unsigned int quotient = 0;

    while(d1 >= d2) {
        int powerOf2 = 0;
        while(d1 > d2 << (powerOf2 + 1)) {
            powerOf2 ++;
        }

        quotient += 1 << powerOf2;
        d1 -= d2 << powerOf2;
    }

    if(isDividendNegative == isDivisorNegative && quotient >= INT_MAX) {
        return INT_MAX;
    }

    return isDividendNegative == isDivisorNegative ? quotient : -quotient;
}

void runTest(int dividend, int divisor, int expected) {
    cout << "Dividend: " << dividend << endl;

    cout << "Divisor: " << divisor <<endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << divide(dividend, divisor) << endl;

    cout << endl;
}

int main() {
    runTest(10, 3, 3);
    runTest(7, -3, -2);
    runTest(-7, 3, -2);
    runTest(1, 1, 1);
    runTest(INT_MAX, 1, INT_MAX);
    runTest(INT_MIN, -1, INT_MAX);
    runTest(INT_MIN, 1, INT_MIN);

    return 0;
}
