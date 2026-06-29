#include <iostream>
#include <vector>

using namespace std;

bool numOfStrings(string& pattern, string& word) {
    short j;
    short k;
    short n = pattern.length() - 1;
    for(short i = word.length() - 1; i >= n; --i) {
        k = i;
        for(j = n; j > -1; --j) {
            if(pattern[j] != word[k--]) {
                break;
            }
        }

        if(j < 0) {
            return true;
        }
    }

    return false;
}

int numOfStrings(vector<string>& patterns, string word) {
    short substrings = 0;

    for(short i = patterns.size() - 1; i > -1; --i) {
        if(numOfStrings(patterns[i], word)) {
            ++substrings;
        }
    }

    return substrings;
}

void printArray(vector<string> array) {
    for(string a : array) {
        cout << "\"" << a << "\"" << " ";
    }
    cout << endl;
}

void test(vector<string> patterns, string word, int expected) {
    cout << "Patterns: ";
    printArray(patterns);

    cout << "Word: " << "\"" << word << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numOfStrings(patterns, word) << endl;

    cout << endl;
}

int main() {
    test({"a", "abc", "bc", "d"}, "abc", 3);
    test({"a", "b", "c"}, "aaaaabbbbb", 2);
    test({"a", "a", "a"}, "ab", 3);
    test({"xyz"}, "abc", 0);
    test({"a", "ab", "abc", "abcd"}, "abcd", 4);

    return 0;
}
