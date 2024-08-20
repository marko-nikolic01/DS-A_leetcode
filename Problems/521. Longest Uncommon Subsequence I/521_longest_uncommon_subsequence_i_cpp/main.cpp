#include <iostream>

using namespace std;

int findLUSlength(string a, string b) {
    if(a == b) {
        return -1;
    }

    int na = a.length();
    int nb = b.length();
    if(na > nb) {
        return na;
    }
    return nb;
}

void testFindLUSlength(string a, string b, int expected) {
    int result = findLUSlength(a, b);
    cout << "Strings: \"" << a << "\", \"" << b << "\"" << endl;
    cout << "Expected: " << expected << endl;
    cout << "Result: " << result << endl;
    cout << endl;
}

int main() {
    testFindLUSlength("abc", "def", 3);
    testFindLUSlength("abc", "abc", -1);
    testFindLUSlength("abcd", "abc", 4);
    testFindLUSlength("xyz", "xy", 3);
    testFindLUSlength("hello", "world", 5);

    return 0;
}
