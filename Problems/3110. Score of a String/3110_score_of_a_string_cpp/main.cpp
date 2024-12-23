#include <iostream>

using namespace std;

int scoreOfString(string s) {
    int score = 0;

    for(int i = s.length() - 1; i > 0; --i) {
        score += s[i] > s[i - 1] ? s[i] - s[i - 1] : s[i - 1] - s[i];
    }

    return score;
}

void test(string s, int expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << scoreOfString(s) << endl;

    cout << endl;
}

int main() {
    test("hello", 13);
    test("zaz", 50);
    test("abc", 2);
    test("abcd", 3);
    test("aaa", 0);
    test("leetcode", 63);

    return 0;
}
