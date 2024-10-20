#include <iostream>

using namespace std;

string reversePrefix(string word, char ch) {
    int n = word.length();
    for(int i = 0; i < n; ++i) {
        if(word[i] == ch) {
            n = 0;
            while(n < i) {
                ch = word[n];
                word[n++] = word[i];
                word[i--] = ch;
            }
            return word;
        }
    }

    return word;
}

void test(string word, char ch, string expected) {
    cout << "Word: " << word << endl;

    cout << "Character: " << ch << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << reversePrefix(word, ch) << endl;

    cout << endl;
}

int main() {
    test("abcdef", 'd', "dcbaef");
    test("abcdef", 'a', "abcdef");
    test("abcdefg", 'g', "gfedcba");
    test("xyz", 'a', "xyz");
    test("hello", 'l', "lehlo");
    test("aaaaa", 'a', "aaaaa");

    return 0;
}
