#include <iostream>

using namespace std;

int reverseDegree(string s) {
    int degree = 0;

    for(short i = s.length() - 1; i > -1; --i) {
        degree += (i + 1) * (26 - s[i] + 'a');
    }

    return degree;
}

void test(string s, int expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << reverseDegree(s) << endl;

    cout << endl;
}

int main() {
    test("abc", 148);
    test("zaza", 160);
    test("a", 26);
    test("z", 1);
    test("az", 28);

    return 0;
}
