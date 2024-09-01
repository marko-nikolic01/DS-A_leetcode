#include <iostream>

using namespace std;

double myPow(double x, int n) {
    if (n == 0 || x == 1) {
        return 1;
    }

    long longN = n;
    if (longN < 0) {
        x = 1 / x;
        longN = -longN;
    }

    double pow = 1;
    double currentPow = x;

    while (longN > 0) {
        if (longN % 2 == 1) {
            pow *= currentPow;
        }
        currentPow *= currentPow;
        longN /= 2;
    }

    return pow;
}

void runTest(double x, int n, double expected) {
    cout << "x: " << x << endl;

    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << myPow(x, n) << endl;

    cout << endl;
}

int main() {
    runTest(2.0, 10, 1024.0);
    runTest(2.1, 3, 9.261);
    runTest(2.0, -2, 0.25);
    runTest(-2.0, 3, -8.0);
    runTest(1.0, 1000, 1.0);
    runTest(2.0, 0, 1.0);
    runTest(0.5, -2, 4.0);

    return 0;
}
