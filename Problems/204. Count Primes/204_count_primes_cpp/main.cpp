#include <iostream>
#include <vector>

using namespace std;

int countPrimes(int n) {
    vector<bool> isPrime(n, true);
    int primes = 0;

    int j;
    for(int i = 2; i < n; ++i) {
        if(isPrime[i]) {
            ++primes;

            for(j = i << 1; j < n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    return primes;
}

void test(int n, int expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countPrimes(n) << endl;

    cout << endl;
}

int main() {
    test(10, 4);
    test(0, 0);
    test(1, 0);
    test(20, 8);
    test(100, 25);
    test(1000, 168);
    test(5000000, 348513);

    return 0;
}
