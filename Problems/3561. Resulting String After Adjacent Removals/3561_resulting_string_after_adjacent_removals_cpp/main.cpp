#include <iostream>

using namespace std;

string resultingString(string s) {
    int iResult = -1;
    short c1;
    short c2;

    int n = s.length();
    for(int i = 0; i < n; ++i) {
        if(iResult > -1) {
            c1 = s[i] - 'a';
            c2 = s[iResult] - 'a';

            if((c1 + 1) % 26 == c2 || (c2 + 1) % 26 == c1) {
                --iResult;
            } else {
                s[++iResult] = s[i];
            }
        } else {
            s[++iResult] = s[i];
        }
    }

    s.resize(++iResult);

    return s;
}

void test(string s, string expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << resultingString(s) << "\"" << endl;

    cout << endl;
}

int main() {
    test("abc", "c");
    test("adcb", "");
    test("zadb", "db");
    test("abz", "z");
    test("aabcc", "acc");

    return 0;
}
