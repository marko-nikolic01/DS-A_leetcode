#include <iostream>

using namespace std;

long long kMirror(int k, int n) {
    int digit[100];

    auto isPalindrome = [&](long long x) -> bool {
        int length = -1;

        while(x) {
            ++length;
            digit[length] = x % k;
            x /= k;
        }

        for(int i = 0, j = length; i < j; ++i, --j) {
            if(digit[i] != digit[j]) {
                return false;
            }
        }

        return true;
    };

    int count = 0;
    long ans = 0;

    int left = 1;
    int right;
    int op;
    long combined;
    int x;

    int i;
    while (count < n) {
        right = left * 10;

        for(op = 0; op < 2; ++op) {
            for(i = left; i < right && count < n; ++i) {
                combined = i;
                x = (op == 0 ? i / 10 : i);

                while(x) {
                    combined = combined * 10 + x % 10;
                    x /= 10;
                }

                if(isPalindrome(combined)) {
                    ++count;
                    ans += combined;
                }
            }
        }

        left = right;
    }

    return ans;
}

void test(int k, int n, long long expected) {
    cout << "k: " << k << endl;

    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << kMirror(k, n) << endl;

    cout << endl;
}

int main() {
    test(2, 5, 25);
    test(3, 7, 499);
    test(7, 17, 20379000);
    test(2, 10, 1772);
    test(4, 5, 66);

    return 0;
}
