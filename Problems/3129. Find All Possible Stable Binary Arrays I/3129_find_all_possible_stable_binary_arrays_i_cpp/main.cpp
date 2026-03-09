#include <iostream>
#include <vector>

using namespace std;

int numberOfStableArrays(int zero, int one, int limit) {
    vector<vector<vector<long>>> dp(++zero, vector<vector<long>>(++one, vector<long>(2)));

    short i;
    short j = min(--zero, limit);
    for(int i = 0; i <= j; i++) {
        dp[i][0][0] = 1;
    }

    j = min(--one, limit);
    for(i = 0; i <= j; ++i) {
        dp[0][i][1] = 1;
    }

    for(i = 1; i <= zero; i++) {
        for(j = 1; j <= one; j++) {
            if(i > limit) {
                dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1] - dp[i - limit - 1][j][1];
            } else {
                dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
            }

            dp[i][j][0] = (dp[i][j][0] % 1000000007 + 1000000007) % 1000000007;

            if(j > limit) {
                dp[i][j][1] = dp[i][j - 1][1] + dp[i][j - 1][0] - dp[i][j - limit - 1][0];
            } else {
                dp[i][j][1] = dp[i][j - 1][1] + dp[i][j - 1][0];
            }

            dp[i][j][1] = (dp[i][j][1] % 1000000007 + 1000000007) % 1000000007;
        }
    }

    return (dp[zero][one][0] + dp[zero][one][1]) % 1000000007;
}

void test(int zero, int one, int limit, int expected) {
    cout << "Zeros: " << zero << endl;

    cout << "Ones: " << one << endl;

    cout << "Limit: " << limit << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result:   " << numberOfStableArrays(zero, one, limit) << endl;

    cout << endl;
}

int main() {
    test(1, 1, 2, 2);
    test(1, 2, 1, 1);
    test(3, 3, 2, 14);
    test(2, 2, 1, 2);
    test(200, 200, 200, 587893473);

    return 0;
}
