#include <iostream>

using namespace std;

bool isAdjacentDiffAtMostTwo(string s) {
    for(short i = s.length() - 1; i > 0; --i) {
        if(abs(s[i] - s[i - 1]) > 2) {
            return false;
        }
    }

    return true;
}

void test(string s, bool expected) {
    cout << "Digits: " << s << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (isAdjacentDiffAtMostTwo(s) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test("132", true);
    test("129", false);
    test("99", true);
    test("13579", true);
    test("1359", false);

    return 0;
}
