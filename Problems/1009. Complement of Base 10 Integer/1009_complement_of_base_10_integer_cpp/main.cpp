#include <iostream>

using namespace std;

int bitwiseComplement(int n) {
    if(n < 1) {
        return 1;
    }

    int complement = 0;

    for(short i = 0; n > 0; n >>= 1) {
        complement |= ((n & 1) ^ 1) << i++;
    }

    return complement;
}

void test(int n, int expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << bitwiseComplement(n) << endl;

    cout << endl;
}

int main() {
    test(5, 2);
    test(7, 0);
    test(10, 5);
    test(0, 1);
    test(1, 0);

    return 0;
}
