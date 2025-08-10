#include <iostream>
#include <vector>

using namespace std;

bool reorderedPowerOf2(int n) {
    vector<long> digitScores = {0, 1, 100, 10000, 1000000, 100000000, 10000000000, 1000000000000, 100000000000000, 10000000000000000};
    long score = 0;
    long powerOf2Score;
    short zeros = 0;
    short powerOf2Zeros;
    short digit;

    while(n > 0) {
        digit = n % 10;

        if(digit < 1) {
            ++zeros;
        } else {
            score += digitScores[digit];
        }

        n /= 10;
    }

    for(int powerOf2 = 1; powerOf2 < 1000000001; powerOf2 <<= 1) {
        n = powerOf2;
        powerOf2Score = 0;
        powerOf2Zeros = 0;

        while(n > 0) {
            digit = n % 10;

            if(digit < 1) {
                ++powerOf2Zeros;
            } else {
                powerOf2Score += digitScores[digit];
            }

            n /= 10;
        }

        if(powerOf2Score == score && powerOf2Zeros == zeros) {
            return true;
        }
    }

    return false;
}

void test(int n, bool expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (reorderedPowerOf2(n) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test(1, true);
    test(10, false);
    test(46, true);
    test(124, false);
    test(128, true);
    test(604, false);

    return 0;
}
