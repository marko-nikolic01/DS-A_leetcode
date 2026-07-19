#include <iostream>
#include <vector>

using namespace std;

string removeDuplicateLetters(string s) {
    vector<short> letters(26, 0);
    int usedLetters = 0;

    short iSubsequence;
    short n = s.length();
    for(iSubsequence = 0; iSubsequence < n; ++iSubsequence) {
        letters[s[iSubsequence] - 'a'] = iSubsequence;
    }

    iSubsequence = -1;
    for(short i = 0; i < n; ++i) {
        if((usedLetters & (1 << (s[i] - 'a'))) < 1) {
            while(iSubsequence > -1 && s[i] < s[iSubsequence] && letters[s[iSubsequence] - 'a'] > i) {
                usedLetters ^= 1 << (s[iSubsequence--] - 'a');
            }

            s[++iSubsequence] = s[i];
            usedLetters |= 1 << (s[i] - 'a');
        }
    }

    s.resize(++iSubsequence);

    return s;
}

void test(string s, string expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << removeDuplicateLetters(s) << "\"" << endl;

    cout << endl;
}

int main() {
    test("bcabc", "abc");
    test("cbacdcbc", "acdb");
    test("a", "a");
    test("cccc", "c");
    test("abcdef", "abcdef");

    return 0;
}
