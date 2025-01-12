#include <iostream>

using namespace std;

bool canBeValid(string s, string locked) {
    int n = s.length();
    if((n & 1) > 0) {
        return false;
    }

    int open = 0;
    int any = 0;

    for(int i = 0; i < n; ++i) {
        if(locked[i] == '0') {
            ++any;
        } else if(s[i] == '(') {
            ++open;
        } else if(open > 0) {
            --open;
        } else if(any > 0) {
            --any;
        } else {
            return false;
        }
    }

    open = 0;
    any = 0;

    for(--n; n > -1; --n) {
        if(locked[n] == '0') {
            ++any;
        } else if(s[n] == ')') {
            ++open;
        } else if(open > 0) {
            --open;
        } else if(any > 0) {
            --any;
        } else {
            return false;
        }
    }

    return true;
}

void executeTest(string s, string locked, bool expected) {
    cout << "Parentheses: " << s << endl;

    cout << "Locked: " << locked << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (canBeValid(s, locked) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    executeTest("()))()", "010100", true);
    executeTest("()()", "0000", true);
    executeTest(")", "0", false);
    executeTest("((()))", "111111", true);
    executeTest("((())", "11100", false);
    executeTest("()())(", "000000", true);
    executeTest("(()))", "01001", false);

    return 0;
}
