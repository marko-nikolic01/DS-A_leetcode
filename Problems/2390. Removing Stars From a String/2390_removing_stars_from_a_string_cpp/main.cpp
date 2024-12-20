#include <iostream>

using namespace std;

string removeStars(string s) {
    int current = 0;

    int n = s.length();
    for(int i = 0; i < n; ++i) {
        if(s[i] == '*') {
            --current;
        } else {
            s[current++] = s[i];
        }
    }

    s.resize(current);

    return s;
}

void test(string s, string expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << removeStars(s) << "\"" << endl;

    cout << endl;
}

int main() {
    test("leet**cod*e", "lecoe");
    test("abcd", "abcd");
    test("ab*c", "ac");
    test("a*b*c*", "");
    test("a*b*c", "c");
    test("erase*****", "");

    return 0;
}
