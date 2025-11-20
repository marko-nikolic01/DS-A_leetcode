#include <iostream>
#include <vector>

using namespace std;

int minSteps(string s, string t) {
    int steps = 0;
    vector<int> letters(26, 0);

    int i;
    for(i = s.length() - 1; i > -1; --i) {
        ++letters[s[i] - 'a'];
        --letters[t[i] - 'a'];
    }

    for(i = 0; i < 26; ++i) {
        steps += abs(letters[i]);
    }

    return ++steps >> 1;
}

void test(string s, string t, int expected) {
    cout << "s: " << "\"" << s << "\"" << endl;

    cout << "t: " << "\"" << t << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minSteps(s, t) << endl;

    cout << endl;
}

int main() {
    test("bab", "aba", 1);
    test("leetcode", "practice", 5);
    test("anagram", "mangaar", 0);
    test("xxyyzz", "zzxxyy", 0);
    test("aaaaab", "bbbbba", 4);

    return 0;
}
