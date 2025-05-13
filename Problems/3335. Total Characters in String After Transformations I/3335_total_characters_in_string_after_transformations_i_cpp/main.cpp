#include <iostream>
#include <vector>

using namespace std;

int lengthAfterTransformations(string s, int t) {
    vector<int> cnt(26);
    for (char ch : s) {
        ++cnt[ch - 'a'];
    }
    for (int round = 0; round < t; ++round) {
        vector<int> nxt(26);
        nxt[0] = cnt[25];
        nxt[1] = (cnt[25] + cnt[0]) % 1000000007;
        for (int i = 2; i < 26; ++i) {
            nxt[i] = cnt[i - 1];
        }
        cnt = move(nxt);
    }
    int ans = 0;
    for (int i = 0; i < 26; ++i) {
        ans = (ans + cnt[i]) % 1000000007;
    }
    return ans;
}

void test(string s, int t, int expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "t: " << t << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << lengthAfterTransformations(s, t) << endl;

    cout << endl;
}

int main() {
    test("abcyy", 2, 7);
    test("azbk", 1, 5);
    test("zzz", 1, 6);
    test("z", 3, 2);
    test("a", 3, 1);

    return 0;
}
