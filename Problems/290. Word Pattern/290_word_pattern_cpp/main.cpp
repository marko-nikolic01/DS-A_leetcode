#include <iostream>
#include <unordered_map>

using namespace std;

bool wordPattern(string pattern, string s) {
    unordered_map<string, char> dictionary;
    unordered_map<char, string> reverseDictionary;

    s += ' ';

    int j = 0;
    string word = "";
    string patternResult = "";

    int n = s.size();
    for(int i = 0; i < n; ++i) {
        if(s[i] == ' ') {
            if(dictionary.find(word) == dictionary.end() && reverseDictionary.find(pattern[j]) == reverseDictionary.end()) {
                dictionary[word] = pattern[j];
                reverseDictionary[pattern[j]] = word;
            } else if(dictionary[word] != pattern[j] || reverseDictionary[pattern[j]] != word) {
                return false;
            }
            word = "";
            j++;
        } else {
            word += s[i];
        }
    }

    return j == pattern.size();
}

int main() {
    string pattern1 = "abba";
    string s1 = "dog cat cat dog";
    cout << "Pattern: " << pattern1 << endl;
    cout << "Word: " << s1 << endl;
    cout << "Result: " << (wordPattern(pattern1, s1) ? "true" : "false") << endl;
    cout << endl;

    string pattern2 = "abba";
    string s2 = "dog cat cat fish";
    cout << "Pattern: " << pattern2 << endl;
    cout << "Word: " << s2 << endl;
    cout << "Result: " << (wordPattern(pattern2, s2) ? "true" : "false") << endl;
    cout << endl;

    string pattern3 = "aaaa";
    string s3 = "dog cat cat dog";
    cout << "Pattern: " << pattern3 << endl;
    cout << "Word: " << s3 << endl;
    cout << "Result: " << (wordPattern(pattern3, s3) ? "true" : "false") << endl;
    cout << endl;

    string pattern4 = "abba";
    string s4 = "dog dog dog dog";
    cout << "Pattern: " << pattern4 << endl;
    cout << "Word: " << s4 << endl;
    cout << "Result: " << (wordPattern(pattern4, s4) ? "true" : "false") << endl;
    cout << endl;

    string pattern5 = "abc";
    string s5 = "dog cat fish";
    cout << "Pattern: " << pattern5 << endl;
    cout << "Word: " << s5 << endl;
    cout << "Result: " << (wordPattern(pattern5, s5) ? "true" : "false") << endl;

    return 0;
}
