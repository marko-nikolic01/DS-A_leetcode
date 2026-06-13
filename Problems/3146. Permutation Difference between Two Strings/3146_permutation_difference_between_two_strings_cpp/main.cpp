#include <iostream>
#include <vector>

using namespace std;

int findPermutationDifference(string s, string t) {
    short difference = 0;
    vector<short> letters(26);

    short n = s.length();
    for(short i = --n; i > -1; --i) {
        letters[s[i] - 'a'] = i;
    }

    for(n; n > -1; --n) {
        difference += abs(n - letters[t[n] - 'a']);
    }

    return difference;
}

void test(string s, string t, int expected) {
    cout << "s: " << "\"" << s << "\"" << endl;

    cout << "t: " << "\"" << t << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << findPermutationDifference(s, t) << endl;

    cout << endl;
}

int main() {
    test("abc", "bac", 2);
    test("abcde", "edbac", 12);
    test("a", "a", 0);
    test("abcd", "dcba", 8);
    test("abcdefg", "abcdefg", 0);

    return 0;
}
