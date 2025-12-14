#include <iostream>

using namespace std;

string reverseWords(string s) {
    int vowels = 0;
    int currentVowels;
    char character;

    int i;
    int n = s.length();
    for(i = 0; i < n && s[i] > '`'; ++i) {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            ++vowels;
        }
    }

    int j;
    int k;
    while(++i < n) {
        currentVowels = 0;

        for(j = i--; j < n && s[j] > '`'; ++j) {
            if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') {
                ++currentVowels;
            }
        }

        if(currentVowels == vowels) {
            k = j;
            while(++i < --k) {
                character = s[i];
                s[i] = s[k];
                s[k] = character;
            }
        }

        i = j;
    }

    return s;
}

void test(string s, string expected) {
    cout << "Words: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << reverseWords(s) << "\"" << endl;

    cout << endl;
}

int main() {
    test("cat and mice", "cat dna mice");
    test("book is nice", "book is ecin");
    test("banana healthy", "banana healthy");
    test("hello world again", "hello world again");
    test("team meet stream", "team teem maerts");
    test("word", "word");

    return 0;
}

