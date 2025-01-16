#include <iostream>

using namespace std;

int minChanges(int n, int k) {
    short changes = 0;

    while(n > 0) {
        if((n & 1) > 0) {
            if((k & 1) < 1) {
                ++changes;
            }
        } else if((k & 1) > 0) {
            return -1;
        }

        n >>= 1;
        k >>= 1;
    }

    return k > 0 ? -1 : changes;
}

void test(int n, int k, int expected) {
    cout << "n: " << n << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minChanges(n, k) << endl;

    cout << endl;
}

int main() {
    test(13, 4, 2);
    test(21, 21, 0);
    test(14, 13, -1);
    test(8, 4, -1);
    test(31, 7, 2);
    test(10, 1, -1);

    return 0;
}
