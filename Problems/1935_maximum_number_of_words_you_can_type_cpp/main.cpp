#include <iostream>

using namespace std;

int canBeTypedWords(string text, string brokenLetters) {
    int letters = 0;

    short i;
    for(i = brokenLetters.size() - 1; i > -1; --i) {
        letters |= 1 << (brokenLetters[i] - 'a');
    }

    short words = 0;

    for(i = text.length() - 1; i > -1; --i) {
        while(i > -1 && text[i] != ' ') {
            if((letters & (1 << (text[i] - 'a'))) > 0) {
                break;
            }

            --i;
        }

        if(i < 0 || text[i] == ' ') {
            ++words;
        }

        while(i > -1 && text[i] != ' ') {
            --i;
        }

        while(i > -1 && text[i] == ' ') {
            --i;
        }
        ++i;
    }

    return words;
}

void test(string text, string brokenLetters, int expected) {
    cout << "Text: " << "\"" << text << "\"" << endl;

    cout << "Broken letters: " << "\"" << brokenLetters << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << canBeTypedWords(text, brokenLetters) << endl;

    cout << endl;
}

int main() {
    test("hello world", "ad", 1);
    test("leet code", "lt", 1);
    test("leet code", "e", 0);
    test("a b c d e", "xyz", 5);
    test("abc def ghi", "cf", 1);

    return 0;
}
