#include <iostream>
#include <string>

using namespace std;

bool checkString(string s) {
    for(short i = s.length() - 1; i > 0; --i) {
        if(s[i] < 'b' && s[i - 1] > 'a') {
            return false;
        }
    }

    return true;
}

void test(string s, bool expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (checkString(s) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test("aaabbb", true);
    test("abab", false);
    test("bbb", true);
    test("aaa", true);
    test("bbaaa", false);
    test("ab", true);
    test("ba", false);

    return 0;
}
