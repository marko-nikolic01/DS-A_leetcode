#include <iostream>
#include <unordered_map>

using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    unordered_map<char, int> letters;

    int n = magazine.length();
    for(int i = 0; i < n; ++i) {
        if(letters.find(magazine[i]) == letters.end()) {
            letters[magazine[i]] = 1;
        } else {
            letters[magazine[i]]++;
        }
    }

    n = ransomNote.length();
    for(int i = 0; i < n; ++i) {
        if(letters.find(ransomNote[i]) == letters.end() || letters[ransomNote[i]] == 0) {
            return false;
        }
        letters[ransomNote[i]]--;
    }

    return true;
}

void testCanConstruct(string ransomNote, string magazine, bool expected) {
    bool result = canConstruct(ransomNote, magazine);
    cout << "Ransom Note: " << ransomNote << endl;
    cout << "Magazine: " << magazine << endl;
    cout << "Expected: " << (expected ? "true" : "false") << endl;
    cout << "Result: " << (result ? "true" : "false") << endl;
    cout << endl;
}

int main() {
    testCanConstruct("a", "b", false);
    testCanConstruct("aa", "ab", false);
    testCanConstruct("aa", "aab", true);
    testCanConstruct("abc", "aabbcc", true);
    testCanConstruct("", "abc", true);
    testCanConstruct("hello", "hello world", true);

    return 0;
}
