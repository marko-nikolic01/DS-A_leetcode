#include <iostream>

using namespace std;

string makeFancyString(string s) {
    string fancyString = "";

    int n = s.length();
    for(int i = 0; i < n; ++i) {
        fancyString.push_back(s[i]);

        if(++i < n && s[i] == s[i - 1]) {
            fancyString.push_back(s[i]);
        }

        while(i < n && s[i] == s[i - 1]) {
            i++;
        }
        i--;
    }

    return fancyString;
}

void test(string input, string expected) {
    cout << "Input: \"" << input << "\"" << endl;

    cout << "Expected: \"" << expected << "\"" << endl;

    cout << "Result: \"" << makeFancyString(input) << "\"" << endl;

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
