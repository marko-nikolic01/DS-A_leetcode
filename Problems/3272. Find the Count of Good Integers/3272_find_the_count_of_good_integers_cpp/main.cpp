#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>
#include <algorithm>

using namespace std;

long long countGoodIntegers(int n, int k) {
    unordered_set<string> dict;
    int base = pow(10, (n - 1) / 2);
    int skip = n & 1;
    for (int i = base; i < base * 10; i++) {
        string s = to_string(i);
        s += string(s.rbegin() + skip, s.rend());
        long long palindromicInteger = stoll(s);
        if (palindromicInteger % k == 0) {
            sort(s.begin(), s.end());
            dict.emplace(s);
        }
    }

    vector<long long> factorial(n + 1, 1);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        factorial[i] = factorial[i - 1] * i;
    }
    for (const string &s : dict) {
        vector<int> cnt(10);
        for (char c : s) {
            cnt[c - '0']++;
        }
        long long tot = (n - cnt[0]) * factorial[n - 1];
        for (int x : cnt) {
            tot /= factorial[x];
        }
        ans += tot;
    }

    return ans;
}

void test(int n, int k, long long expected) {
    cout << "n: " << n << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countGoodIntegers(n, k) << endl;

    cout << endl;
}

int main() {
    test(3, 5, 27);
    test(1, 4, 2);
    test(5, 6, 2468);
    test(2, 1, 9);
    test(4, 2, 172);

    return 0;
}
