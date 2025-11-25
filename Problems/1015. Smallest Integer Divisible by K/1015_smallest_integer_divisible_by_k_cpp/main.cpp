#include <iostream>

using namespace std;

int smallestRepunitDivByK(int k) {
    if((k & 1) < 1  || k % 5 < 1) {
        return -1;
    } else if(k < 2) {
        return 1;
    }

    int remainder = 1;
    int digits = 1;

    while(remainder > 0) {
        remainder = (10 * remainder + 1) % k;
        ++digits;
    }

    return digits;
}

void test(int k, int expected) {
    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << smallestRepunitDivByK(k) << endl;

    cout << endl;
}

int main() {
    test(1, 1);
    test(2, -1);
    test(3, 3);
    test(7, 6);
    test(11, 2);
    test(100000, -1);

    return 0;
}
