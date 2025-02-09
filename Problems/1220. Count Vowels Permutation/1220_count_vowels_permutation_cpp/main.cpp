#include <iostream>

using namespace std;

int countVowelPermutation(int n) {
    int a = 1;
    int e = 1;
    int i = 1;
    int o = 1;
    int u = 1;

    int aTemp;
    int eTemp;
    int oTemp;
    int uTemp;

    for(n; n > 1; --n) {
        aTemp = a;
        eTemp = e;
        oTemp = o;
        uTemp = u;

        o = i;
        a = ((eTemp + o) % 1000000007 + uTemp) % 1000000007;
        e = (aTemp + o) % 1000000007;
        i = (eTemp + oTemp) % 1000000007;
        u = (o + oTemp) % 1000000007;
    }

    return ((((a + e) % 1000000007 + i) % 1000000007 + o) % 1000000007 + u) % 1000000007;
}

void test(int n, int expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countVowelPermutation(n) << endl;

    cout << endl;
}

int main() {
    test(1, 5);
    test(2, 10);
    test(5, 68);
    test(10, 1739);
    test(15, 44779);
    test(20, 1151090);
    test(25, 29599477);

    return 0;
}
