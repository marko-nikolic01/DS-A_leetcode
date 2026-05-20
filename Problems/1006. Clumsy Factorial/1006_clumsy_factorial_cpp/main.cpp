#include <iostream>

using namespace std;

int clumsy(int factorial, short n, short operation, int operand) {
    if(--n < 1) {
        return factorial + operand;
    } else if(operation < 1) {
        operand *= n;
    } else if(operation < 2) {
        operand /= n;
    } else if(operation < 3) {
        operand += n;
    } else {
        factorial += operand;
        operand = -n;
    }

    return clumsy(factorial, n, ++operation % 4, operand);
}

int clumsy(int n) {
    return clumsy(0, n, 0, n);
}

void test(int n, int expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << clumsy(n) << endl;

    cout << endl;
}

int main() {
    test(4, 7);
    test(10, 12);
    test(1, 1);
    test(2, 2);
    test(3, 6);
    test(10000, 10001);

    return 0;
}
