#include <iostream>

using namespace std;

int makeTheIntegerZero(int num1, int num2) {
    int k = 1;
    long x;

    while(true) {
        x = num1 - static_cast<long long>(num2) * ++k;

        if(x < k) {
            return -1;
        }

        if(k >= __builtin_popcountll(x)) {
            return k;
        }
    }
}

void test(int num1, int num2, int expected) {
    cout << "Number 1: " << num1 << endl;

    cout << "Number 2: " << num2 << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << makeTheIntegerZero(num1, num2) << endl;


    cout << endl;
}


int main() {
    test(3, -2, 3);
    test(5, 7, -1);
    test(10, 3, 2);
    test(25, 2, 3);
    test(1, -1, 2);

    return 0;
}
