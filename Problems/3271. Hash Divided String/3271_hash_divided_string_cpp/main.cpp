#include <iostream>

using namespace std;

string stringHash(string s, int k) {
    short n = s.length();
    short iterations = n / k;
    short character;

    short j;
    short m = 0;
    for(short i = 0; i < iterations; ++i) {
        character = 0;

        for(j = m, m += k; j < m; ++j) {
            character += s[j] - 'a';
        }

        s[i] = character % 26 + 'a';
    }

    s.resize(iterations);

    return s;
}

void test(string s, int k, string expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << stringHash(s, k) << "\"" << endl;

    cout << endl;
}

int main() {
    test("abcd", 2, "bf");
    test("mxz", 3, "i");
    test("zzzz", 2, "yy");
    test("abcdefghijkl", 3, "dmve");
    test("aaaaaaaabbbb", 4, "aae");

    return 0;
}
