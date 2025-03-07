#include <iostream>
#include <vector>

using namespace std;

vector<int> closestPrimes(int left, int right) {
    vector<bool> isPrime(right + 1, true);

    int i;
    int j;
    for(i = 2; i * i <= right; ++i) {
        for(j = i * i; j <= right; j += i) {
            isPrime[j] = false;
        }
    }

    vector<int> primes = {-1, -1};
    j = 1000000;

    if(left < 2) {
        left = 2;
    }

    for(left; left <= right; ++left) {
        if(isPrime[left]) {
            i = left;
            break;
        }
    }

    for(++left; left <= right; ++left) {
        if(isPrime[left]) {
            if(left - i < j) {
                primes[0] = i;
                primes[1] = left;

                j = left - i;
            }

            i = left;
        }
    }

    return primes;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(int left, int right, vector<int> expected) {
    cout << "Left: " << left << endl;

    cout << "Right: " << right << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(closestPrimes(left, right));

    cout << endl;
}

int main() {
    test(10, 19, {11, 13});
    test(4, 6, {-1, -1});
    test(2, 10, {2, 3});
    test(20, 50, {29, 31});
    test(100, 110, {101, 103});
    test(1, 1, {-1, -1});

    return 0;
}
