#include <iostream>

using namespace std;

int minFlips(int a, int b, int c) {
    short flips = 0;

    while(a > 0 || b > 0 || c > 0) {
        if((c & 1) < 1) {
            if((a & 1) > 0) {
                ++flips;
            }

            if((b & 1) > 0) {
                ++flips;
            }
        } else if((a & 1) < 1 && (b & 1) < 1) {
            ++flips;
        }

        a >>= 1;
        b >>= 1;
        c >>= 1;
    }

    return flips;
}

void test(int a, int b, int c, int expected) {
    cout << "a: " << a << endl;

    cout << "b: " << b << endl;

    cout << "c: " << c << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minFlips(a, b, c) << endl;

    cout << endl;
}

int main() {
    test(2, 6, 5, 3);
    test(4, 2, 7, 1);
    test(1, 2, 3, 0);
    test(1, 1, 1, 0);
    test(8, 3, 5, 3);

    return 0;
}
