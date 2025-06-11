#include <iostream>

using namespace std;

string getPermutation(int n, int k) {
    string permutation = "";

    int factorial = 1;

    short i;
    for(i = 2; i <= n; ++i) {
        factorial *= i;
    }

    short used = 0;
    short nextUsed;
    --k;

    i = n;
    short j;
    while(i > 0) {
        factorial /= i--;
        nextUsed = k / factorial;
        k %= factorial;

        j = 0;
        while(true) {
            if((used & (1 << j)) < 1) {
                if(--nextUsed < 0) {
                    break;
                }
            }

            ++j;
        }

        used |= 1 << j;
        permutation.push_back('0' + ++j);
    }

    return permutation;
}

void test(int n, int k, string expected) {
    cout << "n: " << n << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << getPermutation(n, k) << endl;

    cout << endl;
}

int main() {
    test(3, 3, "213");
    test(4, 9, "2314");
    test(3, 1, "123");
    test(2, 2, "21");
    test(5, 96, "45321");

    return 0;
}
