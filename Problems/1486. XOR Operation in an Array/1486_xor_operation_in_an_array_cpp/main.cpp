#include <iostream>

using namespace std;

int xorOperation(int n, int start) {
    int sum = 0;

    for(--n; n > -1; --n) {
        sum ^= start + 2 * n;
    }

    return sum;
}

void runTestCase(int n, int start, int expected) {
    cout << "n: " << n << endl;

    cout << "Start: " << start << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << xorOperation(n, start) << endl;

    cout << endl;
}

int main() {
    runTestCase(5, 0, 8);

    runTestCase(4, 3, 8);

    runTestCase(1, 7, 7);

    runTestCase(10, 5, 2);

    return 0;
}
