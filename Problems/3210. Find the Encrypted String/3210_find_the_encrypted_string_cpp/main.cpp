#include <iostream>

using namespace std;

string getEncryptedString(string s, int k) {
    short n = s.length();
    string encrypted(n, ' ');

    for(short i = 0; i < n; ++i) {
        encrypted[i] = s[(i + k) % n];
    }

    return encrypted;
}

void test(string s, int k, string expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << getEncryptedString(s, k) << "\"" << endl;

    cout << endl;
}

int main() {
    test("dart", 3, "tdar");
    test("aaa", 1, "aaa");
    test("hello", 2, "llohe");
    test("cipher", 4, "erciph");
    test("rotate", 6, "rotate");
    test("abc", 7, "bca");

    return 0;
}
