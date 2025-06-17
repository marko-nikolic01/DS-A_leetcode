#include <iostream>
#include <vector>

using namespace std;

long long countGoodArrays(long long x, int n) {
    long long res = 1;

    while (n) {
        if (n & 1) {
            res = res * x % 1000000007;
        }

        x = x * x % 1000000007;
        n >>= 1;
    }

    return res;
}

long long countGoodArrays(int n, int m, vector<long long>& fact, vector<long long>& inv_fact) {
    return fact[n] * inv_fact[m] % 1000000007 * inv_fact[n - m] % 1000000007;
}

void countGoodArrays(vector<long long>& fact, vector<long long>& inv_fact) {
    fact[0] = 1;

    for (int i = 1; i < 100000; i++) {
        fact[i] = fact[i - 1] * i % 1000000007;
    }

    inv_fact[100000 - 1] = countGoodArrays(fact[100000 - 1], 1000000007 - 2);

    for (int i = 100000 - 1; i > 0; i--) {
        inv_fact[i - 1] = inv_fact[i] * i % 1000000007;
    }
}

int countGoodArrays(int n, int m, int k) {
    vector<long long> fact(100000);
    vector<long long> inv_fact(100000);

    countGoodArrays(fact, inv_fact);

    return countGoodArrays(n - 1, k, fact, inv_fact) * m % 1000000007 * countGoodArrays(m - 1, n - k - 1) % 1000000007;
}

void test(int n, int m, int k, int expected) {
    cout << "n: " << n << endl;

    cout << "m: " << m << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countGoodArrays(n, m, k) << endl;

    cout << endl;
}

int main() {
    test(3, 2, 1, 4);
    test(4, 2, 2, 6);
    test(5, 2, 0, 2);
    test(3, 2, 2, 2);
    test(2, 3, 0, 6);

    return 0;
}
