#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

string longestWord(vector<string>& words) {
    sort(words.begin(), words.end(), [](const string &a, const string &b) {
        return (a.length() == b.length()) ? (a > b) : (a.length() > b.length());
    });

    if(words.back().length() > 1) {
        return "";
    }

    short iLongestWord = words.size();
    unordered_set<string> parts;
    string part(1, ' ');

    parts.insert("");

    short j;
    short n;
    for(short i = --iLongestWord; i > -1; --i) {
        part.resize(0);

        n = words[i].length();

        if(n-- > words[iLongestWord].length() + 1) {
            break;
        }

        for(j = 0; j < n; ++j) {
            part.push_back(words[i][j]);
        }

        if(parts.find(part) != parts.end()) {
            parts.insert(words[i]);

            if(++n > words[iLongestWord].length()) {
                iLongestWord = i;
            }

        }
    }

    return words[iLongestWord];
}

void printArray(vector<string> array) {
    for(string a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<string> words, string expected) {
    cout << "Words: ";
    printArray(words);

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << longestWord(words) << "\"" << endl;

    cout << endl;
}

int main() {
    test({"w", "wo", "wor", "worl", "world"}, "world");
    test({"a", "banana", "app", "appl", "ap", "apply", "apple"}, "apple");
    test({"cat", "dog", "plane"}, "");
    test({"t", "ti", "tig", "tige", "tiger", "tigera", "tigers"}, "tigera");
    test({"b", "a", "c"}, "a");

    return 0;
}
