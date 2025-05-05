#include <iostream>
#include <vector>

using namespace std;

int numTilings(int n) {
    int tilings = 1;
    int tempTilings;

    int plus1 = 0;
    int topBottomPlus1 = 0;

    int minus1 = 0;

    while(--n > -1) {
        tempTilings = tilings;

        tilings = (tilings + topBottomPlus1) % 1000000007;
        tilings = ((tilings + minus1) % 1000000007 + minus1) % 1000000007;

        topBottomPlus1 = tempTilings;
        minus1 = plus1;
        plus1 = (tempTilings + plus1) % 1000000007;
    }

    return tilings;
}

void test(int n, int expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numTilings(n) << endl;

    cout << endl;
}

int main() {
    test(1, 1);
    test(2, 2);
    test(3, 5);
    test(4, 11);
    test(5, 24);

    return 0;
}
