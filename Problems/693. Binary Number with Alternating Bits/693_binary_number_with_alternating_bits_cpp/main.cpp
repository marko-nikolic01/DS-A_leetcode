#include <iostream>

using namespace std;

bool hasAlternatingBits(int n) {
    bool isZero = n % 2 == 0;
    n >>= 1;


    while(n > 0) {
        if(isZero == (n % 2 == 0)) {
            return false;
        }
        n >>= 1;
        isZero = !isZero;
    }

    return true;
}

void runTest(int n, bool expected) {
    bool result = hasAlternatingBits(n);
    cout << "n = " << n << endl;
    cout << "Expected: " << (expected ? "true" : "false") << endl;
    cout << "Result: " << (result ? "true" : "false") << endl;
    cout << endl;
}

int main() {
    runTest(5, true);
    runTest(7, false);
    runTest(10, true);
    runTest(11, false);
    runTest(1, true);
    runTest(0, true);

    return 0;
}
