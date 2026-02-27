#include <iostream>

using namespace std;

int concatenatedBinary(int n) {
    long concatenation = 0;
    int bits = 0;

    for(int i = 1; i <= n; ++i){
        if((i & (i - 1)) < 1) {
            ++bits;
        }

        concatenation = ((concatenation << bits) | i) % 1000000007;
    }

    return concatenation;
}

void test(int n, int expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << concatenatedBinary(n) << endl;

    cout << endl;
}

int main() {
    test(1, 1);
    test(3, 27);
    test(12, 505379714);
    test(5, 1765);
    test(100, 310828084);

    return 0;
}
