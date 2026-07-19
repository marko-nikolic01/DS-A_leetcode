#include <iostream>
#include <vector>

using namespace std;

string lexSmallestAfterDeletion(string s) {
    vector<int> letters(26, 0);
    vector<vector<int>> usedLetters(26);

    int iSubsequence;
    int n = s.length();
    for(iSubsequence = 0; iSubsequence < n; ++iSubsequence) {
        letters[s[iSubsequence] - 'a'] = iSubsequence;
    }

    iSubsequence = -1;
    for(int i = 0; i < n; ++i) {
        while(iSubsequence > -1 && s[i] < s[iSubsequence] && (letters[s[iSubsequence] - 'a'] > i || usedLetters[s[iSubsequence] - 'a'].size() > 1)) {
            usedLetters[s[iSubsequence--] - 'a'].pop_back();
        }

        s[++iSubsequence] = s[i];
        usedLetters[s[i] - 'a'].push_back(iSubsequence);
    }

    while(usedLetters[s[iSubsequence] - 'a'].size() > 1) {
        usedLetters[s[iSubsequence--] - 'a'].pop_back();
    }

    s.resize(++iSubsequence);

    return s;
}

void test(string s, string expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << lexSmallestAfterDeletion(s) << "\"" << endl;

    cout << endl;
}

int main() {
    test("aaccb", "aacb");
    test("z", "z");
    test("abc", "abc");
    test("bbaa", "ba");
    test("cbacdcbc", "acdb");

    return 0;
}
