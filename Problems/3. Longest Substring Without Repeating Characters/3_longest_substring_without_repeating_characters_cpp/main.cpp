#include <iostream>
#include <unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int max = 0;
    unordered_map<char, int> letters;

    int i = 0;
    for(int j = 0; j < s.length(); ++j) {
        if(letters.find(s[j]) == letters.end() || letters[s[j]] < i) {
            letters[s[j]] = j;
            if(max < j - i + 1) {
                max = j - i + 1;
            }
        } else {
            i = letters[s[j]] + 1;
            letters[s[j]] = j;
        }
    }

    return max;
}

void runTests() {
    cout << "Test case 1: " << lengthOfLongestSubstring("") << " (Expected: 0)" << endl;

    cout << "Test case 2: " << lengthOfLongestSubstring("a") << " (Expected: 1)" << endl;

    cout << "Test case 3: " << lengthOfLongestSubstring("abcdef") << " (Expected: 6)" << endl;

    cout << "Test case 4: " << lengthOfLongestSubstring("bbbbb") << " (Expected: 1)" << endl;

    cout << "Test case 5: " << lengthOfLongestSubstring("abcabcbb") << " (Expected: 3)" << endl;

    cout << "Test case 6: " << lengthOfLongestSubstring("pwwkew") << " (Expected: 3)" << endl;

    cout << "Test case 7: " << lengthOfLongestSubstring("dvdf") << " (Expected: 3)" << endl;
}

int main() {
    runTests();
    return 0;
}
