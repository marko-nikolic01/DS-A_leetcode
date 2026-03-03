#include <iostream>

using namespace std;

char findKthBit(int n, int k) {
    string s = "0";

    for(int i = n; i > 1 && s.length() < k; --i) {
        s.push_back('1');

        for(n = s.length() - 2; n > -1; --n) {
            s.push_back(s[n] < '1' ? '1' : '0');
        }
    }

    return s[--k];
}

void test(int n, int k, char expected) {
    cout << "n: " << n << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << findKthBit(n, k) << endl;

    cout << endl;
}

int main() {
    test(3, 1, '0');
    test(4, 11, '1');
    test(1, 1, '0');
    test(2, 3, '1');
    test(4, 4, '1');

    return 0;
}
