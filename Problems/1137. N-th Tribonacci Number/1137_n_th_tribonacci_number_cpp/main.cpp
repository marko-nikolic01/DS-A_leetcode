#include <iostream>

using namespace std;

int tribonacci(int n) {
    if(n == 0) {
        return 0;
    } else if(n < 3) {
        return 1;
    }

    int n1 = 0;
    int n2 = 1;
    int n3 = 1;

    while(n-- > 2) {
        int n4 = n1 + n2 + n3;
        n1 = n2;
        n2 = n3;
        n3 = n4;
    }

    return n3;
}

void test(int n, int expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << tribonacci(n) << endl;

    cout << endl;
}

int main() {
    test(0, 0);
    test(1, 1);
    test(2, 1);
    test(3, 2);
    test(4, 4);
    test(5, 7);
    test(6, 13);
    test(7, 24);
    test(37, 2082876103);

    return 0;
}
