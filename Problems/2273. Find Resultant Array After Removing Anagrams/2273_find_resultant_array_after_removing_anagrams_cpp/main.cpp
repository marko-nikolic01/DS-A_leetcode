#include <iostream>
#include <vector>

using namespace std;

vector<string> removeAnagrams(vector<string>& words) {
    int n = words.size();
    vector<vector<short>> letters(n, vector<short>(26, 0));
    vector<short> validWords(1, 0);

    short i;
    for(i = words[0].length() - 1; i > -1; --i) {
        ++letters[0][words[0][i] - 'a'];
    }

    short j;
    for(i = 1; i < n; ++i) {
        for(j = words[i].length() - 1; j > -1; --j) {
            ++letters[i][words[i][j] - 'a'];
        }

        for(j = 25; j > -1; --j) {
            if(letters[i][j] != letters[validWords.back()][j]) {
                break;
            }
        }

        if(j > -1) {
            validWords.push_back(i);
        }
    }

    i = 0;
    n = validWords.size();
    while(i < n && validWords[i] == i) {
        ++i;
    }

    short m;
    for(i; i < n; ++i) {
        words[i].resize(0);

        m = words[validWords[i]].length();
        for(j = 0; j < m; ++j) {
            words[i].push_back(words[validWords[i]][j]);
        }
    }

    words.resize(n);

    return words;
}

void printArray(vector<string> array) {
    for(string a : array) {
        cout << "\"" << a << "\"" << " ";
    }
    cout << endl;
}

void test(vector<string> words, vector<string> expected) {
    cout << "Words: ";
    printArray(words);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(removeAnagrams(words));

    cout << endl;
}

int main() {
    test({"abba", "baba", "bbaa", "cd", "cd"}, {"abba", "cd"});
    test({"a", "b", "c", "d", "e"}, {"a", "b", "c", "d", "e"});
    test({"aa", "aa", "aa", "aa"}, {"aa"});
    test({"listen", "silent", "enlist", "google", "elgoog"}, {"listen", "google"});
    test({"abc", "acb", "bac", "bca", "cab", "cba", "xyz"}, {"abc", "xyz"});

    return 0;
}
