#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long countPairs(vector<string>& words) {
    long pairs = 0;
    unordered_map<string, int> ciphers;
    short normalization;

    int j;
    for(int i = words.size() - 1; i > -1; --i) {
        normalization = words[i][0] - 'a';

        for(int j = words[i].length() - 1; j > -1; --j) {
            words[i][j] = (words[i][j] - '=' - normalization) % 26;
        }

        pairs += ciphers[words[i]]++;
    }

    return pairs;
}

void printArray(vector<string> array) {
    for(string a : array) {
        cout << "\"" << a << "\"" << " ";
    }
    cout << endl;
}

void test(vector<string> words, long long expected) {
    cout << "Words: ";
    printArray(words);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countPairs(words) << endl;

    cout << endl;
}

int main() {
    test({"fusion", "layout"}, 1);
    test({"ab", "aa", "za", "aa"}, 2);
    test({"abc", "bcd", "cde", "xyz"}, 6);
    test({"a", "b", "c", "z"}, 6);
    test({"abc", "abc", "abc"}, 3);

    return 0;
}
