#include <iostream>
#include <vector>

using namespace std;

int uniqueLetterString(string s) {
    vector<vector<int>> letters(26, vector<int>(2, -1));
    letters[s[0] - 'A'][0] = 0;

    int previous = 1;
    int uniqueLetters = 1;

    short j;
    int n = s.length();
    for(int i = 1; i < n; ++i) {
        j = s[i] - 'A';

        previous += i - 2 * letters[j][0] + letters[j][1];
        uniqueLetters += previous;

        letters[j][1] = letters[j][0];
        letters[j][0] = i;
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
