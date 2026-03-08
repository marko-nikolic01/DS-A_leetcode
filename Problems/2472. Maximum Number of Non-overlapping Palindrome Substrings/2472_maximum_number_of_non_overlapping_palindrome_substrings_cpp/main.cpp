#include <iostream>

using namespace std;

int maxPalindromes(string s, int k) {
    int result = 0;
    short start = 0;
    short left;
    short right;

    short n = s.length();
    short m = n << 1;
    for(short center = 0; center < m; ++center) {
        left = center >> 1;
        right = left++ + (center & 1) - 1;

        while(--left >= start && ++right < n && s[left] == s[right]) {
            if(right - left + 1 >= k) {
                ++result;
                start = right + 1;

                break;
            }
        }
    }

    return result;
}

void test(string s, int k, int expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxPalindromes(s, k) << endl;

    cout << endl;
}

int main() {
    test("abaccdbbd", 3, 2);
    test("adbcda", 2, 0);
    test("aa", 2, 1);
    test("aaa", 1, 3);
    test("abba", 2, 1);

    return 0;
}
