#include <iostream>
#include <vector>

using namespace std;

bool winnerSquareGame(int n) {
    vector<bool> dp(n + 1, false);

    int j;
    for(int i = 0; i <= n; ++i) {
        if(!dp[i]) {
            for(j = 1; i + j * j <= n; ++j) {
                dp[i + j * j] = true;
            }

            if(dp[n]) {
                return true;
            }
        }
    }

    return false;
}

void test(int n, bool expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (winnerSquareGame(n) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test(1, true);
    test(2, false);
    test(4, true);
    test(7, false);
    test(8, true);

    return 0;
}
