#include <iostream>

using namespace std;

string largestEven(string s) {
    for(short i = s.length() - 1; i > -1; --i) {
        if(s[i] > '1') {
            s.resize(++i);

            return s;
        }
    }

    return "";
}

void test(string s, string expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << largestEven(s) << "\"" << endl;

    cout << endl;
}

int main() {
    test("1112", "1112");
    test("221", "22");
    test("1", "");
    test("111", "");
    test("22222", "22222");
    test("1212121", "121212");

    return 0;
}
