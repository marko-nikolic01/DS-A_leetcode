#include <iostream>

using namespace std;

int partitionString(string s) {
    int partitions = 0;
    int letters;

    for(int i = s.length() - 1; i > -1; i) {
        ++partitions;
        letters = 1 << (s[i] - 'a');

        while(--i > -1 && (letters & (1 << (s[i] - 'a'))) < 1) {
            letters |= 1 << (s[i] - 'a');
        }
    }

    return partitions;
}

void test(string s, int expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << partitionString(s) << endl;

    cout << endl;
}

int main() {
    test("abacaba", 4);
    test("ssssss", 6);
    test("abcabc", 2);
    test("abcd", 1);
    test("aabbccddeeff", 7);
    test("leetcode", 3);

    return 0;
}
