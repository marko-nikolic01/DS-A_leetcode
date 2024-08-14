#include <iostream>

using namespace std;

bool isUgly(int n) {
    if(n < 1) {
        return false;
    }

    while(n % 2 == 0) {
        n /= 2;
    }

    while(n % 3 == 0) {
        n /= 3;
    }

    while(n % 5 == 0) {
        n /= 5;
    }

    return n == 1;
}

void testIsUgly(int n, bool expected) {
    bool result = isUgly(n);
    cout << "Number: " << n << ", Expected: " << (expected ? "true" : "false") << ", Result: " << (result ? "true" : "false") << endl << endl;
}

int main()
{
    testIsUgly(6, true);
    testIsUgly(8, true);
    testIsUgly(14, false);
    testIsUgly(1, true);
    testIsUgly(30, true);
    testIsUgly(-6, false);

    return 0;
}
