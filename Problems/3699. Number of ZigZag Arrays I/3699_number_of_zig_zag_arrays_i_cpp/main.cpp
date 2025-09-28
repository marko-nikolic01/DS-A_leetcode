#include <iostream>
#include <vector>

using namespace std;

int zigZagArrays(int n, int l, int r) {
    r -= l;
    vector<int> dp(r + 1, 1);
    int sum;

    short i;
    while(--n > 0) {
        sum = 0;

        if((n & 1) < 1) {
            for(i = 0; i <= r; ++i) {
                l = sum;
                sum = (sum + dp[i]) % 1000000007;
                dp[i] = l;
            }
        } else {
            for(i = r; i > -1; --i) {
                l = sum;
                sum = (sum + dp[i]) % 1000000007;
                dp[i] = l;
            }
        }
    }

    sum = 0;

    while(r > -1) {
        sum = (sum + dp[r--]) % 1000000007;
    }

    return (sum << 1) % 1000000007;
}

void test(int n, int l, int r, int expected) {
    cout << "n: " << n << endl;

    cout << "l: " << l << endl;

    cout << "r: " << r << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << zigZagArrays(n, l, r) << endl;

    cout << endl;
}

int main() {
    test(3, 4, 5, 2);
    test(3, 1, 3, 10);
    test(50, 365, 1730, 376292319);
    test(4, 1, 2, 2);
    test(3, 1, 4, 28);
    test(5, 1, 3, 26);

    return 0;
}
