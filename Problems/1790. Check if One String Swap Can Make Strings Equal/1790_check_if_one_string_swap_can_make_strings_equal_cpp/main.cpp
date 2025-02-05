#include <iostream>

using namespace std;

bool areAlmostEqual(string s1, string s2) {
    short wrongLetterIndex = -1;

    short i = s1.length();
    while(--i > -1) {
        if(s1[i] != s2[i]) {
            wrongLetterIndex = i;
            break;
        }
    }

    while(--i > -1) {
        if(s1[i] != s2[i]) {
            if(s1[i] == s2[wrongLetterIndex] && s1[wrongLetterIndex] == s2[i]) {
                wrongLetterIndex = -1;
                break;
            }
            return false;
        }
    }

    while(--i > -1) {
        if(s1[i] != s2[i]) {
            return false;
        }
    }

    return wrongLetterIndex < 0;
}

void test(string s1, string s2, bool expected) {
    cout << "String 1: " << "\"" << s1 << "\"" << endl;

    cout << "String 2: " << "\"" << s2 << "\"" << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (areAlmostEqual(s1, s2) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test("bank", "kanb", true);
    test("attack", "defend", false);
    test("kelb", "kelb", true);
    test("abcd", "abdc", true);
    test("abcd", "dcba", false);
    test("a", "a", true);

    return 0;
}
