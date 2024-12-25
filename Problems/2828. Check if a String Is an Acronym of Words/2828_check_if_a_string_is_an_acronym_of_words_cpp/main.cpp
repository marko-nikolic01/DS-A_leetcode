#include <iostream>
#include <vector>

using namespace std;

bool isAcronym(vector<string>& words, string s) {
    int n = s.length();
    if(words.size() != n) {
        return false;
    }

    for(--n; n > - 1; --n) {
        if(s[n] != words[n][0]) {
            return false;
        }
    }

    return true;
}

void test(vector<string> words, string s, bool expected) {
    bool result = isAcronym(words, s);
    cout << "Words: ";
    for (string word : words) {
        cout << "\"" << word << "\" ";
    }
    cout << endl;

    cout << "Acronym: \"" << s << "\"" << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (isAcronym(words, s) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test({"alice", "bob", "charlie"}, "abc", true);
    test({"an", "apple"}, "a", false);
    test({"never", "gonna", "give", "up", "on", "you"}, "ngguoy", true);
    test({"test", "case"}, "tc", true);
    test({"hello", "world"}, "hw", true);
    test({"quick", "brown", "fox"}, "qbf", true);
    test({"quick", "brown", "fox"}, "qbx", false);

    return 0;
}

