#include <iostream>

using namespace std;

long long countCommas(long long n) {
    long commas = 0;

    for(long powerOf1000 = 1000; powerOf1000 <= n; ++powerOf1000 *= 1000) {
        commas += n - --powerOf1000;
    }

    return commas;
}

void test(long long n, long long expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countCommas(n) << endl;

    cout << endl;
}

int main() {
    test(1002, 3);
    test(998, 0);
    test(999, 0);
    test(1000, 1);
    test(1002, 3);
    test(999999, 999000);
    test(1000000, 999002);
    test(1, 0);
    test(1000000000000000, 3998998998999005);
}
