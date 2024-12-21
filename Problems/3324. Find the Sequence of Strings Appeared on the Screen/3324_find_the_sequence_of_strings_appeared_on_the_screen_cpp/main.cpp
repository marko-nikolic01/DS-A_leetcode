#include <iostream>
#include <vector>

using namespace std;

vector<string> stringSequence(string target) {
    vector<string> words;
    string word = "";

    int n = target.length();
    for(int i = 0; i < n; ++i) {
        word.push_back('a');

        while(word[i] < target[i]) {
            words.push_back(word);
            ++word[i];
        }

        words.push_back(word);
    }

    return words;
}

void test(string target, vector<string> expected) {
    cout << "Target: " << target << endl;

    cout << "Expected: ";
    for (string e : expected) {
        cout << "\"" << e << "\"" << " ";
    }
    cout << endl;

    cout << "Result: ";
    for (string result : stringSequence(target)) {
        cout << "\"" << result << "\"" << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    test("abc", {"a", "aa", "ab", "aba", "abb", "abc"});
    test("a", {"a"});
    test("aaa", {"a", "aa", "aaa"});
    test("z", {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"});
    test("ac", {"a", "aa", "ab", "ac"});

    return 0;
}
