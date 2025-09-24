#include <iostream>
#include <vector>

using namespace std;

int numDistinct(string s, string t) {
    short nT = t.size();
    vector<int> dp(nT--, 0);

    short iT;
    short nS = s.length();
    for(short iS = 0; iS < nS; ++iS) {
        for(iT = nT; iT > -1; --iT) {
            if(s[iS] == t[iT]) {
                dp[iT] += iT > 0 ? (long)dp[iT - 1] : 1;
            }
        }
    }

    return dp[nT];
}

void test(string s, string t, int expected) {
    cout << "s: " << "\"" << s << "\"" << endl;

    cout << "t: " << "\"" << t << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numDistinct(s, t) << endl;

    cout << endl;
}

int main() {
    test("rabbbit", "rabbit", 3);
    test("babgbag", "bag", 5);
    test("abc", "d", 0);
    test("abc", "a", 1);
    test("aaaa", "aa", 6);

    return 0;
}
