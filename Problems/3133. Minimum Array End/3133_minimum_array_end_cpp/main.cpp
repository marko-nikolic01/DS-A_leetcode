#include <iostream>

using namespace std;

long long minEnd(int n, int x) {
    long num = x;
    long bit = 1;

    --n;
    while(n > 0) {
        if((x & bit) == 0) {
            if((n & 1) == 1) {
                num |= bit;
            }
            n >>= 1;
        }
        bit <<= 1;
    }

    return num;
}

void test(int n, int x, long long expected) {
    cout << "n: " << n << endl;

    cout << "x: " << x << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minEnd(n, x) << endl;

    cout << endl;
}

int main() {
    test(5, 3, 19);
    test(4, 10, 15);
    test(3, 6, 14);
    test(2, 5, 7);
    test(6, 1, 11);
    test(100, 0, 99);

    return 0;
}
