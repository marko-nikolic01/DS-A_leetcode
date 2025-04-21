#include <iostream>
#include <vector>

using namespace std;

string smallestPalindrome(string s) {
    vector<int> letters(26, 0);
    char middle;

    int i;
    int n = s.size();
    for(i = 0; i < n; ++i) {
        ++letters[s[i] - 'a'];
    }

    int iPalindrome = 0;
    short iLetter = 0;
    i = 0;
    --n;

    while(iPalindrome <= n) {
        while(letters[iLetter] < 1) {
            ++iLetter;
        }

        if((letters[iLetter] & 1) > 0) {
            s[n >> 1] = iLetter + 'a';
            --letters[iLetter];
            ++iPalindrome;
        }

        while(letters[iLetter] > 0) {
            s[i] = iLetter + 'a';
            s[n - i] = iLetter + 'a';
            ++i;
            letters[iLetter] -= 2;
            iPalindrome += 2;
        }
        ++iLetter;
    }

    return s;
}

void test(string s, string expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << smallestPalindrome(s) << "\"" << endl;

    cout << endl;
}

int main() {
    test("z", "z");
    test("babab", "abbba");
    test("daccad", "acddca");
    test("ggggeee", "eggegge");
    test("zyyzz", "yzzzy");

    return 0;
}
