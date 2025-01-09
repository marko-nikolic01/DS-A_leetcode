#include <iostream>
#include <vector>

using namespace std;

int prefixCount(vector<string>& words, string pref) {
    short prefixes = 0;
    short n = pref.size();

    for(short i = words.size() - 1; i > -1; --i) {
        if(words[i].size() >= n) {
            ++prefixes;

            for(short j = 0; j < n; ++j) {
                if(words[i][j] != pref[j]) {
                    --prefixes;
                    break;
                }
            }
        }
    }

    return prefixes;
}

void test(vector<string> words, string pref, int expected) {
    cout << "Words: ";
    for(string word : words) {
        cout << "\"" << word << "\" ";
    }
    cout << endl;

    cout << "Prefix: " << pref << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << prefixCount(words, pref) << endl;

    cout << endl;;
}

int main() {
    test({"pay", "attention", "practice", "attend"}, "at", 2);
    test({"leetcode", "win", "loops", "success"}, "code", 0);
    test({"apple", "application", "app", "apricot"}, "app", 3);
    test({"hello", "world", "hell", "helicopter"}, "hel", 3);
    test({"test", "testing", "tester", "team"}, "tes", 3);
    test({"a", "ab", "abc", "abcd"}, "abc", 2);
    return 0;
}
