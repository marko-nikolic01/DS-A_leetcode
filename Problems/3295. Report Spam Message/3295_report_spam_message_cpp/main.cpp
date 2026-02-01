#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
    bool spam = false;
    unordered_set<string> banned;

    int i;
    for(i = bannedWords.size() - 1; i > -1; --i) {
        banned.insert(bannedWords[i]);
    }

    for(i = message.size() - 1; i > -1; --i) {
        if(banned.find(message[i]) != banned.end()) {
            if(spam) {
                return true;
            }

            spam = true;
        }
    }

    return false;
}

void printArray(vector<string> array) {
    for(string a : array) {
        cout << "\"" << a << "\"" << " ";
    }
    cout << endl;
}

void test(vector<string> message, vector<string> bannedWords, bool expected) {
    cout << "Message: ";
    printArray(message);

    cout << "Banned words: ";
    printArray(bannedWords);

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (reportSpam(message, bannedWords) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test({"hello", "world", "leetcode"}, {"world", "hello"}, true);
    test({"hello", "programming", "fun"}, {"world", "programming", "leetcode"}, false);
    test({"spam", "spam", "eggs"}, {"spam"}, true);
    test({"one", "two", "three"}, {"four", "five"}, false);
    test({"a", "b", "c", "a"}, {"a"}, true);

    return 0;
}
