#include <iostream>

using namespace std;

int checkRecord(int n) {
    int a0l0 = 1;
    int a0l1 = 0;
    int a0l2 = 0;
    int a1l0 = 0;
    int a1l1 = 0;
    int a1l2 = 0;

    int a0l0Temp;
    int a0l1Temp;
    int a0l2Temp;
    int a1l0Temp;
    int a1l1Temp;
    int a1l2Temp;

    for(n; n > 0; --n) {
        a0l0Temp = a0l0;
        a0l1Temp = a0l1;
        a0l2Temp = a0l2;
        a1l0Temp = a1l0;
        a1l1Temp = a1l1;
        a1l2Temp = a1l2;

        a0l0 = ((a0l0Temp + a0l1Temp) % 1000000007 + a0l2Temp) % 1000000007;
        a0l1 = a0l0Temp;
        a0l2 = a0l1Temp;
        a1l0 = (((((a1l0Temp + a0l0Temp) % 1000000007 + a0l1Temp) % 1000000007 + a0l2Temp) % 1000000007 + a1l1Temp) % 1000000007 + a1l2Temp) % 1000000007;
        a1l1 = a1l0Temp;
        a1l2 = a1l1Temp;
    }

    return (((((a0l0 + a0l1) % 1000000007 + a0l2) % 1000000007 + a1l0) % 1000000007 + a1l1) % 1000000007 + a1l2) % 1000000007;
}

void test(int n, int expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << checkRecord(n) << endl;

    cout << endl;
}

int main() {
    test(1, 3);
    test(2, 8);
    test(3, 19);
    test(4, 43);
    test(5, 94);
    test(10101, 183236316);

    return 0;
}
