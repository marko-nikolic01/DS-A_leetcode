#include <iostream>
#include <vector>

using namespace std;

int countPalindromicSubsequence(string s) {
    vector<vector<int>> letters(26);

    int n = s.length();
    for(int i = 0; i < n; ++i) {
        letters[s[i] - 'a'].push_back(i);
    }

    short palindromes = 0;
    int used = 0;

    for(--n; n > 1; --n) {
        short l = s[n] - 'a';

        letters[l].pop_back();

        if(letters[l].size() > 0 && (used & (1 << l)) == 0) {
            used |= 1 << l;

            for(short i = 0; i < 26; ++i) {
                if(letters[i].size() > 0 && letters[i].back() > letters[l][0]) {
                    ++palindromes;
                }
            }
        }
    }

    return palindromes;
}

void test(string s, int expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countPalindromicSubsequence(s) << endl;

    cout << endl;
}

int main() {
    test("aabca", 3);
    test("adc", 0);
    test("bbcbaba", 4);
    test("aaa", 1);
    test("abc", 0);
    test("aabbcc", 0);
    test("abcabc", 6);
    test("bbaabbaa", 4);

    return 0;
}
