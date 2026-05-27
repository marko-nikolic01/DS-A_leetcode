#include <iostream>

using namespace std;

string greatestLetter(string s) {
    int lowercase = 0;
    int uppercase = 0;

    short i = s.length();
    while(--i > -1) {
        if(s[i] < 'a') {
            uppercase |= 1 << (s[i] - 'A');
        } else {
            lowercase |= 1 << (s[i] - 'a');
        }
    }

    for(i = 25; i > -1; --i) {
        if((lowercase & uppercase & (1 << i)) > 0) {
            s.resize(1);
            s[0] = 'A' + i;

            return s;
        }
    }

    return "";
}

void test(string s, string expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << greatestLetter(s) << "\"" << endl;

    cout << endl;
}

int main() {
    test("lEeTcOdE", "E");
    test("arRAzFif", "R");
    test("AbCdEfGhIjK", "");
    test("aAbBcC", "C");
    test("z", "");

    return 0;
}
