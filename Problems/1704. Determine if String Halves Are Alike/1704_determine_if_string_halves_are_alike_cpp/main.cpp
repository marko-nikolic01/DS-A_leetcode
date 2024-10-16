#include <iostream>
#include <unordered_set>

using namespace std;

bool halvesAreAlike(string s) {
    unordered_set<char> vowels = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};

    int vowelCount = 0;

    int n = s.length();
    int i = 0;
    for(i; i < n / 2; ++i) {
        if(vowels.find(s[i]) != vowels.end()) {
            vowelCount++;
        }
    }

    for(i; i < n; ++i) {
        if(vowels.find(s[i]) != vowels.end()) {
            vowelCount--;
        }
    }

    return vowelCount == 0;
}

void test(string input, bool expected) {
    cout << "Input: \"" << input << "\"" << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (halvesAreAlike(input) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test("book", true);
    test("textbook", false);
    test("MerryChristmas", false);
    test("AbCdEfGh", true);
    test("aA", true);

    return 0;
}
