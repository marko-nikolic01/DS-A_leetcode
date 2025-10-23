#include <iostream>

using namespace std;

bool hasSameDigits(string s) {
    short i;
    for(short n = s.length() - 1; n > 1; --n) {
        for(i = 0; i < n; ++i) {
            s[i] = (s[i] + s[i + 1] - '`') % 10 + '0';
        }
    }

    return s[0] == s[1];
}

void test(string s, bool expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (hasSameDigits(s) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test("3902", true);
    test("34789", false);
    test("1234", false);
    test("5555", true);
    test("90817", true);
    test("12345", false);

    return 0;
}
