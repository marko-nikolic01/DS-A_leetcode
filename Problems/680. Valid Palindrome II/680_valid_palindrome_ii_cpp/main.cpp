#include <iostream>
#include <vector>

using namespace std;

bool validPalindrome(string s, int a, int b, bool skipped) {
    while(a < b) {
        if(s[a] == s[b]) {
            a++;
            b--;
        } else if(!skipped) {
            return validPalindrome(s, a + 1, b, true) || validPalindrome(s, a, b - 1, true);
        } else {
            return false;
        }
    }

    return true;
}

bool validPalindrome(string s) {
    return validPalindrome(s, 0, s.length() - 1, false);
}

void printBool(bool value) {
    cout << (value ? "true" : "false");
}

int main() {
    vector<string> testCases = {
        "abca",
        "racecar",
        "deified",
        "abcdef",
        "abccbfa",
        "abcdcab",
        "a",
        "ab",
        ""
    };

    vector<bool> expectedResults = {true, true, true, false, true, false, true, true, true};

    for (int i = 0; i < testCases.size(); ++i) {
        cout << "Test case " << i + 1 << ":" << endl;
        cout << "Input: \"" << testCases[i] << "\"" << endl;

        cout << "Expected: ";
        printBool(expectedResults[i]);
        cout << endl;

        cout << "Result: ";
        printBool(validPalindrome(testCases[i]));
        cout << endl;

        cout << endl;
    }

    return 0;
}
