#include <iostream>

using namespace std;

int getLucky(string s, int k) {
    short number = 0;

    short i;
    for(i = s.length() - 1; i > -1; --i) {
        number += (s[i] - '`') % 10 + (s[i] - '`') / 10;
    }

    while(--k > 0) {
        i = number;
        number = 0;

        while(i > 0) {
            number += i % 10;
            i /= 10;
        }
    }

    return number;
}

void test(string s, int k, int expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << getLucky(s, k) << endl;

    cout << endl;
}

int main() {
    test("iiii", 1, 36);
    test("leetcode", 2, 6);
    test("zbax", 2, 8);
    test("a", 1, 1);
    test("z", 3, 8);

    return 0;
}
