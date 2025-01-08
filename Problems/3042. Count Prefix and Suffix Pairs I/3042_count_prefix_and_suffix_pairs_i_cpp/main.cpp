#include <iostream>
#include <vector>

using namespace std;

int countPrefixSuffixPairs(vector<string>& words) {
    short pairs = 0;

    short n = words.size();
    for(short i = 0; i < n; ++i) {
        short l1 = words[i].length();

        for(short j = i + 1; j < n; ++j) {
            short l2 = words[j].length();

            if(l1 <= l2) {
                ++pairs;

                for(short k = 0; k < l1; ++k) {
                    if(words[i][k] != words[j][k] || words[i][k] != words[j][l2 - l1 + k]) {
                        --pairs;
                        break;
                    }
                }
            }
        }
    }

    return pairs;
}

void test(vector<string> words, int expected) {
    cout << "Words: ";
    for(string word : words) {
        cout << "\"" << word << "\" ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countPrefixSuffixPairs(words) << endl;

    cout << endl;
}

int main() {
    test({"a", "aba", "ababa", "aa"}, 4);
    test({"pa", "papa", "ma", "mama"}, 2);
    test({"abab", "ab"}, 0);
    test({"a", "a", "aa", "aaa"}, 6);
    test({"abc", "abcd", "bc", "bcd"}, 0);
    test({"a", "b", "c", "d"}, 0);
    test({"xy", "xyxy", "yxy", "xyx"}, 1);

    return 0;
}
