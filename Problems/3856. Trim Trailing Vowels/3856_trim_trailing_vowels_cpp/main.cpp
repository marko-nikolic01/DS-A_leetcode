#include <iostream>

using namespace std;

string trimTrailingVowels(string s) {
    for(short n = s.length() - 1; n > -1 && (s[n] == 'a' || s[n] == 'e' || s[n] == 'i' || s[n] == 'o' || s[n] == 'u'); --n) {
        s.pop_back();
    }

    return s;
}

void test(string s, int k, string expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << trimTrailingVowels(s) << "\"" << endl;

    cout << endl;
}

int main() {
    test("idea", 0, "id");
    test("day", 0, "day");
    test("aeiou", 0, "");
    test("programming", 0, "programming");
    test("hello", 0, "hell");

    return 0;
}
