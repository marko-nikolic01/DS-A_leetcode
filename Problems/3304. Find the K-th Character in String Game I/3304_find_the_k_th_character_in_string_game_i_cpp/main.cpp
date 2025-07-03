#include <iostream>

using namespace std;

char kthCharacter(int k) {
    short character = 0;

    short powerOf2 = 1;
    while(powerOf2 < k) {
        powerOf2 <<= 1;
    }
    powerOf2 >>= 1;

    while(k > 1) {
        ++character;

        while(powerOf2 >= k) {
            powerOf2 >>= 1;
        }

        k -= powerOf2;
        powerOf2 >>= 1;
    }

    return 'a' + character;
}

void test(int k, char expected) {
    cout << "k: " << k << endl;

    cout << "Expected: " << "'" << expected << "'" << endl;

    cout << "Result: " << "'" << kthCharacter(k) << "'" << endl;

    cout << endl;
}

int main() {
    test(1, 'a');
    test(5, 'b');
    test(10, 'c');
    test(12, 'd');
    test(20, 'd');

    return 0;
}
