#include <iostream>

using namespace std;

int longestPalindrome(string s, int left, int right) {
    int n = s.length();

    while(left >= 0 && right < n && s[left] == s[right]) {
        --left;
        ++right;
    }

    return --right - left;
}

string longestPalindrome(string s) {
    if (s.empty()) {
        return "";
    }

    int start = 0;
    int end = 0;
    int odd;
    int even;
    int maximumLength;

    int n = s.length();
    for(int i = 0; i < n; ++i) {
        odd = longestPalindrome(s, i, i);
        even = longestPalindrome(s, i, i + 1);
        maximumLength = max(odd, even);

        if(maximumLength > end - start) {
            start = i - (maximumLength - 1) / 2;
            end = i + maximumLength / 2;
        }
    }

    return s.substr(start, end - start + 1);
}

void test(string s, string expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << longestPalindrome(s) << "\"" << endl;

    cout << endl;
}

int main() {
    test("babad", "aba");
    test("cbbd", "bb");
    test("a", "a");
    test("racecar", "racecar");
    test("aacabdkacaa", "aca");

    return 0;
}
