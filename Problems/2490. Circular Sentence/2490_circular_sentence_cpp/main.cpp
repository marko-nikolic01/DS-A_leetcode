#include <iostream>

using namespace std;

bool isCircularSentence(string sentence) {
    char first = sentence[0];
    char last;

    for(int i = sentence.size() - 2; i > -1; --i) {
        last = sentence[++i];

        if(last != first) {
            return false;
        }

        while(i > -1 && sentence[i] != ' ') {
            first = sentence[i--];
        }

        while(i > -1 && sentence[i] == ' ') {
            i--;
        }
    }

    return true;
}

void test(string sentence, bool expected) {
    cout << "Sentence: \"" << sentence << "\"" << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (isCircularSentence(sentence) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test("leetcode exercises sound delightful", true);
    test("eetcode", true);
    test("leetcode eats soul", true);
    test("Leetcode is cool", false);
    test("happy Leetcode", false);
    test("Leetcode", false);
    test("I like Leetcode", false);
    test("a", true);
    test("a a", true);
    test("ab", false);
    test("a b", false);

    return 0;
}
