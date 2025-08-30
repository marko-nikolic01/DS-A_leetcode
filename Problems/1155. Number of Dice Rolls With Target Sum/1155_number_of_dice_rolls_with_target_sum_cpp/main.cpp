#include <iostream>
#include <vector>

using namespace std;

int numRollsToTarget(int n, int k, int target) {
    vector<int> rolls(target--, 0);

    short i;
    short j;
    for(i = 0; i < k && i <= target; ++i) {
        ++rolls[i];
    }

    while(--n > 0) {
        for(i = target; i > -1; --i) {
            rolls[i] = 0;

            for(j = 1; j <= k && i - j > -1; ++j) {
                rolls[i] = (rolls[i] + rolls[i - j]) % 1000000007;
            }
        }
    }

    return rolls[target];
}

void test(int n, int k, int target, int expected) {
    cout << "n: " << n << endl;

    cout << "k: " << k << endl;

    cout << "Target: " << target << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numRollsToTarget(n, k, target) << endl;

    cout << endl;
}

int main() {
    test(1, 6, 3, 1);
    test(2, 6, 7, 6);
    test(30, 30, 500, 222616187);
    test(2, 6, 12, 1);
    test(3, 4, 5, 6);

    return 0;
}
