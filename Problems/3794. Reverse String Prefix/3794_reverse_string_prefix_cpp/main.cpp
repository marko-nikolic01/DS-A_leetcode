#include <iostream>

using namespace std;

string reversePrefix(string s, int k) {
    char temp;

    for(short i = 0; i < --k; ++i) {
        temp = s[i];
        s[i] = s[k];
        s[k] = temp;
    }

    return s;
}

void test(string s, int k, string expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << reversePrefix(s, k) << "\"" << endl;

    cout << endl;
}

int main() {
    test("abcd", 2, "bacd");
    test("xyz", 3, "zyx");
    test("hey", 1, "hey");
    test("algorithm", 5, "roglaithm");
    test("programming", 7, "margorpming");

    return 0;
}

