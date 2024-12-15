#include <iostream>

using namespace std;

int smallestNumber(int n) {
    int number = 1;

    while(number < n) {
        number <<= 1;
        ++number;
    }

    return number;
}

void test(int n, int expected) {
    cout << "n = " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << smallestNumber(n) << endl;

    cout << endl;
}

int main() {
    test(1, 1);
    test(2, 3);
    test(5, 7);
    test(10, 15);
    test(20, 31);
    test(100, 127);

    return 0;
}
