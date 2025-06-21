#include <iostream>
#include <vector>

using namespace std;

int minimumDeletions(string word, int k) {
    vector<int> letters(26, 0);
    int deletions = word.length();
    int currentDeletions;
    int used = 0;

    int i;
    for(i = deletions - 1; i > -1; --i) {
        ++letters[word[i] - 'a'];
    }

    int j;
    for(i = 0; i < 26; ++i) {
        if((used & (1 << i)) < 1) {
            currentDeletions = 0;

            for(j = 0; j < 26; ++j) {
                if(letters[i] == letters[j]) {
                    used |= 1 << j;
                } else if(letters[i] > letters[j]) {
                    currentDeletions += letters[j];
                } else if(letters[i] + k < letters[j]) {
                    currentDeletions += letters[j] - letters[i] - k;
                }
            }

            if(currentDeletions < deletions) {
                deletions = currentDeletions;
            }
        }
    }

    return deletions;
}

void test(string word, int k, int expected) {
    cout << "Word: " << "\"" << word << "\"" << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minimumDeletions(word, k) << endl;

    cout << endl;
}

int main() {
    test("aabcaba", 0, 3);
    test("dabdcbdcdcd", 2, 2);
    test("aaabaaa", 2, 1);
    test("ahahnhahhah", 1, 2);
    test("zzzzzz", 0, 0);

    return 0;
}
