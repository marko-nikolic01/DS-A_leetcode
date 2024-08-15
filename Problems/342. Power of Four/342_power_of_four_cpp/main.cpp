#include <iostream>

using namespace std;

bool isPowerOfFour(int n) {
    return n > 0 && 1073741824 % n == 0 && !isPowerOfFour(n / 2);
}

int main() {
    int n1 = 16;
    cout << "n: " << n1 << endl;
    cout << "Expected: true" << endl;
    cout << "Result: " << (isPowerOfFour(n1) ? "true" : "false") << endl;
    cout << endl;

    int n2 = 5;
    cout << "n: " << n2 << endl;
    cout << "Expected: false" << endl;
    cout << "Result: " << (isPowerOfFour(n2) ? "true" : "false") << endl;
    cout << endl;

    int n3 = 64;
    cout << "n: " << n3 << endl;
    cout << "Expected: true" << endl;
    cout << "Result: " << (isPowerOfFour(n3) ? "true" : "false") << endl;
    cout << endl;

    int n4 = 20;
    cout << "n: " << n4 << endl;
    cout << "Expected: false" << endl;
    cout << "Result: " << (isPowerOfFour(n4) ? "true" : "false") << endl;
    cout << endl;

    int n5 = 1;
    cout << "n: " << n5 << endl;
    cout << "Expected: true" << endl;
    cout << "Result: " << (isPowerOfFour(n5) ? "true" : "false") << endl;
    cout << endl;

    int n6 = -64;
    cout << "n: " << n6 << endl;
    cout << "Expected: false" << endl;
    cout << "Result: " << (isPowerOfFour(n6) ? "true" : "false") << endl;
    cout << endl;

    int n7 = 0;
    cout << "n: " << n7 << endl;
    cout << "Expected: false" << endl;
    cout << "Result: " << (isPowerOfFour(n7) ? "true" : "false") << endl;

    return 0;
}
