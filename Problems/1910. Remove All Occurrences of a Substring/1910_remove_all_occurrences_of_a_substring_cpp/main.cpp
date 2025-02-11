#include <iostream>

using namespace std;

string removeOccurrences(string s, string part) {
    short n = s.length();
    short nPart = part.length() - 1;

    for(short i = 0; i < n; ++i) {
        if(s[i] == part[nPart] && i >= nPart) {
            if(s.substr(i - nPart, nPart + 1) == part) {
                s.erase(i - nPart, nPart + 1);
                i -= ++nPart;
                n -= nPart--;
            }
        }
    }

    return s;
}

void test(string s, string part, string expected) {
    cout << "String: \"" << s << "\"" << endl;

    cout << "Part: \"" << part << "\"" << endl;

    cout << "Expected: \"" << expected << "\"" << endl;

    cout << "Result: \"" << removeOccurrences(s, part) << "\"" << endl;

    cout << endl;
}

int main() {
    test("daabcbaabcbc", "abc", "dab");
    test("axxxxyyyyb", "xy", "ab");
    test("abababab", "aba", "bb");
    test("aaaaaa", "aa", "");
    test("abcdef", "xyz", "abcdef");
    test("mississippi", "iss", "mippi");

    return 0;
}
