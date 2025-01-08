#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void wordBreak(string& s, vector<string>& sentences, string& sentence, unordered_set<string>& dictionary, short position) {
    string word = "";

    short n = s.length();
    while(position < n) {
        word.push_back(s[position++]);

        if(dictionary.find(word) != dictionary.end()) {
            sentence.insert(sentence.end(), word.begin(), word.end());

            if(position < n) {
                sentence.push_back(' ');
                wordBreak(s, sentences, sentence, dictionary, position);
                sentence.pop_back();
            } else {
                sentences.push_back(sentence);
            }

            sentence.resize(sentence.size() - word.size());
        }
    }
}

vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dictionary;
    for(short i = wordDict.size() - 1; i > -1; --i) {
        dictionary.insert(wordDict[i]);
    }

    wordDict = {};
    string sentence = "";

    wordBreak(s, wordDict, sentence, dictionary, 0);

    return wordDict;
}

void printTestCase(string s, vector<string> wordDict, vector<string> expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Word dictionary: ";
    for (string word : wordDict) {
        cout << "\"" << word << "\" ";
    }
    cout << endl;

    cout << "Expected: ";
    for (string e : expected) {
        cout << "\"" << e << "\" ";
    }
    cout << endl;

    cout << "Result:   ";
    for (string result : wordBreak(s, wordDict)) {
        cout << "\"" << result << "\" ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    string s1 = "catsanddog";
    vector<string> wordDict1 = {"cat", "cats", "and", "sand", "dog"};
    vector<string> expected1 = {"cat sand dog", "cats and dog"};
    printTestCase(s1, wordDict1, expected1);

    string s2 = "pineapplepenapple";
    vector<string> wordDict2 = {"apple", "pen", "applepen", "pine", "pineapple"};
    vector<string> expected2 = {"pine apple pen apple", "pine applepen apple", "pineapple pen apple"};
    printTestCase(s2, wordDict2, expected2);

    string s3 = "catsandog";
    vector<string> wordDict3 = {"cats", "dog", "sand", "and", "cat"};
    vector<string> expected3 = {};
    printTestCase(s3, wordDict3, expected3);

    string s4 = "abcd";
    vector<string> wordDict4 = {"a", "abc", "b", "cd"};
    vector<string> expected4 = {"a b cd"};
    printTestCase(s4, wordDict4, expected4);

    string s5 = "applepie";
    vector<string> wordDict5 = {"apple", "pie", "app", "le"};
    vector<string> expected5 = {"app le pie", "apple pie"};
    printTestCase(s5, wordDict5, expected5);

    return 0;
}
