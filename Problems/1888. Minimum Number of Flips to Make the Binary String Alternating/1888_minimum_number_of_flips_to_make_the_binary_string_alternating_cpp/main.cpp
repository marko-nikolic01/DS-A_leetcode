#include <iostream>
#include <vector>

using namespace std;

int minFlips(char c, int x) {
    return c - '0' == x ? 1 : 0;
}

int minFlips(string s) {
    int n = s.size();
    vector<vector<int>> prefix(n, vector<int>(2));

    int i;
    for(i = 0; i < n; ++i) {
        prefix[i][0] = (i == 0 ? 0 : prefix[i - 1][1]) + minFlips(s[i], 1);
        prefix[i][1] = (i == 0 ? 0 : prefix[i - 1][0]) + minFlips(s[i], 0);
    }

    int operations = min(prefix[n - 1][0], prefix[n - 1][1]);

    if((n & 1) > 0) {
        vector<vector<int>> suffix(n, vector<int>(2));

        for(i = --n; i >= 0; --i) {
            suffix[i][0] = (i == n ? 0 : suffix[i + 1][1]) + minFlips(s[i], 1);
            suffix[i][1] = (i == n ? 0 : suffix[i + 1][0]) + minFlips(s[i], 0);
        }

        for(i = 0; i < n; ++i) {
            operations = min(operations, prefix[i][0] + suffix[i + 1][0]);
            operations = min(operations, prefix[i][1] + suffix[i + 1][1]);
        }
    }

    return operations;
}

void test(string s, int k, int expected) {
    cout << "String: " << s << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minFlips(s) << endl;

    cout << endl;
}

int main() {
    test("111000", 0, 2);
    test("010", 0, 0);
    test("1110", 0, 1);
    test("10", 0, 0);
    test("01001001101", 0, 2);

    return 0;
}
