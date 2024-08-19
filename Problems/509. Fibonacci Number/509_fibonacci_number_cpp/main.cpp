#include <iostream>

using namespace std;

int fib(int n, int f1, int f2) {
    while(n-- > 0) {
        int temp = f1;
        f1 = f2;
        f2 = temp + f1;

    }

    return f2;
}

int fib(int n) {
    if(n == 0) {
        return 0;
    } else if(n == 1) {
        return 1;
    }

    return fib(n - 1, 0, 1);
}

void runTest(int n, int expected) {
    int result = fib(n);
    cout << "Number: " << n << endl;
    cout << "Expected: " << expected << endl;
    cout << "Result: " << result << endl;
    cout << endl;
}

int main() {
    runTest(0, 0);
    runTest(1, 1);
    runTest(3, 2);
    runTest(5, 5);
    runTest(6, 8);
    runTest(10, 55);
    runTest(15, 610);

    return 0;
}
