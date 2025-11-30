#include <iostream>

using namespace std;

int maxDistinct(string s) {
    int substrings = 0;
    int letters = 0;
    int letter;

    for(int i = s.length() - 1; i > -1 && substrings < 26; --i) {
        letter = 1 << (s[i] - 'a');

        if((letters & letter) < 1) {
            ++substrings;
            letters |= letter;
        }
    }

    return substrings;
}

void test(string s, int expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxDistinct(s) << endl;

    cout << endl;
}

int main() {
    test("abab", 2);
    test("abcd", 4);
    test("aaaa", 1);
    test("zxyzz", 3);
    test("qwertyqwerty", 6);
    test("abcdefghijklmnopqrstuvwxyz", 26);

    return 0;
}
