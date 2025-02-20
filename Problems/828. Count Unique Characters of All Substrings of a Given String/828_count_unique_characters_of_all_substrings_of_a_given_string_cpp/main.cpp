#include <iostream>
#include <vector>

using namespace std;

int uniqueLetterString(string s) {
    vector<vector<int>> letters(26, vector<int>(2, -1));
    letters[s[0] - 'A'][0] = 0;

    int previous = 1;
    int uniqueLetters = 1;

    int n = s.length();
    for(int i = 1; i < n; ++i) {
        previous = previous + i - 2 * letters[s[i] - 'A'][0] + letters[s[i] - 'A'][1];
        uniqueLetters += previous;

        letters[s[i] - 'A'][1] = letters[s[i] - 'A'][0];
        letters[s[i] - 'A'][0] = i;
    }

    return uniqueLetters;
}

void test(string s, int expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << uniqueLetterString(s) << endl;

    cout << endl;
}

int main() {
    test("ABC", 10);
    test("ABA", 8);
    test("LEETCODE", 92);
    test("A", 1);
    test("ZZZ", 3);
    test("ABCDEFG", 84);
    test("AAABBBCCC", 27);

    return 0;
}
