#include <iostream>

using namespace std;

int longestSubsequence(string s, int k) {
    int value = 0;
    short length = 0;

    for(short i = s.length() - 1; i > -1; --i) {
        if(s[i] > '0') {
            if(length < 31 && (value | (1 << length)) <= k) {
                value |= 1 << length++;
            }
        } else {
            ++length;
        }
    }

    return length;
}

void test(string s, int k, int expected) {
    cout << "String: " << s << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << longestSubsequence(s, k) << endl;

    cout << endl;
}

int main() {
    test("1001010", 5, 5);
    test("00101001", 1, 6);
    test("1111", 0, 0);
    test("0000", 0, 4);
    test("100110111111000000010011101000111011000001000111010001010111100001111110110010100011100100111000011011000000100001011000000100110110001101011010011", 522399436, 92);

    return 0;
}
