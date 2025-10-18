#include <iostream>
#include <vector>

using namespace std;

void findAndReplacePattern(vector<string>& words, string& pattern, string& letters, vector<short>& isUsed, int& lettersUsed, short& i, short& n, short iWord) {
    short letter;

    lettersUsed = 0;

    for(short j = n; j > -1; --j) {
        letter = pattern[j] - 'a';

        if(isUsed[letter] < iWord) {
            if((lettersUsed & (1 << (words[iWord][j] - 'a'))) > 0) {
                return;
            }

            letters[letter] = words[iWord][j];
            isUsed[letter] = iWord;
            lettersUsed |= 1 << (words[iWord][j] - 'a');
        } else if(letters[letter] != words[iWord][j]) {
            return;
        }
    }

    for(letter = n; letter > -1; --letter) {
        words[i][letter] = words[iWord][letter];
    }

    ++i;
}

vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
    string letters(26, ' ');
    vector<short> isUsed(26, -1);
    int lettersUsed;

    short iWords = 0;
    short n = pattern.size() - 1;
    short nWords = words.size();
    for(short i = 0; i < nWords; ++i) {
        findAndReplacePattern(words, pattern, letters, isUsed, lettersUsed, iWords, n, i);
    }

    words.resize(iWords);

    return words;
}

void printArray(vector<string> array) {
    for(string a : array) {
        cout << "\"" << a << "\"" << " ";
    }
    cout << endl;
}

void test(vector<string> words, string pattern, vector<string> expected) {
    cout << "Words: ";
    printArray(words);

    cout << "Pattern: " << "\"" << pattern << "\"" << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(findAndReplacePattern(words, pattern));

    cout << endl;
}

int main() {
    test({"abc","deq","mee","aqq","dkd","ccc"}, "abb", {"mee","aqq"});
    test({"a","b","c"}, "a", {"a","b","c"});
    test({"xyz","xyy","yyx","yxx"}, "abb", {"xyy","yxx"});
    test({"abc","cba","xyx","yxy","zaz"}, "aba", {"xyx","yxy","zaz"});
    test({"abcd","deed","mnop","xyyx"}, "aabb", {});

    return 0;
}
