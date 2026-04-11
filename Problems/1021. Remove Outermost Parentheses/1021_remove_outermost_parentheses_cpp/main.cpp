#include <iostream>

using namespace std;

string removeOuterParentheses(string s) {
    int parentheses = 0;

    int iParentheses = -1;
    int n = s.length();
    for(int i = 0; i < n; ++i) {
        ++parentheses;

        while(true) {
            if(s[++i] == '(') {
                ++parentheses;
            } else if(--parentheses < 1) {
                break;
            }

            s[++iParentheses] = s[i];
        }
    }

    s.resize(++iParentheses);

    return s;
}

void test(string s, string expected) {
    cout << "Parentheses: " << s << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << removeOuterParentheses(s) << endl;

    cout << endl;
}

int main() {
    test("(()())(())", "()()()");
    test("(()())(())(()(()))", "()()()()(())");
    test("()()", "");
    test("(((())))", "((()))");
    test("()()()()", "");

    return 0;
}
