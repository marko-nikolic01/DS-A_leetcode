#include <iostream>

using namespace std;

int firstMatchingIndex(string s) {
    short n = s.length() - 1;
    for(short i = 0; i <= n - i; ++i) {
        if(s[i] == s[n - i]) {
            return i;
        }
    }

    return -1;
}

void test(string s, int expected) {
    cout << "String: " << s << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << firstMatchingIndex(s) << endl;

    cout << endl;
}

int main() {
    test("abcacbd", 1);
    test("abc", 1);
    test("abcdab", -1);
    test("a", 0);
    test("aa", 0);

    return 0;
}
