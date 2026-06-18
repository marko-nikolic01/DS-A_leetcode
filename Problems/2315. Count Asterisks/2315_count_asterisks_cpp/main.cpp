#include <iostream>

using namespace std;

int countAsterisks(string s) {
    short asterisks = 0;
    bool isInsidePair = false;

    for(short i = s.length() - 1; i > -1; --i) {
        if(s[i] > '{') {
            isInsidePair = !isInsidePair;
        } else if(s[i] < '+' && !isInsidePair) {
            ++asterisks;
        }
    }

    return asterisks;
}

void test(string s, int expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countAsterisks(s) << endl;

    cout << endl;
}

int main() {
    test("l|*e*et|c**o|*de|", 2);
    test("iamprogrammer", 0);
    test("yo|uar|e**|b|e***au|tifu|l", 5);
    test("*|*|*", 2);
    test("||*", 1);

    return 0;
}
