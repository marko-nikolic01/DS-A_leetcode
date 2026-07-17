#include <iostream>

using namespace std;

string rearrangeString(string s, char x, char y) {
    short iY = -1;
    for(short i = s.length() - 1; i > iY; --i) {
        if(s[i] == y) {
            x = s[++iY];
            s[iY] = y;
            s[i++] = x;
        }
    }

    return s;
}

void test(string s, char x, char y, string expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "x: " << "'" << x << "'" << endl;

    cout << "y: " << "'" << y << "'" << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << rearrangeString(s, x, y) << "\"" << endl;

    cout << endl;
}

int main() {
    test("aabc", 'a', 'c', "caba");
    test("dcab", 'd', 'b', "bcad");
    test("axe", 'o', 'x', "xae");
    test("nidlnmpjrm", 'i', 'n', "nndlimpjrm");
    test("ab", 'a', 'b', "ba");
    test("ab", 'b', 'a', "ab");

    return 0;
}
