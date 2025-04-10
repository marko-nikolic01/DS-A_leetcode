#include <iostream>
#include <vector>
#include <functional>

using namespace std;

long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
    string low = to_string(start);
    string high = to_string(finish);
    int n = high.size();
    low = string(n - low.size(), '0') + low;
    int pre_len = n - s.size();

    vector<long long> memo(n, -1);
    function<long long(int, bool, bool)> dfs =
        [&](int i, bool limit_low, bool limit_high) -> long long {
        if (i == low.size()) {
            return 1;
        }

        if (!limit_low && !limit_high && memo[i] != -1) {
            return memo[i];
        }

        int lo = limit_low ? low[i] - '0' : 0;
        int hi = limit_high ? high[i] - '0' : 9;

        long long res = 0;
        if (i < pre_len) {
            for (int digit = lo; digit <= min(hi, limit); digit++) {
                res += dfs(i + 1, limit_low && digit == lo,
                           limit_high && digit == hi);
            }
        } else {
            int x = s[i - pre_len] - '0';
            if (lo <= x && x <= min(hi, limit)) {
                res =
                    dfs(i + 1, limit_low && x == lo, limit_high && x == hi);
            }
        }

        if (!limit_low && !limit_high) {
            memo[i] = res;
        }
        return res;
    };
    return dfs(0, true, true);
}

void runTest(long long start, long long finish, int limit, string s, long long expected) {
    cout << "Start: " << start << endl;

    cout << "Finish: " << finish << endl;

    cout << "Limit: " << limit << endl;

    cout << "Suffix: " << s << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numberOfPowerfulInt(start, finish, limit, s) << endl;

    cout << endl;
}

int main() {
    runTest(1, 6000, 4, "124", 5);
    runTest(15, 215, 6, "10", 2);
    runTest(1000, 2000, 4, "3000", 0);
    runTest(1, 10000, 2, "22", 9);
    runTest(10, 9999, 9, "9", 999);

    return 0;
}
