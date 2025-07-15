#include <iostream>

using namespace std;

bool isValid(string word) {
    short n = word.length();
    if(n < 3) {
        return false;
    }

    bool vowel = false;
    bool consonant = false;

    for(--n; n > -1; --n) {
        if(word[n] > '`' && word[n] < '{') {
            if(word[n] == 'a' || word[n] == 'e' || word[n] == 'i' || word[n] == 'o' || word[n] == 'u') {
                vowel = true;
            } else {
                consonant = true;
            }
        } else if(word[n] > '@' && word[n] < '[') {
            if(word[n] == 'A' || word[n] == 'E' || word[n] == 'I' || word[n] == 'O' || word[n] == 'U') {
                vowel = true;
            } else {
                consonant = true;
            }
        } else if(word[n] < '0' || word[n] > '9') {
            return false;
        }
    }

    return vowel && consonant;
}

void test(string word, bool expected) {
    cout << "Word: " << "\"" << word << "\"" << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (isValid(word) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test("234Adas", true);
    test("b3", false);
    test("a3$e", false);
    test("Ae3", false);
    test("Ya$", false);
    test("Code9", true);

    return 0;
}
