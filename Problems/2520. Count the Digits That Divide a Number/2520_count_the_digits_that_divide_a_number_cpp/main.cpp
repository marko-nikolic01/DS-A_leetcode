#include <iostream>

using namespace std;

int countDigits(int num) {
    short digits = 0;
    int number = num;

    while(num > 0) {
        if(number % (num % 10) < 1) {
            ++digits;
        }

        num /= 10;
    }

    return digits;
}

void test(int num, int expected) {
    cout << "Number: " << num << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countDigits(num) << endl;

    cout << endl;
}

int main() {
    test(7, 1);
    test(121, 2);
    test(1248, 4);
    test(1, 1);
    test(999999999, 9);

    return 0;
}
