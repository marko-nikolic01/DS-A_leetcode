#include <iostream>
#include <unordered_set>

using namespace std;

int longestPalindrome(string s) {
    int length = 0;

    unordered_set<char> letters;
    int n = s.length();
    for(int i = 0; i < n; ++i) {
        if(letters.find(s[i]) == letters.end()) {
            letters.insert(s[i]);
        } else {
            letters.erase(s[i]);
            length += 2;
        }
    }

    return letters.empty() ? length : ++length;
}

void runTestCase(string s, int expected) {
    int result = longestPalindrome(s);
    cout << "String: \"" << s << "\" | Expected: " << expected << " | Result: " << result << endl << endl;
}

int main() {
    runTestCase("abccccdd", 7);
    runTestCase("a", 1);
    runTestCase("bb", 2);
    runTestCase("abc", 1);
    runTestCase("aabbcc", 6);

    return 0;
}
