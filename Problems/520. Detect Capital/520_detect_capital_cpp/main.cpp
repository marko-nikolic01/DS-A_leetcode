#include <iostream>

using namespace std;

bool detectCapitalUse(string word) {
    int n = word.length();

    if(n == 1) {
        return true;
    }

    bool lowercase = word[0] > 96 || word[1] > 96;

    for(--n; n > 0; --n) {
        if(lowercase && word[n] < 91) {
            return false;
        } else if(!lowercase && word[n] > 96) {
            return false;
        }
    }

    return true;
}

void runTest(string word, bool expected) {
    bool result = detectCapitalUse(word);
    cout << "Word: " << word << endl;
    cout << "Expected: " << (expected ? "true" : "false") << endl;
    cout << "Result: " << (result ? "true" : "false") << endl << endl;
}

int main() {
    runTest("USA", true);
    runTest("leetcode", true);
    runTest("Google", true);
    runTest("FlaG", false);
    runTest("HeLLo", false);
    runTest("a", true);
    runTest("A", true);


    return 0;
}
