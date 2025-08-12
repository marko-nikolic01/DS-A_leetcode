#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int numberOfWays(int n, int x) {
    vector<int> ways(++n, 0);
    ++ways[0];

    short base = floor(pow(n--, 1.0 / x)) + 1;
    short power;
    short exponent;

    short i;
    while(--base > 0) {
        power = base;
        exponent = x;

        while(--exponent > 0 && power <= n) {
            power *= base;
        }

        if(power > n) {
            continue;
        }

        for(i = n - power; i > -1; --i) {
            if(ways[i] > 0) {
                ways[i + power] = (ways[i + power] + ways[i]) % 1000000007;
            }
        }
    }

    return ways[n];
}

void test(int n, int x, int expected) {
    cout << "n: " << n << endl;

    cout << "x: " << x << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numberOfWays(n, x) << endl;

    cout << endl;
}

int main() {
    test(10, 2, 1);
    test(4, 1, 2);
    test(1, 1, 1);
    test(182, 2, 8);
    test(160, 3, 1);

    return 0;
}
