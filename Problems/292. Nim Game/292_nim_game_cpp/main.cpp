#include <iostream>

using namespace std;

bool canWinNim(int n) {
    return n % 4 != 0;
}

int main() {
    int n1 = 4;
    cout << "n: " << n1 << endl;
    cout << "Expected: false" << endl;
    cout << "Result: " << (canWinNim(n1) ? "true" : "false") << endl;
    cout << endl;

    int n2 = 1;
    cout << "n: " << n2 << endl;
    cout << "Expected: true" << endl;
    cout << "Result: " << (canWinNim(n2) ? "true" : "false") << endl;
    cout << endl;

    int n3 = 7;
    cout << "n: " << n3 << endl;
    cout << "Expected: true" << endl;
    cout << "Result: " << (canWinNim(n3) ? "true" : "false") << endl;
    cout << endl;

    int n4 = 8;
    cout << "n: " << n4 << endl;
    cout << "Expected: false" << endl;
    cout << "Result: " << (canWinNim(n4) ? "true" : "false") << endl;
    cout << endl;

    int n5 = 15;
    cout << "n: " << n5 << endl;
    cout << "Expected: true" << endl;
    cout << "Result: " << (canWinNim(n5) ? "true" : "false") << endl;

    return 0;
}

