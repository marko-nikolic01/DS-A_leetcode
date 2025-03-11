#include <iostream>

using namespace std;

int numberOfSubstrings(string s) {
    int substrings = 0;
    int a = 0;
    int b = 0;
    int c = 0;

    int i = s.length();
    int end = --i;
    for(i; i > -1; --i) {
        while(end > -1 && (a < 1 || b < 1 || c < 1)) {
            if(s[end] == 'a') {
                ++a;
            } else if(s[end] == 'b') {
                ++b;
            } else {
                ++c;
            }

            --end;
        }

        if(a > 0 && b > 0 && c > 0) {
            substrings += end + 2;
        } else if(end < 0) {
            break;
        }

        if(s[i] == 'a') {
            --a;
        } else if(s[i] == 'b') {
            --b;
        } else {
            --c;
        }
    }

    return substrings;
}

void test(string s, int expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numberOfSubstrings(s) << endl;

    cout << endl;
}

int main() {
    test("abcabc", 10);
    test("aaacb", 3);
    test("abc", 1);
    test("aaa", 0);
    test("aabbcc", 4);
    test("cbaacb", 8);

    return 0;
}

