#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int minDeletions(string s) {
    vector<int> letters(26, 0);

    int i;
    for(i = s.length() - 1; i > -1; --i) {
        ++letters[s[i] - 'a'];
    }

    int deletions = 0;
    unordered_set<int> frequencies;

    for(i = 0; i < 26; ++i) {
        while(letters[i] > 0 && frequencies.find(letters[i]) != frequencies.end()) {
            --letters[i];
            ++deletions;
        }

        frequencies.insert(letters[i]);
    }

    return deletions;
}

void test(string s, int expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minDeletions(s) << endl;

    cout << endl;
}


int main() {
    test("aab", 0);
    test("aaabbbcc", 2);
    test("ceabaacb", 2);
    test("bbcebab", 2);
    test("abcabc", 3);

    return 0;
}
