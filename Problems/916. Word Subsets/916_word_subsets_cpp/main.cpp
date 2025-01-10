#include <iostream>
#include <vector>

using namespace std;

vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    vector<short> letters2(26, 0);

    vector<short> letters(26);

    for(short i = words2.size() - 1; i > -1; --i) {
        letters = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        for(short j = words2[i].length() - 1; j > -1; --j) {
            if(++letters[words2[i][j] - 'a'] > letters2[words2[i][j] - 'a']) {
                letters2[words2[i][j] - 'a'] = letters[words2[i][j] - 'a'];
            }
        }
    }

    short resultN = 0;

    short n = words1.size();
    for(short i = 0; i < n; ++i) {
        letters = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        for(short j = words1[i].length() - 1; j > -1; --j) {
            ++letters[words1[i][j] - 'a'];
        }

        short j = 0;
        for(j; j < 26; ++j) {
            if(letters[j] < letters2[j]) {
                break;
            }
        }

        if(j == 26) {
            words1[resultN++] = words1[i];
        }
    }

    words1.resize(resultN);

    return words1;
}

void runTestCase(vector<string> words1, vector<string> words2, vector<string> expected) {
    cout << "Words 1: ";
    for(string word : words1) {
        cout << "\"" << word << "\" ";
    }
    cout << endl;

    cout << "Words 2: ";
    for(string word : words2) {
        cout << "\"" << word << "\" ";
    }
    cout << endl;

    cout << "Expected: ";
    for(string e : expected) {
        cout << "\"" << e << "\" ";
    }
    cout << endl;

    cout << "Result: ";
    for(string result : wordSubsets(words1, words2)) {
        cout << "\"" << result << "\" ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    runTestCase({"amazon", "apple", "facebook", "google", "leetcode"}, {"e", "o"}, {"facebook", "google", "leetcode"});
    runTestCase({"amazon", "apple", "facebook", "google", "leetcode"}, {"l", "e"}, {"apple", "google", "leetcode"});
    runTestCase({"amazon", "apple", "facebook", "google", "leetcode"}, {"a"}, {"amazon", "apple", "facebook"});
    runTestCase({"amazon", "apple", "facebook", "google", "leetcode"}, {"oo"}, {"facebook", "google"});
    runTestCase({"amazon", "apple", "facebook", "google", "leetcode"}, {"x"}, {});
    runTestCase({"amazon", "apple", "facebook", "google", "leetcode"}, {"e", "l", "o"}, {"google", "leetcode"});
    runTestCase({"hello", "world", "warrior"}, {"w", "r", "l"}, {"world"});

    return 0;
}
