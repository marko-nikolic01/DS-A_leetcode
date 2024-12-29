#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> operands;

    int n = tokens.size();
    for(int i = 0; i < n; ++i) {
        if(tokens[i][0] > '/') {
            int operand = tokens[i][0] - '0';

            int l = tokens[i].length();
            for(int j = 1; j < l; ++j) {
                operand = 10 * operand + tokens[i][j] - '0';
            }

            operands.push(operand);
        } else if(tokens[i].length() > 1) {
            int operand = tokens[i][1] - '0';

            int l = tokens[i].length();
            for(int j = 2; j < l; ++j) {
                operand = 10 * operand + tokens[i][j] - '0';
            }

            operands.push(-operand);
        } else {
            int operand2 = operands.top();
            operands.pop();

            int operand1 = operands.top();
            operands.pop();

            if(tokens[i][0] == '+') {
                operands.push(operand1 + operand2);
            } else if(tokens[i][0] == '-') {
                operands.push(operand1 - operand2);
            } else if(tokens[i][0] == '*') {
                operands.push(operand1 * operand2);
            } else {
                operands.push(operand1 / operand2);
            }
        }
    }

    return operands.top();
}

void test(vector<string>& tokens, int expected) {
    cout << "Tokens: ";
    for(string token : tokens) {
        cout << token << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << evalRPN(tokens) << endl;

    cout << endl;
}

int main() {
    vector<string> tokens1 = {"2", "1", "+", "3", "*"};
    test(tokens1, 9);

    vector<string> tokens2 = {"4", "13", "5", "/", "+"};
    test(tokens2, 6);

    vector<string> tokens3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    test(tokens3, 22);

    vector<string> tokens4 = {"5", "1", "2", "+", "4", "*", "+", "3", "+"};
    test(tokens4, 20);

    vector<string> tokens5 = {"3", "4", "+", "2", "*", "7", "/"};
    test(tokens5, 2);

    vector<string> tokens6 = {"2", "3", "*", "5", "+"};
    test(tokens6, 11);

    vector<string> tokens7 = {"1", "1", "+", "2", "*", "3", "+"};
    test(tokens7, 7);

    return 0;
}
