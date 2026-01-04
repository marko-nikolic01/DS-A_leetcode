#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string customSortString(string order, string s) {
    vector<short> letters(26, 25);

    for(short i = order.length() - 1; i > -1; --i) {
        letters[order[i] - 'a'] = i;
    }

    sort(s.begin(), s.end(), [&](char& a, char& b) {
        return letters[a - 'a'] < letters[b - 'a'];
    });

    return s;
}

void test(string order, string s, string expected) {
    cout << "Order: " << "\"" << order << "\"" << endl
    ;
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << customSortString(order, s) << "\"" << endl;

    cout << endl;
}

int main() {
    test("cba", "abcd", "cbad");
    test("bcafg", "abcd", "bcad");
    test("abc", "abc", "abc");
    test("kqep", "pekeq", "kqeep");
    test("xyz", "aabbcc", "aabbcc");

    return 0;
}
