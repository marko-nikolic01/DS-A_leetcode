#include <iostream>
#include <vector>

using namespace std;

vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
    short iSubsequence = 1;
    bool next = !(groups[0] > 0);

    short iWord;
    short nWord;
    short n = groups.size();
    for(short i = 1; i < n; ++i) {
        if(next == (groups[i] > 0)) {
            if(i > iSubsequence) {
                words[iSubsequence].resize(0);

                nWord = words[i].length();
                for(iWord = 0; iWord < nWord; ++iWord) {
                    words[iSubsequence].push_back(words[i][iWord]);
                }
            }

            next = !next;
            ++iSubsequence;
        }
    }

    words.resize(iSubsequence);

    return words;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void printArray(vector<string> array) {
    for(string a : array) {
        cout << "\"" << a << "\"" << " ";
    }
    cout << endl;
}

void test(vector<string> words, vector<int> groups, vector<string> expected) {
    cout << "Words: ";
    printArray(words);

    cout << "Groups: ";
    printArray(groups);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(getLongestSubsequence(words, groups));

    cout << endl;
}

int main() {
    test({"e", "a", "b"}, {0, 0, 1}, {"e", "b"});
    test({"a", "b", "c", "d"}, {1, 0, 1, 1}, {"a", "b", "c"});
    test({"c", "w", "h", "s"}, {0, 0, 0, 1}, {"c", "s"});
    test({"d", "g"}, {0, 1}, {"d", "g"});
    test({"x", "y", "z", "a", "b", "c"}, {1, 1, 0, 1, 0, 1}, {"x", "z", "a", "b", "c"});
    test({"a", "b", "c"}, {0, 0, 0}, {"a"});
    test({"x", "y", "z"}, {1, 1, 1}, {"x"});

    return 0;
}
