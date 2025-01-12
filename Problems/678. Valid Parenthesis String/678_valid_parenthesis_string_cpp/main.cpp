#include <iostream>

using namespace std;

bool checkValidString(string s) {
    int open = 0;
    int closed = 0;

    int n = s.length();
    --n;
    for(int i = 0; i <= n; ++i) {
        if(s[i] == ')') {
            if(--open < 0) {
                return false;
            }
        } else {
            ++open;
        }

        if(s[n - i] == '(') {
            if(--closed < 0) {
                return false;
            }
        } else {
            ++closed;
        }
    }

    return true;
}

void test(string s, bool expected) {
    cout << "Parentheses: " << s << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (checkValidString(s) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test("()", true);
    test("(*)", true);
    test("(*))", true);
    test("(*)))", false);
    test("((*)", true);
    test("*(", false);
    test("(*)(", false);

    return 0;
}
