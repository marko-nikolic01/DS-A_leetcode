#include <iostream>

using namespace std;

int appendCharacters(string s, string t) {
    int n = s.length();
    int l = t.length();

    int existing = 0;

    for(int i = 0; i < n; ++i) {
        if(s[i] == t[existing]) {
            ++existing;
        }
    }

    return t.size() - existing;
}

void test(string s, string t, int expected) {
    cout << "String 1: " << s << endl;

    cout << "String 2: " << t << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << appendCharacters(s, t) << endl;

    cout << endl;
}

int main() {
    test("abc", "abc", 0);
    test("abc", "abcd", 1);
    test("abc", "d", 1);
    test("abc", "ab", 0);
    test("a", "aaa", 2);
    test("xyz", "xyzxyz", 3);
    test("hello", "hel", 0);

    return 0;
}
