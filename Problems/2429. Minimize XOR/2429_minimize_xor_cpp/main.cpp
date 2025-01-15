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

    while(ones > 0) {
        ++shift;
        if((num1 & (1 << shift)) < 1) {
            num2 |= 1 << shift;
            --ones;
        }
    }

    return num2;
}

void test(int num1, int num2, int expected) {
    cout << "Number 1: " << num1 << endl;

    cout << "Number 2: " << num2 << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minimizeXor(num1, num2) << endl;

    cout << endl;
}

int main() {
    test(3, 5, 3);
    test(1, 12, 3);
    test(7, 15, 15);
    test(10, 4, 8);
    test(17, 7, 19);
    test(28, 19, 28);
    test(0, 1, 1);

    return 0;
}
