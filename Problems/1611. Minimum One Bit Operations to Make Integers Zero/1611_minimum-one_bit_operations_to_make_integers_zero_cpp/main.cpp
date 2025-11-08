#include <iostream>

using namespace std;

int minimumOneBitOperations(int n) {
    int operations = 0;
    int k = 0;
    int mask = 1;

    while(mask <= n) {
        if((n & mask) != 0) {
            operations = (1 << (k + 1)) - 1 - operations;
        }

        ++k;
        mask <<= 1;
    }

    return operations;
}

void test(int n, int expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minimumOneBitOperations(n) << endl;

    cout << endl;
}

int main() {
    test(3, 2);
    test(6, 4);
    test(9, 14);
    test(0, 0);
    test(15, 10);

    return 0;
}
