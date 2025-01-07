#include <iostream>

using namespace std;

bool isValid(string s) {
    int nLetters = -1;

    int n = s.size();
    for(int i = 0; i < n; ++i) {
        if(s[i] == 'c' && nLetters > 0 && s[nLetters] == 'b' && s[nLetters - 1] == 'a') {
            nLetters -= 2;
        } else {
            s[++nLetters] = s[i];
        }
    }

    return nLetters == -1;
}

void test(string word, bool expected) {
    cout << "Word: " << word << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (isValid(word) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test("aabcbc", true);
    test("abcabcababcc", true);
    test("abccba", false);
    test("abc", true);
    test("aabbcc", false);
    test("ababc", false);
    test("abcabcabc", true);
    test("aaa", false);
    test("cba", false);
    test("aaabcbcbc", true);

    return 0;
}
