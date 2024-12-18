#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimumPushes(string word) {
    vector<int> occurences(26, 0);

    for(int i = word.length() - 1; i > -1; --i) {
        ++occurences[word[i] - 97];
    }

    sort(occurences.rbegin(), occurences.rend());

    word[0] = 0;
    int pushes = 0;

    for(int i = 0; i < 8 && word[0] < 26 && occurences[word[0]] > 0; ++i, ++word[0]) {
        pushes += occurences[word[0]];
    }

    for(int i = 0; i < 8 && word[0] < 26 && occurences[word[0]] > 0; ++i, ++word[0]) {
        pushes += 2 * occurences[word[0]];
    }

    for(int i = 0; i < 8 && word[0] < 26 && occurences[word[0]] > 0; ++i, ++word[0]) {
        pushes += 3 * occurences[word[0]];
    }

    for(int i = 0; i < 2 && word[0] < 26 && occurences[word[0]] > 0; ++i, ++word[0]) {
        pushes += 4 * occurences[word[0]];
    }

    return pushes;
}

void test(string word, int expected) {
    cout << "Word: \"" << word << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minimumPushes(word) << endl;

    cout << endl;
}

int main() {
    test("hello", 5);
    test("aaaabbbbccccddddeeee", 20);
    test("abcdefghijklmnopqrstuvwxyz", 56);
    test("aabbcc", 6);
    test("zzzzzzzzzzzzzzzzzz", 18);
    test("abacabadabacaba", 15);
    test("a", 1);
    test("abcde", 5);
    test("xyzxyzxyzxyz", 12);
    test("aabbccddeeffgghhiiiiii", 24);

    return 0;
}
