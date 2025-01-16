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

void test(string s, bool expected) {
    cout << "Number: " << s << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (isNumber(s) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test("2", true);
    test("0089", true);
    test("-0.1", true);
    test("+3.14", true);
    test("4.", true);
    test("-.9", true);
    test("2e10", true);
    test("-90E3", true);
    test("3e+7", true);
    test("+6e-1", true);
    test("53.5e93", true);
    test("-123.456e789", true);
    test("abc", false);
    test("1a", false);
    test("1e", false);
    test("e3", false);
    test("99e2.5", false);
    test("--6", false);
    test("-+3", false);
    test("95a54e53", false);
    test("0", true);
    test("e", false);
    test(".", false);

    return 0;
}
