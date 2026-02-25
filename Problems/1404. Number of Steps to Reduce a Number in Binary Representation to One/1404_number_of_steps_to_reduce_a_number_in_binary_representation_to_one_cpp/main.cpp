#include <iostream>

using namespace std;

int numSteps(string s) {
    short steps = 0;
    short carry = 0;

    for(short i = s.length() - 1; i > 0; --i) {
        if(((s[i] - '0' + carry) & 1) > 0) {
            steps += 2;
            carry = 1;
        } else {
            ++steps;
        }
    }

    return steps + carry;
}

void test(string s, int expected) {
    cout << "s: " << s << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numSteps(s) << endl;

    cout << endl;
}

int main() {
    test("1101", 6);
    test("10", 1);
    test("1", 0);
    test("1111", 5);
    test("1001", 7);

    return 0;
}
