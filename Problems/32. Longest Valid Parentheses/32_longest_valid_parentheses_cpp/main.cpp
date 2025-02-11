#include <iostream>
#include <vector>

using namespace std;

int longestValidParentheses(string s) {
    vector<short> parentheses;
    int iParentheses = -1;

    short length = 0;

    int n = s.length();
    for(int i = 0; i < n; ++i) {
        if(s[i] == '(') {
            parentheses.push_back(0);
            ++iParentheses;
        } else if(iParentheses > -1) {
            if(parentheses[iParentheses] < 1) {
                parentheses[iParentheses] = 1;

                if(iParentheses > 0 && parentheses[iParentheses - 1] > 0) {
                    parentheses[iParentheses - 1] += parentheses[iParentheses];
                    --iParentheses;
                    parentheses.pop_back();
                }

                if(parentheses[iParentheses] > length) {
                    length = parentheses[iParentheses];
                }
            } else if(iParentheses > 0) {
                parentheses[iParentheses - 1] = ++parentheses[iParentheses];
                --iParentheses;
                parentheses.pop_back();

                if(iParentheses > 0 && parentheses[iParentheses - 1] > 0) {
                    parentheses[iParentheses - 1] += parentheses[iParentheses];
                    --iParentheses;
                    parentheses.pop_back();
                }

                if(parentheses[iParentheses] > length) {
                    length = parentheses[iParentheses];
                }
            } else {
                parentheses.resize(0);
                iParentheses = -1;
            }
        }
    }

    return 2 * length;
}

void test(string s, int expected) {
    cout << "Parentheses: " << s << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << longestValidParentheses(s) << endl;

    cout << endl;
}

int main() {
    test("(()", 2);
    test(")()())", 4);
    test("", 0);
    test("()(()", 2);
    test("()()()", 6);
    test(")((((())))(", 8);
    test("())(()))", 4);
    test(")(()())()()(()()))()()(((())()()", 16);
    test(")))", 0);

    return 0;
}
