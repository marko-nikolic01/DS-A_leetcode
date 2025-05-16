#include <iostream>
#include <vector>

using namespace std;

bool getWordsInLongestSubsequence(vector<string>& words, short i1, short i2) {
    short n = words[i1].length();

    if(n != words[i2].length()) {
        return false;
    }

    bool difference = false;

    for(--n; n > -1; --n) {
        if(words[i1][n] != words[i2][n]) {
            if(difference) {
                return false;
            }
            difference = true;;
        }
    }

    return difference;
}

vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
    short n = words.size();
    vector<short> lengths(n, 1);
    vector<short> next(n, -1);
    short maxLengthIndex = --n;

    short i;
    for(n; n > -1; --n) {
        for(i = n - 1; i > -1; --i) {
            if(groups[n] != groups[i] && lengths[n] + 1 > lengths[i] && getWordsInLongestSubsequence(words, n, i)) {
                lengths[i] = lengths[n] + 1;
                next[i] = n;
            }
        }

        if(lengths[n] > lengths[maxLengthIndex]) {
            maxLengthIndex = n;
        }
    }

    n = lengths[maxLengthIndex];

    i = -1;
    short j;
    short k;
    while(++i < n) {
        if(maxLengthIndex > i) {
            words[i].resize(0);

            k = words[maxLengthIndex].length();
            for(j = 0; j < k; ++j) {
                words[i].push_back(words[maxLengthIndex][j]);
            }
        }

        maxLengthIndex = next[maxLengthIndex];
    }

    words.resize(n);

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

    cout << "Result:   ";
    printArray(getWordsInLongestSubsequence(words, groups));

    cout << endl;
}

int main() {
    test({"bab", "dab", "cab"}, {1, 2, 2}, {"bab", "cab"});
    test({"a", "b", "c", "d"}, {1, 2, 3, 4}, {"a", "b", "c", "d"});
    test({"ab", "ac", "ad"}, {1, 1, 1}, {"ad"});
    test({"abc", "def", "ghi"}, {1, 2, 3}, {"ghi"});
    test({"abc", "bbc", "bcc", "bcd"}, {1, 2, 3, 4}, {"abc", "bbc", "bcc", "bcd"});

    return 0;
}
