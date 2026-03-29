#include <iostream>

using namespace std;

bool canBeEqual(string s1, string s2) {
    return ((1 << (s1[0] - 'a') | 1 << (s1[2] - 'a')) == (1 << (s2[0] - 'a') | 1 << (s2[2] - 'a'))) && ((1 << (s1[1] - 'a') | 1 << (s1[3] - 'a')) == (1 << (s2[1] - 'a') | 1 << (s2[3] - 'a')));
}

void test(string s1, string s2, bool expected) {
    cout << "String 1: " << s1 << endl;

    cout << "String 2: " << s2 << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (canBeEqual(s1, s2) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test("abcd", "cdab", true);
    test("abcd", "dacb", false);
    test("abcd", "abcd", true);
    test("aabb", "bbaa", true);
    test("abcd", "abdc", false);

    return 0;
}
