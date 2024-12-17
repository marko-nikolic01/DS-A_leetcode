#include <iostream>
#include <vector>

using namespace std;

string repeatLimitedString(string s, int repeatLimit) {
    vector<int> letters(26, 0);

    for(int i = s.length() - 1; i > -1; --i) {
        ++letters[s[i] - 97];
    }

    int length = 0;
    int returnLetter = -1;
    for(int i = 25; i > -1; --i) {
        if(returnLetter > -1 && letters[i] > 0) {
            s[length++] = i + 97;
            --letters[i];
            i = returnLetter + 1;
            returnLetter = -1;
            continue;
        }

        int limit = repeatLimit;
        while(letters[i] > 0 && limit > 0) {
            s[length++] = i + 97;
            --letters[i];
            --limit;
        }

        if(letters[i] > 0) {
            returnLetter = i;
        }
    }

    s.resize(length);

    return s;
}

void test(string s, int repeatLimit, string expected) {
    cout << "Input: " << "\"" << s << "\"" << endl;

    cout << "Repeat limit: " << repeatLimit << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << repeatLimitedString(s, repeatLimit) << "\"" << endl;

    cout << endl;
}

int main() {
    test("aabbcc", 2, "ccbbaa");
    test("aabbcc", 1, "cbcba");
    test("zzzxy", 3, "zzzyx");
    test("aaaaaaa", 2, "aa");
    test("abcabc", 3, "ccbbaa");
    test("aaaabbbbcccc", 1, "cbcbcbcba");
    test("xyzxyzxyz", 2, "zzyzyyxx");
    test("a", 1, "a");
    test("aaa", 1, "a");
    test("ab", 2, "ba");

    return 0;
}
