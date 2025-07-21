#include <iostream>

using namespace std;

string makeFancyString(string s) {
    int iFancy = 0;

    int n = s.size();
    for(int i = 0; i < n; ++i) {
        s[iFancy++] = s[i];

        if(++i < n && s[i - 1] == s[i]) {
            s[iFancy++] = s[i++];

            while(i < n && s[i - 1] == s[i]) {
                ++i;
            }
        }

        --i;
    }

    s.resize(iFancy);

    return s;
}

void test(string input, string expected) {
    cout << "Input: " << "\"" << input << "\"" << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << makeFancyString(input) << "\"" << endl;

    cout << endl;
}

int main() {
    test("aaabaaaa", "aabaa");
    test("leeetcode", "leetcode");
    test("aab", "aab");
    test("a", "a");
    test("aaa", "aa");
    test("aaaabbbbcccc", "aabbcc");
    test("aaabbbaaabb", "aabbaabb");

    return 0;
}
