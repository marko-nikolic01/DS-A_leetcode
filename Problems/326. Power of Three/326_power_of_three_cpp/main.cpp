#include <iostream>

using namespace std;

bool isPowerOfThree(int n) {
    while(n > 1) {
        if(n % 3 != 0) {
            return false;
        }
        n /= 3;
    }

    return n == 1;
}

int main() {
    int n1 = 27;
    cout << "n: " << n1 << endl;
    cout << "Expected: true" << endl;
    cout << "Result: " << (isPowerOfThree(n1) ? "true" : "false") << endl;
    cout << endl;

    int n2 = 0;
    cout << "n: " << n2 << endl;
    cout << "Expected: false" << endl;
    cout << "Result: " << (isPowerOfThree(n2) ? "true" : "false") << endl;
    cout << endl;

    int n3 = 9;
    cout << "n: " << n3 << endl;
    cout << "Expected: true" << endl;
    cout << "Result: " << (isPowerOfThree(n3) ? "true" : "false") << endl;
    cout << endl;

    int n4 = 45;
    cout << "n: " << n4 << endl;
    cout << "Expected: false" << endl;
    cout << "Result: " << (isPowerOfThree(n4) ? "true" : "false") << endl;
    cout << endl;

    int n5 = 1;
    cout << "n: " << n5 << endl;
    cout << "Expected: true" << endl;
    cout << "Result: " << (isPowerOfThree(n5) ? "true" : "false") << endl;

    return 0;
}
