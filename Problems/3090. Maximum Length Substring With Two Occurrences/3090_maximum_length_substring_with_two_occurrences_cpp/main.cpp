#include <iostream>
#include <vector>

using namespace std;

int maximumLengthSubstring(string s) {
    short length = 1;
    vector<short> letters(26, 0);

    short right = s.length();
    for(short left = --right; left > -1; --left) {
        if(++letters[s[left] - 'a'] < 3) {
            if(right - left > length) {
                length = right - left;
            }
        } else {
            while(s[right] != s[left]) {
                --letters[s[right--] - 'a'];
            }

            --letters[s[right--] - 'a'];
        }
    }

    return ++length;
}

void test(string s, int expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maximumLengthSubstring(s) << endl;

    cout << endl;
}

int main() {
    test("bcbbbcba", 4);
    test("aaaa", 2);
    test("abcabcabc", 6);
    test("aabbcc", 6);
    test("abacadaeaf", 5);

    return 0;
}
