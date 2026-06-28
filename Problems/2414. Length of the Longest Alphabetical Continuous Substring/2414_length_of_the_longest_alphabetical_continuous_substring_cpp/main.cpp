#include <iostream>

using namespace std;

int longestContinuousSubstring(string s) {
    short length = 1;
    short currentLength = 1;

    for(int i = s.length() - 1; i > -1; --i) {
        if(s[i] != s[i + 1] - 1) {
            currentLength = 1;
        } else if(++currentLength > length) {
            length = currentLength;
        }
    }

    return length;
}

void test(string s, int expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << longestContinuousSubstring(s) << endl;

    cout << endl;
}

int main() {
    test("abacaba", 2);
    test("abcde", 5);
    test("z", 1);
    test("zyxwvutsrqponmlkjihgfedcba", 1);
    test("abcxyzde", 3);
    test("abcdefghijklmnopqrstuvwxyz", 26);

    return 0;
}
