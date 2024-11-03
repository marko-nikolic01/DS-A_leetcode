#include <iostream>
#include <unordered_map>

using namespace std;

int numberOfSpecialChars(string word) {
    int specialCharacters = 0;

    unordered_map<char, int> letters;

    int n = word.length();
    for(int i = 0; i < n; ++i) {
        if(word[i] < 'a') {
            if(letters.find(word[i] + 32) == letters.end()) {
                letters[word[i] + 32] = 2;
            } else if(letters[word[i] + 32] == 0) {
                specialCharacters++;
                letters[word[i] + 32]++;
            }
        } else if(letters.find(word[i]) == letters.end()) {
            letters[word[i]] = 0;
        } else if(letters[word[i]] == 1) {
            specialCharacters--;
            letters[word[i]]++;
        }
    }

    return specialCharacters;
}

void test(string word, int expected) {
    cout << "Word: " << word << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numberOfSpecialChars(word) << endl;

    cout << endl;
}

int main() {
    test("aA", 1);
    test("abAB", 2);
    test("aBc", 0);
    test("Aa", 0);
    test("aBcB", 0);
    test("aBcAb", 1);

    return 0;
}
