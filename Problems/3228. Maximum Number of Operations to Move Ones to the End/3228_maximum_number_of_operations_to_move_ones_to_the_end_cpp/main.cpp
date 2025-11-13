#include <iostream>

using namespace std;

int maxOperations(string s) {
    int operations = 0;
    int ones = s[0] > '0' ? 1 : 0;

    s.push_back('1');

    int n = s.length();
    for(int i = 1; i < n; ++i) {
        if(s[i] > '0') {
            if(s[i - 1] < '1') {
                operations += ones;
            }

            ++ones;
        }
    }

    return operations;
}


void test(string s, int expected) {
    cout << "String: " << s << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxOperations(s) << endl;

    cout << endl;
}

int main() {
    test("1001101", 4);
    test("00111", 0);
    test("110", 2);
    test("101010", 6);
    test("111000", 3);
    test("010010", 3);

    return 0;
}
