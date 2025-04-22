#include <iostream>
#include <vector>

using namespace std;

int powMod(int a, int b) {
    int result = 1;
    while (b > 0) {
        if (b % 2) result = (1LL * result * a) % 1000000007;
        a = (1LL * a * a) % 1000000007;
        b /= 2;
    }
    return result;
}

void precomputeFactorials(int n, vector<int>& factorial, vector<int>& invFactorial) {
    factorial.assign(n + 1, 1);
    invFactorial.assign(n + 1, 1);

    for (int i = 1; i <= n; i++)
        factorial[i] = (1LL * factorial[i - 1] * i) % 1000000007;

    invFactorial[n] = powMod(factorial[n], 1000000007 - 2);

    for (int i = n - 1; i >= 0; i--)
        invFactorial[i] = (1LL * invFactorial[i + 1] * (i + 1)) % 1000000007;
}

int comb(int n, int k, const vector<int>& factorial, const vector<int>& invFactorial) {
    if (k > n) return 0;
    return (1LL * factorial[n] * invFactorial[k] % 1000000007 * invFactorial[n - k] % 1000000007);
}

int idealArrays(int n, int maxValue) {
    vector<int> factorial, invFactorial;
    precomputeFactorials(n, factorial, invFactorial);

    vector<vector<int>> memo(16, vector<int>(maxValue + 1, 0));

    for (int val = 1; val <= maxValue; val++) {
        memo[1][val] = 1;
    }

    for (int len = 2; len <= 15; len++) {
        for (int val = 1; val <= maxValue; val++) {
            for (int mult = 2 * val; mult <= maxValue; mult += val) {
                memo[len][mult] = (memo[len][mult] + memo[len - 1][val]) % 1000000007;
            }
        }
    }

    int result = 0;

    for (int len = 1; len <= 15; len++) {
        for (int val = 1; val <= maxValue; val++) {
            if (memo[len][val] == 0) continue;
            result = (result + 1LL * memo[len][val] * comb(n - 1, len - 1, factorial, invFactorial) % 1000000007) % 1000000007;
        }
    }

    return result;
}

void test(int n, int maxValue, int expected) {
    cout << "n: " << n << endl;

    cout << "Maximum value: " << maxValue << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << idealArrays(n, maxValue) << endl;

    cout << endl;
}

int main() {
    test(2, 5, 10);
    test(5, 3, 11);
    test(1, 10, 10);
    test(3, 2, 4);
    test(4, 4, 19);

    return 0;
}
