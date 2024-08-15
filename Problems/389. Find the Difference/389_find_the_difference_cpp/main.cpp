#include <iostream>

using namespace std;

char findTheDifference(string s, string t) {
    char difference = 0;

    int n = s.length();
    for(int i = 0; i < n; ++i) {
        difference ^= s[i];
        difference ^= t[i];
    }
    difference ^= t[n];

    return difference;
}

void testFindTheDifference(string s, string t, char expected) {
    char result = findTheDifference(s, t);
    cout << "String s: " << s << endl;
    cout << "String t: " << t << endl;
    cout << "Expected: " << expected << endl;
    cout << "Result: " << result << endl;
    cout << endl;
}

int main() {
    testFindTheDifference("abcd", "abcde", 'e');
    testFindTheDifference("abc", "abcd", 'd');
    testFindTheDifference("xyz", "xyza", 'a');
    testFindTheDifference("hello", "helloo", 'o');
    testFindTheDifference("abc", "cba", '\0');

    return 0;
}
