#include <iostream>
#include <vector>

using namespace std;

int rearrangeCharacters(string s, string target) {
    vector<short> letters(26, 0);
    vector<short> targetLetters(26, 0);

    short i;
    for(i = s.length() - 1; i > -1; --i) {
        ++letters[s[i] - 'a'];
    }

    short n = target.length();
    for(i = --n; i > -1; --i) {
        target[i] -= 'a';
        ++targetLetters[target[i]];
    }

    i = 100;

    for(n; n > -1 && i > 0; --n) {
        i = min(i, (short)(letters[target[n]] / targetLetters[target[n]]));
    }

    return i;
}

void test(string s, string target, int expected) {
    cout << "Letters: " << s << endl;

    cout << "Target: " << "\"" << target << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << rearrangeCharacters(s, target) << endl;

    cout << endl;
}

int main() {
    test("ilovecodingonleetcode", "code", 2);
    test("abcba", "abc", 1);
    test("abbaccaddaeea", "aaaaa", 1);
    test("aaaaabbbbcc", "abc", 2);
    test("zzz", "z", 3);

    return 0;
}
