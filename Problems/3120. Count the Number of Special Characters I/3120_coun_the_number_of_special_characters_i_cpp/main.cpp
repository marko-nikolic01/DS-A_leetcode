#include <iostream>
#include <vector>

using namespace std;

int numberOfSpecialChars(string word) {
    short special = 0;
    vector<pair<bool, bool>> letters(26, {false, false});

    for(short i = word.length() - 1; i > -1; --i) {
        if(word[i] < 'a') {
            if(!letters[word[i] - 'A'].first) {
                letters[word[i] - 'A'].first = true;

                if(letters[word[i] - 'A'].second) {
                    ++special;
                }
            }
        } else if(!letters[word[i] - 'a'].second) {
            letters[word[i] - 'a'].second = true;

            if(letters[word[i] - 'a'].first) {
                ++special;
            }
        }
    }

    return special;
}

void test(string word, int expected) {
    cout << "Word: " << "\"" << word << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numberOfSpecialChars(word) << endl;

    cout << endl;
}

int main() {
    test("aaAbcBC", 3);
    test("abc", 0);
    test("abBCab", 1);
    test("aAbB", 2);
    test("AaBbCc", 3);
    test("ABC", 0);

    return 0;
}
