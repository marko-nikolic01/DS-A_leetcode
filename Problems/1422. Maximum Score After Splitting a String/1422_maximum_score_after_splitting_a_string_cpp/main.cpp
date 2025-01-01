#include <iostream>

using namespace std;

int maxScore(string s) {
    short ones = 0;

    short n = s.length();
    for(short i = 0; i < n; ++i) {
        if(s[i] == '1') {
            ++ones;
        }
    }

    short score = 0;
    short currentOnes = 0;

    --n;
    for(short i = 0; i < n; ++i) {
        if(s[i] == '1') {
            ++currentOnes;
        }

        if(i + 1 + ones - 2 * currentOnes > score) {
            score = i + 1 + ones - 2 * currentOnes;
        }
    }

    return score;
}

void test(string s, int expected) {
    cout << "String: " << s << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxScore(s) << endl;

    cout << endl;
}

int main() {
    test("011101", 5);
    test("00111", 5);
    test("1111", 3);
    test("1001", 3);
    test("111000", 2);
    test("01010", 3);
    test("0000", 3);
    test("111111", 5);
    test("1010101010", 5);
    test("0101010", 4);
    test("00", 1);
    test("01", 2);
    test("10", 0);
    test("11", 1);

    return 0;
}
