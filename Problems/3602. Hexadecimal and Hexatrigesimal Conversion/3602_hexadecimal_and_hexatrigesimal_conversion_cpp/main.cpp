#include <iostream>

using namespace std;

void concatHex36(int n, string& representation, short base) {
    long power = 1;
    int digit;

    while(power <= n) {
        power *= base;
    }
    power /= base;

    while(power > 0) {
        digit = n / power;
        n %= power;
        power /= base;
        representation.push_back((digit < 10 ? '0' : '7') + digit);
    }
}

string concatHex36(int n) {
    string hex16Hex36 = "";

    concatHex36(n * n, hex16Hex36, 16);
    concatHex36(n * n * n, hex16Hex36, 36);

    return hex16Hex36;
}

void test(int n, string expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << concatHex36(n) << endl;

    cout << endl;
}

int main() {
    test(13, "A91P1");
    test(36, "5101000");
    test(393, "25B51104Z89");
    test(1, "11");
    test(1000, "F4240GJDGXS");

    return 0;
}
