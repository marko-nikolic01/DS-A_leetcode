#include <iostream>

using namespace std;

int generateKey(int num1, int num2, int num3) {
    short key = 0;
    short powerOf10 = 1;

    while(num1 > 0 && num2 > 0 && num3 > 0) {
        key += powerOf10 * min(num1 % 10, min(num2 % 10, num3 % 10));
        num1 /= 10;
        num2 /= 10;
        num3 /= 10;
        powerOf10 *= 10;
    }

    return key;
}

void test(int num1, int num2, int num3, int expected) {
    cout << "Number 1: " << num1 << endl;

    cout << "Number 2: " << num2 << endl;

    cout << "Number 3: " << num3 << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << generateKey(num1, num2, num3) << endl;

    cout << endl;
}

int main() {
    test(1, 10, 1000, 0);
    test(987, 879, 798, 777);
    test(1, 2, 3, 1);
    test(4567, 7654, 1111, 1111);
    test(9000, 800, 70, 0);

    return 0;
}
