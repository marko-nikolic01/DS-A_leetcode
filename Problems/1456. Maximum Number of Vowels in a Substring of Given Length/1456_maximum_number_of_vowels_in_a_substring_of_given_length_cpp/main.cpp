#include <iostream>
#include <vector>

using namespace std;

int maxVowels(string s, int k) {
    vector<bool> isVowel = {
        true, false, false, false, true, false,
        false, false, true, false, false,
        false, false, false, true, false,
        false, false, false, false, true,
        false, false, false, false, false
    };

    int maximumVowels = 0;
    int currentVowels = 0;

    int i;
    for(i = 0; i < k; ++i) {
        if(isVowel[s[i] - 'a']) {
            ++currentVowels;
        }
    }
    maximumVowels = currentVowels;

    int n = s.length();
    for(i; i < n; ++i) {
        if(isVowel[s[i - k] - 'a']) {
            --currentVowels;

            if(isVowel[s[i] - 'a']) {
                ++currentVowels;
            }
        } else if(isVowel[s[i] - 'a'] && ++currentVowels > maximumVowels) {
            maximumVowels = currentVowels;
        }
    }

    return maximumVowels;
}

void runTest(string s, int k, int expected) {
    cout << "s: \"" << s << "\"" << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxVowels(s, k) << endl;

    cout << endl;
}

int main() {
    runTest("abciiidef", 3, 3);
    runTest("aeiou", 2, 2);
    runTest("leetcode", 3, 2);
    runTest("rhythms", 4, 0);
    runTest("aabaa", 3, 2);
    runTest("cbaeiuooo", 5, 5);
    runTest("bbbbb", 2, 0);

    return 0;
}
