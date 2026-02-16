#include <iostream>
#include <cstdint>

using namespace std;

int reverseBits(int n) {
    int reversed = 0;

    for(short i = 0; i < 32; ++i) {
        reversed <<= 1;
        reversed |= n & 1;
        n >>= 1;
    }

    return reversed;
}

void test(int n, int expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << reverseBits(n) << endl;

    cout << endl;
}

int main() {
    test(43261596, 964176192);
    test(2147483644, 1073741822);
    test(0, 0);
    test(2, 1073741824);
    test(8, 268435456);

    return 0;
}
