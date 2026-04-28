#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
    unordered_map<int, int> wordLetters;
    int letters;

    int i;
    int j;
    for(i = words.size() - 1; i > -1; --i) {
        letters = 0;

        for(j = words[i].length() - 1; j > -1; --j) {
            letters |= 1 << (words[i][j] - 'a');
        }

        ++wordLetters[letters];
    }

    i = puzzles.size();
    vector<int> validWords(i, 0);

    unordered_map<int, int>::iterator it;
    while(--i > -1) {
        letters = 0;

        for(j = puzzles[i].length() - 1; j > -1; --j) {
            letters |= 1 << (puzzles[i][j] - 'a');
        }

        for(it = wordLetters.begin(); it != wordLetters.end(); ++it) {
            if((letters & it->first) == it->first && ((1 << (puzzles[i][0] - 'a')) & it->first) > 0) {
                validWords[i] += it->second;
            }
        }
    }

    return validWords;
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

void test(vector<string> words, vector<string> puzzles, vector<int> expected) {
    cout << "Words: ";
    printArray(words);

    cout << "Puzzles: ";
    printArray(puzzles);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(findNumOfValidWords(words, puzzles));

    cout << endl;
}

int main() {
    test({"aaaa", "asas", "able", "ability", "actt", "actor", "access"}, {"aboveyz", "abrodyz", "abslute", "absoryz", "actresz", "gaswxyz"}, {1, 1, 3, 2, 4, 0});
    test({"apple", "pleas", "please"}, {"aelwxyz", "aelpxyz", "aelpsxy", "saelpxy", "xaelpsy"}, {0, 1, 3, 2, 0});
    test({"a", "b", "c"}, {"abcdefg", "bcdefga", "cdefgab"}, {1, 1, 1});
    test({"xyz", "zzz", "zyx"}, {"xyzabcd", "zyxabcd"}, {2, 3});
    test({"hello", "world"}, {"hxyzabc", "wxyzabc"}, {0, 0});

    return 0;
}
