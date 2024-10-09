#include <iostream>

using namespace std;

int maxPower(string s) {
    int maximumPower = 1;

    for(int i = s.length() - 2; i > -1; --i) {
        int power = 1;

        while(i > -1 && s[i] == s[i + 1]) {
            power++;
            i--;
        }

        if(power > maximumPower) {
            maximumPower = power;
        }
    }

    return maximumPower;
}

void test(string s, int expected) {
    cout << "Input: \"" << s << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxPower(s) << endl;

    cout << endl;
}

int main() {
    test("abbcccddddeee", 4);
    test("leetcode", 2);
    test("aabbcc", 2);
    test("aaaaa", 5);
    test("abcde", 1);
    test("bbbbb", 5);
    test("a", 1);

    return 0;
}
