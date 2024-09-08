#include <iostream>
#include <vector>

using namespace std;

string reverseWords(string s) {
    vector<string> words;

    string word = "";

    int n = s.length();
    for(int i = 0; i < n; ++i) {
        if(s[i] == ' ') {
            if(word.length() > 0) {
                words.push_back(word);
                word = "";
            }
        } else {
            word += s[i];
        }
    }
    if(word.length() > 0) {
        words.push_back(word);
        word = "";
    }

    string sentence = "";

    n = words.size() - 1;
    for(n; n > -1; --n) {
        sentence += words[n];
        if(n > 0) {
            sentence += ' ';
        }
    }

    return sentence;
}

void testCase(string input, string expected) {
    cout << "Input: \"" << input << "\"" << endl;

    cout << "Expected: \"" << expected << "\"" << endl;

    cout << "Result: \"" << reverseWords(input) << "\"" << endl;

    cout << endl;
}

int main()
{
    testCase("Hello world", "world Hello");

    testCase("The quick brown fox", "fox brown quick The");

    testCase("", "");

    testCase("   ", "");

    testCase(" a ", "a");

    testCase("one two three four five", "five four three two one");

    testCase("   leading and trailing spaces   ", "spaces trailing and leading");

    return 0;
}
