#include <iostream>

using namespace std;

int minimumDeletions(string s) {
    int deletions;
    int a = 0;
    int b = 0;

    int i;
    int n = s.length();
    for(i = 0; i < n; ++i) {
        if(s[i] < 'b') {
            ++a;
        } else {
            ++b;
        }
    }

    deletions = min(a, b);
    b = 0;

    for(i = 0; i < n && a > 0; ++i) {
        if(s[i] < 'b') {
            --a;
        } else {
            ++b;
        }

        if(a + b < deletions) {
            deletions = a + b;
        }
    }

    return deletions;
}

void test(string s, int expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minimumDeletions(s) << endl;

    cout << endl;
}

int main() {
    test("aababbab", 2);
    test("bbaaaaabb", 2);
    test("aaaa", 0);
    test("bbbb", 0);
    test("abababab", 3);

    return 0;
}
