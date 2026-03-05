#include <iostream>
#include <vector>

using namespace std;

int minOperations(string s) {
    vector<short> operations(2, 0);

    for(short i = s.length() - 1; i > -1; --i) {
        ++operations[(i & 1) < 1 ? (s[i] < '1' ? 0 : 1) : (s[i] < '1' ? 1 : 0)];
    }

    return min(operations[0], operations[1]);
}

void test(string s, int expected) {
    cout << "s: " << s << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minOperations(s) << endl;

    cout << endl;
}

int main() {
    test("0100", 1);
    test("10", 0);
    test("1111", 2);
    test("010101", 0);
    test("0000", 2);

    return 0;
}
