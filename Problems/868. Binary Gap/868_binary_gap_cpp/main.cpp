#include <iostream>

using namespace std;

int binaryGap(int n) {
    short longestGap = 0;
    short gap = 0;

    while((n & 1) < 1) {
        n >>= 1;
    }

    while(n > 0) {
        if((n & 1) > 0) {
            if(gap > longestGap) {
                longestGap = gap;
            }

            gap = 0;
        }

        ++gap;
        n >>= 1;
    }

    return longestGap;
}

void test(int n, int expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << binaryGap(n) << endl;

    cout << endl;
}

int main(){
    test(22, 2);
    test(8, 0);
    test(5, 2);
    test(6, 1);
    test(9, 3);
    test(1, 0);
    test(1000000000, 3);

    return 0;
}
