#include <iostream>

using namespace std;

int countHomogenous(string s) {
    int substrings = 1;
    int streak = 1;

    for(int i = s.length() - 2; i > -1; --i) {
        if(s[i] == s[i + 1]) {
            substrings = (substrings + ++streak) % 1000000007;
        } else {
            substrings = ++substrings % 1000000007;
            streak = 1;
        }
    }

    return substrings;
}

void test(string s, int expected) {
    cout << "String: " << s << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countHomogenous(s) << endl;

    cout << endl;
}

int main() {
    test("abbcccaa", 13);
    test("xy", 2);
    test("zzzzz", 15);
    test("a", 1);
    test("aaabbaa", 12);

    return 0;
}
