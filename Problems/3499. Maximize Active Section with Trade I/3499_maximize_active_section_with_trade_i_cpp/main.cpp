#include <iostream>
#include <climits>

using namespace std;

int maxActiveSectionsAfterTrade(string s) {
    int ones = 0;
    int zeros;
    int previousZeros = INT_MIN;
    int maximumZeros = 0;

    for(int i = s.length() - 1; i > -1; --i) {
        if(s[i] < '1') {
            zeros = 1;

            while(--i > -1 && s[i] < '1') {
                ++zeros;
            }
            ++i;

            if(zeros + previousZeros > maximumZeros) {
                maximumZeros = zeros + previousZeros;
            }

            previousZeros = zeros;
        } else {
            ++ones;
        }
    }

    return ones + maximumZeros;
}

void test(string s, int expected) {
    cout << "String: " << s << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxActiveSectionsAfterTrade(s) << endl;

    cout << endl;
}

int main() {
    test("01", 1);
    test("0100", 4);
    test("1000100", 7);
    test("01010", 4);
    test("0000", 0);

    return 0;
}
