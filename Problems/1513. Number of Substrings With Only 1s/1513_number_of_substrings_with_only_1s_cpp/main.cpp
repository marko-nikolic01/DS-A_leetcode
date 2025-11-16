#include <iostream>

using namespace std;

int numSub(string s) {
    int substrings = 0;
    int streak = 0;

    for(int i = s.length() - 1; i > -1; --i) {
        if(s[i] > '0') {
            substrings = (substrings + ++streak) % 1000000007;
        } else {
            streak = 0;
        }
    }

    return substrings;
}

void test(string s, int expected) {
    cout << "String: " << s << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numSub(s) << endl;

    cout << endl;
}

int main() {
    test("0110111", 9);
    test("101", 2);
    test("111111", 21);
    test("0000", 0);
    test("11011101111", 19);

    return 0;
}
