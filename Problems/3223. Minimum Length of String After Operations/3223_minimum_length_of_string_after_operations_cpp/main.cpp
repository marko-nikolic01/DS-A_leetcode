#include <iostream>
#include <vector>

using namespace std;

int minimumLength(string s) {
    vector<short> letters(26, 0);

    int length = s.length();

    for(int i = length - 1; i > -1; --i) {
        if(letters[s[i] - 'a'] == 2) {
            length -= 2;
            letters[s[i] - 'a'] = 1;
        } else {
            ++letters[s[i] - 'a'];
        }
    }

    return length;
}

void runTest(string s, int expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minimumLength(s) << endl;

    cout << endl;
}

int main() {
    runTest("abaacbcbb", 5);
    runTest("aa", 2);
    runTest("a", 1);
    runTest("abccba", 6);
    runTest("aabba", 3);
    runTest("abcde", 5);
    runTest("aaa", 1);
    runTest("aaaa", 2);

    return 0;
}
