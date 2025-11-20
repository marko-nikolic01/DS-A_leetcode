#include <iostream>
#include <vector>

using namespace std;

int minSteps(string s, string t) {
    int steps = 0;
    vector<int> letters(26, 0);

    int i;
    for(i = s.length() - 1; i > -1; --i) {
        ++letters[s[i] - 'a'];
    }

    for(i = t.length() - 1; i > -1; --i) {
        --letters[t[i] - 'a'];
    }

    while(++i < 26) {
        steps += abs(letters[i]);
    }

    return steps;
}

void test(string s, string t, int expected) {
    cout << "s: " << "\"" << s << "\"" << endl;

    cout << "t: " << "\"" << t << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minSteps(s, t) << endl;

    cout << endl;
}

int main() {
    test("leetcode", "coats", 7);
    test("night", "thing", 0);
    test("aab", "bb", 3);
    test("abc", "def", 6);
    test("xxyyzz", "xyz", 3);

    return 0;
}
