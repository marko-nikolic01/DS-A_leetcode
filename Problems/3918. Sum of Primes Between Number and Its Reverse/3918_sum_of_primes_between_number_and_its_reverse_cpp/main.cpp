#include <iostream>
#include <vector>

using namespace std;

int sumOfPrimesInRange(short n1, short n2) {
    int primes = 0;
    vector<bool> isPrime(++n2, true);

    isPrime[1] = false;

    short j;
    for(short i = 2; i < n2; ++i) {
        if(isPrime[i]) {
            for(j = i << 1; j < n2; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for(n1; n1 < n2; ++n1) {
        if(isPrime[n1]) {
            primes += n1;
        }
    }

    return primes;
}

int sumOfPrimesInRange(int n) {
    int primes = 0;
    short nReversed = 0;

    for(short i = n; i > 0; i /= 10) {
        nReversed = 10 * nReversed + i % 10;
    }

    return n < nReversed ? sumOfPrimesInRange(n, nReversed) : sumOfPrimesInRange(nReversed, n);
}

void test(int n, int expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << sumOfPrimesInRange(n) << endl;

    cout << endl;
}

int main() {
    test(13, 132);
    test(10, 17);
    test(8, 0);
    test(1, 0);
    test(2, 2);
    test(100, 1060);
    test(1000, 76127);

    return 0;
}
