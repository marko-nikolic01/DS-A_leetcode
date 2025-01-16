#include <iostream>

using namespace std;

bool isNumber(string s) {
    short i = 0;
    short n = s.length();

    if(s[0] == '+' || s[0] == '-') {
        if(++i == n) {
            return false;
        }
    }

    if(s[i] == '.') {
        if(++i == n || s[i] < '0' || s[i] > '9') {
            return false;
        }

        while(i < n && s[i] > '/' && s[i] <= ':') {
            ++i;
        }

        if(i == n) {
            return true;
        }
    } else {
        if(i == n || s[i] < '0' || s[i] > '9') {
            return false;
        }

        ++i;
        while(i < n && s[i] > '/' && s[i] <= ':') {
            ++i;
        }

        if(i == n) {
            return true;
        }

        if(s[i] == '.') {
            if(++i == n) {
                return true;
            }

            while(i < n && s[i] > '/' && s[i] <= ':') {
                ++i;
            }

            if(i == n) {
                return true;
            }
        }
    }

    if(s[i] == 'e' || s[i] == 'E') {
        if(++i == n) {
            return false;
        }

        if(s[i] == '+' || s[i] == '-') {
            if(++i == n) {
                return false;
            }
        }

        while(i < n && s[i] > '/' && s[i] <= ':') {
            ++i;
        }
    }

    return i == n;
}

void runTest(string s, bool expected) {
    cout << "Number: " << s << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result:   " << (isNumber(s) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    runTest("2", true);
    runTest("0089", true);
    runTest("-0.1", true);
    runTest("+3.14", true);
    runTest("4.", true);
    runTest("-.9", true);
    runTest("2e10", true);
    runTest("-90E3", true);
    runTest("3e+7", true);
    runTest("+6e-1", true);
    runTest("53.5e93", true);
    runTest("-123.456e789", true);
    runTest("abc", false);
    runTest("1a", false);
    runTest("1e", false);
    runTest("e3", false);
    runTest("99e2.5", false);
    runTest("--6", false);
    runTest("-+3", false);
    runTest("95a54e53", false);
    runTest("0", true);
    runTest("e", false);
    runTest(".", false);

    return 0;
}
