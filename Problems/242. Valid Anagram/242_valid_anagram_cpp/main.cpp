#include <iostream>
#include <vector>

using namespace std;

bool isAnagram(string s, string t) {
    vector<int> occurences(26, 0);

    int n = s.size();
    for(int i = 0; i < n; ++i) {
        occurences[s[i] - 97]++;
    }

    n = t.size();
    for(int i = 0; i < n; ++i) {
        occurences[t[i] - 97]--;
    }

    for(int i = 0; i < 26; ++i) {
        if(occurences[i] != 0) {
            return false;
        }
    }

    return true;
}

void runTestCase(const string& s, const string& t, bool expected) {
    bool result = isAnagram(s, t);
    cout << "Test case:\n";
    cout << "String 1: \"" << s << "\"\n";
    cout << "String 2: \"" << t << "\"\n";
    cout << "Expected: " << (expected ? "true" : "false") << "\n";
    cout << "Result: " << (result ? "true" : "false") << "\n\n";
}

int main() {
    runTestCase("anagram", "nagaram", true);
    runTestCase("rat", "car", false);
    runTestCase("listen", "silent", true);
    runTestCase("hello", "world", false);
    runTestCase("", "", true);

    return 0;
}
