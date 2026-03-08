#include <iostream>

using namespace std;

bool checkOnesSegment(string s) {
    short n = s.length() - 1;
    for(short i = 1; i < n; ++i) {
        if(s[i] < '1' && s[i + 1] > '0') {
            return false;
        }
    }

    return true;
}

void test(string s, bool expected) {
    cout << "String: " << s << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (checkOnesSegment(s) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test("1001", false);
    test("110", true);
    test("1", true);
    test("10", true);
    test("1111", true);
    test("111000111000111000", false);

    return 0;
}
