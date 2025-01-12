#include <iostream>

using namespace std;

bool canBeValid(string s, string locked) {
    int n = s.length();
    if((n & 1) > 0) {
        return false;
    }

    int open = 0;

    for(int i = 0; i < n; ++i) {
        if(s[i] == ')' && locked[i] == '1') {
            if(--open < 0) {
                return false;
            }
        } else {
            ++open;
        }
    }

    open = 0;

    for(--n; n > -1; --n) {
        if(s[n] == '(' && locked[n] == '1') {
            if(--open < 0) {
                return false;
            }
        } else {
            ++open;
        }
    }

    return true;
}

void test(string s, string locked, bool expected) {
    cout << "Parentheses: " << s << endl;

    cout << "Locked: " << locked << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (canBeValid(s, locked) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test("()))()", "010100", true);
    test("()()", "0000", true);
    test(")", "0", false);
    test("((()))", "111111", true);
    test("((())", "11100", false);
    test("()())(", "000000", true);
    test("(()))", "01001", false);

    return 0;
}
