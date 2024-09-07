#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool wordBreak(string s, unordered_set<string>& wordSet, unordered_set<int>& solved, int start) {
    int n = s.length();
    if(start == n) {
        return true;
    }

    string word = "";

    for(int i = start; i < n; ++i) {
        word += s[i];

        if(wordSet.find(word) != wordSet.end()) {
            if(solved.find(i) == solved.end()) {
                solved.insert(i);
                if(wordBreak(s, wordSet, solved, i + 1)) {
                    return true;
                }
            }
        }
    }

    return false;
}

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wordSet;

    unordered_set<int> solved;

    for(int i = wordDict.size() - 1; i > -1; --i) {
        wordSet.insert(wordDict[i]);
    }

    return wordBreak(s, wordSet, solved, 0);
}

void runTest(string s, vector<string>& wordDict, bool expected) {
    cout << "Input: " << s << endl;

    cout << "Words: [ ";
    for (const string& word : wordDict) {
        cout << word << " ";
    }
    cout << "]" << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result:   " << (wordBreak(s, wordDict) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    vector<string> words1 = {"apple", "pen"};
    vector<string> words2 = {"cats", "dog", "sand", "and", "cat"};
    vector<string> words3 = {"leet", "code"};

    runTest("applepenapple", words1, true);
    runTest("catsandog", words2, false);
    runTest("leetcode", words3, true);

    return 0;
}
