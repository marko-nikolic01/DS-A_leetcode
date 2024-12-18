#include <iostream>

using namespace std;

long long countSubstrings(string s, char c) {
    long charCount = 0;

    for(int i = s.length(); i > -1; --i) {
        if(s[i] == c) {
            ++charCount;
        }
    }

    return charCount++ * charCount / 2;
}

void test(string s, char c, long long expected) {
    cout << "String: \"" << s << "\"" << endl;

    cout << "Character: '" << c  << "'" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countSubstrings(s, c) << endl;

    cout << endl;
}

int main() {
    test("abcabc", 'a', 3);
    test("aaaa", 'a', 10);
    test("abcde", 'f', 0);
    test("abacadaeaf", 'a', 15);
    test("xyzzzz", 'z', 10);
    test("a", 'a', 1);
    test("a", 'z', 0);

    return 0;
}
