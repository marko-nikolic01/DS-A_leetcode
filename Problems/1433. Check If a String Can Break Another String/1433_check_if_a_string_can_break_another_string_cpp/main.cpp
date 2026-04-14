#include <iostream>
#include <algorithm>

using namespace std;

bool checkIfCanBreak(string& s1, string& s2, int i) {
    while(i > -1) {
        if(s1[i] < s2[i--]) {
            return false;
        }
    }

    return true;
}

bool checkIfCanBreak(string s1, string s2) {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    int i = s1.size() - 1;
    while(i > 0 && s1[i] == s2[i]) {
        --i;
    }

    return s1[i] < s2[i] ? checkIfCanBreak(s2, s1, i) : checkIfCanBreak(s1, s2, i);
}

void test(string s1, string s2, bool expected) {
    cout << "String 1: " << "\"" << s1 << "\"" << endl;

    cout << "String 2: " << "\"" << s2 << "\"" << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (checkIfCanBreak(s1, s2) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test("abc", "xya", true);
    test("abe", "acd", false);
    test("leetcodee", "interview", true);
    test("aabb", "baba", true);
    test("z", "a", true);

    return 0;
}
