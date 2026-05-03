#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

int numSpecialEquivGroups(vector<string>& words) {
    unordered_set<string> groups;

    short iWord;
    short nWord = words[0].length();
    for(short i = words.size() - 1; i > -1; --i) {
        for(iWord = 1; iWord < nWord; iWord += 2) {
            words[i][iWord] -= 32;
        }

        sort(words[i].begin(), words[i].end());
        groups.insert(words[i]);
    }

    return groups.size();
}

void printArray(vector<string> array) {
    for(string a : array) {
        cout << "\"" << a << "\"" << " ";
    }
    cout << endl;
}

void test(vector<string> words, int expected) {
    cout << "Words: ";
    printArray(words);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numSpecialEquivGroups(words) << endl;

    cout << endl;
}

int main() {
    test({"abcd", "cdab", "cbad", "xyzz", "zzxy", "zzyx"}, 3);
    test({"abc", "acb", "bac", "bca", "cab", "cba"}, 3);
    test({"a", "b", "c", "a"}, 3);
    test({"abcd", "abcd"}, 1);
    test({"ab", "ba", "cd", "dc"}, 4);

    return 0;
}
