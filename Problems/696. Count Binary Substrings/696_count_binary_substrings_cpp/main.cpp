#include <iostream>

using namespace std;

int countBinarySubstrings(string s) {
    int count = 0;

    int zeros = 0;
    int ones = 0;

    bool previous = false;

    int n = s.length();
    for(int i = 0; i < n; ++i) {
        if(s[i] == '0') {
            if(previous) {
                zeros = 0;
            }

            previous = false;
            ++zeros;

            if(zeros <= ones) {
                ++count;
            }
        } else {
            if(!previous) {
                ones = 0;
            }

            previous = true;
            ++ones;

            if(ones <= zeros) {
                ++count;
            }
        }
    }

    return count;
}

void test(string s, int expected) {
    cout << "s: " << s << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countBinarySubstrings(s) << endl;

    cout << endl;
}

int main() {
    test("00110011", 6);
    test("10101", 4);
    test("000111", 3);
    test("0000", 0);
    test("1111", 0);

    return 0;
}
