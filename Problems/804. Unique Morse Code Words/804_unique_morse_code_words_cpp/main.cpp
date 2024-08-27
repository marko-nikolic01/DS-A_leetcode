#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int uniqueMorseRepresentations(vector<string>& words) {
    vector<string> dictionary = {
        ".-","-...","-.-.","-..",".",
        "..-.","--.","....","..",".---",
        "-.-",".-..","--","-.","---",
        ".--.","--.-",".-.","...","-",
        "..-","...-",".--","-..-","-.--",
        "--.."
    };

    unordered_set<string> morseWords;

    for(int i = words.size() - 1; i > -1; --i) {
        string morseWord = "";

        int l = words[i].length();
        for(int j = 0; j < l; ++j) {
            morseWord += dictionary[words[i][j] - 97];
        }

        morseWords.insert(morseWord);
    }

    return morseWords.size();
}

void runTest(const vector<string>& words, int expected) {
    cout << "Words: [ ";
    for (const auto& word : words) {
        cout << "\"" << word << "\" ";
    }
    cout << "]" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << uniqueMorseRepresentations(const_cast<vector<string>&>(words)) << endl;

    cout << endl;
}

int main() {
    runTest({"gin", "zen", "gig", "msg"}, 2);
    runTest({"a", "b", "c"}, 3);
    runTest({"a", "a", "a"}, 1);
    runTest({"hello", "world"}, 2);
    runTest({"abc", "def", "xyz"}, 3);

    return 0;
}
