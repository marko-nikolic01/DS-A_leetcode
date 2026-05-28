#include <iostream>
#include <vector>

using namespace std;

string mergeCharacters(string s, int k) {
    vector<short> previous(26, -k - 1);

    short iResult = 0;
    short n = s.length();
    for(short i = 0; i < n; ++i) {
        if(previous[s[i] - 'a'] < iResult - k) {
            s[iResult] = s[i];
            previous[s[i] - 'a'] = iResult++;
        }
    }

    s.resize(iResult);

    return s;
}

void test(string s, int k, string expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << mergeCharacters(s, k) << "\"" << endl;

    cout << endl;
}

int main() {
    test("abca", 3, "abc");
    test("aabca", 2, "abca");
    test("yybyzybz", 2, "ybzybz");
    test("aaaa", 1, "a");
    test("abacaba", 2, "abcab");

    return 0;
}
