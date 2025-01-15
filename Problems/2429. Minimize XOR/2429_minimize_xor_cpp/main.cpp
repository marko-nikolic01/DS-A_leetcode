#include <iostream>

using namespace std;

int minimizeXor(int num1, int num2) {
    short ones = 0;
    while(num2 > 0) {
        if((num2 & 1) > 0) {
            ++ones;
        }
        num2 >>= 1;
    }

    short shift = 31;
    while(shift > -1 && ones > 0) {
        if((num1 & (1 << shift)) > 0) {
            num2 |= 1 << shift;
            --ones;
        }
        --shift;
    }

    shift = 0;
    while(ones > 0) {
        if((num1 & (1 << shift)) < 1) {
            num2 |= 1 << shift;
            --ones;
        }
        ++shift;
    }

    return num2;
}

void runTest(int num1, int num2, int expected) {
    cout << "Number 1: " << num1 << endl;

    cout << "Number 2: " << num2 << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minimizeXor(num1, num2) << endl;

    cout << endl;
}

int main() {
    runTest(3, 5, 3);
    runTest(1, 12, 3);
    runTest(7, 15, 15);
    runTest(10, 4, 8);
    runTest(17, 7, 19);
    runTest(28, 19, 28);
    runTest(0, 1, 1);

    return 0;
}
