#include <iostream>

using namespace std;

int mySqrt(int x) {
    int a = 0;
    int b = x;

    if(x == 1) {
        return x;
    }

    while(b - a > 1) {
        int aa = a * a;
        int bb= b * b;

        if(aa == x) {
            return a;
        } else if(bb == x) {
            return b;
        }

        int middle = (a + b) / 2;
        if(middle * middle > x) {
            b = middle;
        } else {
            a = middle;
        }
    }

    return a;
}

int main() {
    int x1 = 4;
    int x2 = 8;
    int x3 = 16;
    int x4 = 27;
    int x5 = 1;

    cout << "mySqrt(" << x1 << ") = " << mySqrt(x1) << endl;
    cout << "mySqrt(" << x2 << ") = " << mySqrt(x2) << endl;
    cout << "mySqrt(" << x3 << ") = " << mySqrt(x3) << endl;
    cout << "mySqrt(" << x4 << ") = " << mySqrt(x4) << endl;
    cout << "mySqrt(" << x5 << ") = " << mySqrt(x5) << endl;

    return 0;
}
