#include <iostream>

using namespace std;

bool canConstruct(string s, int k) {
    int letters = 0;
    short singles = 0;

    int n = s.length();
    for(int i = 0; i < n; ++i) {
        letters ^= 1 << (s[i] - 'a');
        if((letters & (1 << (s[i] - 'a'))) > 0) {
            ++singles;
        } else {
            --singles;
        }
    }

    return singles > k ? false : n >= k;
}

void test(string s, int k, bool expected) {
    cout << "String: \"" << s << "\"" << endl;

    cout << "k: " << k <<  endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (canConstruct(s, k) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test("annabelle", 2, true);
    test("leetcode", 3, false);
    test("true", 4, true);
    test("aabb", 1, true);
    test("abc", 3, true);
    test("abc", 4, false);
    test("z", 1, true);

    return 0;
}
