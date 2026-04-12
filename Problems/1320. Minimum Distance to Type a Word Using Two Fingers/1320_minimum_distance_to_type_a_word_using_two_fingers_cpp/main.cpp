#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int minimumDistance(string word) {
    short n = word.size();
    vector<vector<short>> dp(n, vector<short>(26, SHRT_MAX));
    short current;
    short previous;
    short distance;
    short distance0;

    fill(dp[0].begin(), dp[0].end(), 0);

    short j;
    short k;
    for(short i = 1; i < n; ++i) {
        current = word[i] - 'A';
        previous = word[i - 1] - 'A';
        distance = abs(previous / 6 - current / 6) + abs(previous % 6 - current % 6);

        for(j = 0; j < 26; ++j) {
            dp[i][j] = min(dp[i][j], (short)(dp[i - 1][j] + distance));

            if(previous == j) {
                for(k = 0; k < 26; ++k) {
                    distance0 = abs(k / 6 - current / 6) + abs(k % 6 - current % 6);
                    dp[i][j] = min(dp[i][j], (short)(dp[i - 1][k] + distance0));
                }
            }
        }
    }

    return *min_element(dp[n].begin(), dp[--n].end());
}

void test(string word, int expected) {
    cout << "Word: " << "\"" << word << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minimumDistance(word) << endl;

    cout << endl;
}

int main() {
    test("CAKE", 3);
    test("HAPPY", 6);
    test("AA", 0);
    test("LEETCODE", 8);
    test("ZZZZZ", 0);

    return 0;
}
