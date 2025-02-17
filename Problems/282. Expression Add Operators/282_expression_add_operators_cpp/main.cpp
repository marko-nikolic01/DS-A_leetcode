#include <iostream>
#include <vector>

using namespace std;

void addOperators(string& num, vector<string>& expressions, string& expression, short i, short& n, int value, long operand, int& target) {
    if(i == n) {
        if(value + operand == target) {
            expressions.push_back(expression);
        }

        return;
    }

    short sign = expression.size();
    expression.push_back(' ');

    long number = num[i] - '0';
    expression.push_back(num[i]);

    expression[sign] = '+';
    addOperators(num, expressions, expression, i + 1, n, value + operand, number, target);

    expression[sign] = '-';
    addOperators(num, expressions, expression, i + 1, n, value + operand, -number, target);

    expression[sign] = '*';
    addOperators(num, expressions, expression, i + 1, n, value, operand * number, target);

    if(num[i] != '0') {
        for(++i; i < n; ++i) {
            number = 10 * number + num[i] - '0';
            expression.push_back(num[i]);

            expression[sign] = '+';
            addOperators(num, expressions, expression, i + 1, n, value + operand, number, target);

            expression[sign] = '-';
            addOperators(num, expressions, expression, i + 1, n, value + operand, -number, target);

            expression[sign] = '*';
            addOperators(num, expressions, expression, i + 1, n, value, operand * number, target);
        }
    }

    expression.resize(sign);
}

vector<string> addOperators(string num, int target) {
    vector<string> expressions;
    string expression = "";

    long number = num[0] - '0';
    expression.push_back(num[0]);

    short n = num.size();
    addOperators(num, expressions, expression, 1, n, 0, number, target);

    if(num[0] != '0') {
        short n = num.size();
        for(short i = 1; i < n; ++i) {
            number = 10 * number + num[i] - '0';
            expression.push_back(num[i]);

            addOperators(num, expressions, expression, i + 1, n, 0, number, target);
        }
    }

    return expressions;
}

void printArray(vector<string> array) {
    for(string a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(string num, int target, vector<string> expected) {
    cout << "Numbers: " << num << endl;

    cout << "Target: " << target << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(addOperators(num, target));

    cout << endl;
}

int main()
{
    test("123", 6, {"1+2+3", "1*2*3"});
    test("232", 8, {"2+3*2", "2*3+2"});
    test("3456237490", 9191, {});
    test("105", 5, {"1*0+5", "10-5"});
    test("00", 0, {"0+0", "0-0", "0*0"});
    test("345", 15, {});
    test("98", 17, {"9+8"});

    return 0;
}
