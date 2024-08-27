#include <iostream>
#include <queue>

using namespace std;

bool rotateString(string s, string goal) {
    queue<char> rotated;

    int n = s.length();
    for(int i = 0; i < n; ++i) {
        rotated.push(s[i]);
    }

    for(int i = 0; i < n; ++i) {
        bool isSame = true;

        char letter = rotated.front();
        rotated.pop();

        if(letter != goal[0]) {
            isSame = false;
        }

        for(int j = 1; j < n; ++j) {
            rotated.push(rotated.front());

            if(rotated.front() != goal[j]) {
                isSame = false;
            }

            rotated.pop();
        }

        rotated.push(letter);

        if(isSame) {
            return true;
        }
    }

    return false;
}

void runTest(string input, string goal, bool expected) {
    cout << "Input: \"" << input << "\"" << endl;

    cout << "Goal: \"" << goal << "\"" << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (rotateString(input, goal) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    runTest("abcde", "cdeab", true);
    runTest("abcde", "abced", false);
    runTest("aa", "aa", true);
    runTest("abcd", "abcd", true);
    runTest("abc", "bca", true);
    runTest("abc", "cab", true);
    runTest("abc", "abc", true);
    runTest("abcde", "fghij", false);
    return 0;
}
