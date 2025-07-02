#include <iostream>
#include <vector>

using namespace std;

int possibleStringCount(string word, int k) {
    int n = word.size();
    int cnt = 1;
    vector<int> freq;

    for (int i = 1; i < n; ++i) {
        if (word[i] == word[i - 1]) {
            ++cnt;
        } else {
            freq.push_back(cnt);
            cnt = 1;
        }
    }
    freq.push_back(cnt);

    int ans = 1;
    for (int f : freq) {
        ans = static_cast<long long>(ans) * f % 1000000007;
    }

    if (freq.size() >= k) {
        return ans;
    }

    vector<int> f(k);
    vector<int> g(k, 1);
    f[0] = 1;

    for (int i = 0; i < freq.size(); ++i) {
        vector<int> f_new(k);
        vector<int> g_new(k);

        for (int j = 1; j < k; ++j) {
            f_new[j] = g[j - 1];

            if (j - freq[i] - 1 >= 0) {
                f_new[j] = (f_new[j] - g[j - freq[i] - 1] + 1000000007) % 1000000007;
            }
        }

        g_new[0] = f_new[0];

        for (int j = 1; j < k; ++j) {
            g_new[j] = (g_new[j - 1] + f_new[j]) % 1000000007;
        }

        f = move(f_new);
        g = move(g_new);
    }

    return (ans - g[k - 1] + 1000000007) % 1000000007;
}

void test(string word, int k, int expected) {
    cout << "Word: " << "\"" << word << "\"" << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << possibleStringCount(word, k) << endl;

    cout << endl;
}

int main() {
    test("aabbccdd", 7, 5);
    test("aabbccdd", 8, 1);
    test("aaabbb", 3, 8);
    test("aaaaaa", 3, 4);
    test("abc", 1, 1);

    return 0;
}
