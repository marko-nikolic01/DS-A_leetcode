#include <iostream>

using namespace std;

char processStr(string s, long long k) {
    long long len = 0;

    for(auto c : s) {
        if(c == '*') {
            if(len) {
                --len;
            }
        } else if(c == '#') {
            len <<= 1;
        } else if (c != '%') {
            ++len;
        }
    }

    if(k + 1 > len) {
        return '.';
    }

    for(int i = s.size() - 1; i > -1; --i) {
        if(s[i] == '*') {
            ++len;
        } else if(s[i] == '#') {
            if(k + 1 > (len + 1) >> 1) {
                k -= len >> 1;
            }

            len = (len + 1) >> 1;
        } else if(s[i] == '%') {
            k = len - k - 1;
        } else if (k + 1 == len) {
            return s[i];
        } else {
            --len;
        }
    }

    return '.';
}

void test(string s, long long k, char expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << "'" << expected << "'" << endl;

    cout << "Result: " << "'" << processStr(s, k) << "'" << endl;

    cout << endl;
}

int main() {
    test("a#b%*", 1, 'a');
    test("cd%#*#", 3, 'd');
    test("z*#", 0, '.');
    test("ab%%", 0, 'a');
    test("abc#%", 4, 'b');
    test("a#####", 31, 'a');

    return 0;
}
