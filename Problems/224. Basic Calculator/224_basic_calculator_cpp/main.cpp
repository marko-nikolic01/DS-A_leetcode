#include <iostream>
#include <stack>

using namespace std;

int calculate(string s) {
    stack<int> operands;
    operands.push(0);

    bool sign = true;
    stack<bool> signs;

    int n = s.length();
    for(int i = 0; i < n; ++i) {
        if(s[i] == '+') {
            sign = true;
        } else if(s[i] == '-') {
            sign = false;
        } else if(s[i] > '/' && s[i] < ':') {
            long operand = s[i] - '0';

            while(s[++i] > '/' && s[i] < ':') {
                operand = 10 * operand + s[i] - '0';
            }
            --i;

            if(sign) {
                operands.top() += operand;
            } else {
                operands.top() -= operand;
            }
            sign = true;
        } else if(s[i] == '(') {
            operands.push(0);

            signs.push(sign);
            sign = true;
        } else if(s[i] == ')') {
            long operand = operands.top();
            operands.pop();

            if(signs.top()) {
                operands.top() += operand;
            } else {
                operands.top() -= operand;
            }
            signs.pop();
        }
    }

    return operands.top();
}

void test(string expression, int expected) {
    cout << "Expression: " << expression << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << calculate(expression) << endl;

    cout << endl;
}

int main() {
    test("1 + 1", 2);
    test(" 2-1 + 2 ", 3);
    test("(1+(4+5+2)-3)+(6+8)", 23);
    test("10-(2+3-(1+1))", 7);
    test("100-(50-(25+10))", 85);
    test("(1+(2+3-(4-5)+6))", 13);
    test("5-(4-(3-(2-1)))", 3);
    test("- (3 + (4 + 5))", -12);
    test("2147483647", 2147483647);

    return 0;
}
