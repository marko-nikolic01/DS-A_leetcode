#include <iostream>
#include <vector>

using namespace std;

bool checkStrings(vector<int>& letters, string& s1, string& s2, int i) {
    for(i; i > -1; i -= 2) {
        ++letters[s1[i] - 'a'];
        --letters[s2[i] - 'a'];
    }

    for(i = 0; i < 26; ++i) {
        if(letters[i] != 0) {
            return false;
        }
    }

    return true;
}

bool checkStrings(string s1, string s2) {
    vector<int> letters(26, 0);
    int n = s1.length();

    return checkStrings(letters, s1, s2, --n) && checkStrings(letters, s1, s2, --n);
}

void test(string s1, string s2, bool expected) {
    cout << "String 1: " << "\"" << s1 << "\"" << endl;

    cout << "String 2: " << "\"" << s2 << "\"" << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (checkStrings(s1, s2) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test("abcdba", "cabdab", true);
    test("abe", "bea", false);
    test("abc", "abc", true);
    test("abcd", "badc", false);
    test("abcdef", "cdaefb", false);

    return 0;
}
