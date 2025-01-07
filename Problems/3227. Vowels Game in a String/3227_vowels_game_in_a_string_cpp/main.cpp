#include <iostream>

using namespace std;

bool doesAliceWin(string s) {
    for(int i = s.length() - 1; i > -1; --i) {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            return true;
        }
    }

    return false;
}

void test(string s, bool expected) {
    cout << "String: \"" << s << "\"" << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (doesAliceWin(s) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test("leetcoder", true);
    test("bbcd", false);
    test("aeiou", true);
    test("bcdfg", false);
    test("hello", true);
    test("programming", true);
    test("a", true);
    test("b", false);

    return 0;
}
