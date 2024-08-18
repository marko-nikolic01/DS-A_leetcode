#include <iostream>
#include <string>

using namespace std;

bool repeatedSubstringPattern(string s) {
    if(s.size() < 2) {
        return false;
    }

    string s1 = s + s;

    string s2 = s1.substr(1, s1.size() - 2);

    return s2.find(s) != string::npos;
}

void test(const string& s, bool expected) {
    bool result = repeatedSubstringPattern(s);
    cout << "String: \"" << s << "\", Expected: " << (expected ? "true" : "false") << ", Result: " << (result ? "true" : "false") << endl << endl;
}

int main() {
    test("abab", true);
    test("aba", false);
    test("abcabcabcabc", true);
    test("a", false);
    test("abcdabcd", true);
    test("xyzxyzxyz", true);
    test("xyzxyzxyzxyz", true);
    test("abac", false);

    return 0;
}
