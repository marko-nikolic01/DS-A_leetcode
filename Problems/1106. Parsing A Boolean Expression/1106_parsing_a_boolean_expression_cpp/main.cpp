#include <iostream>

using namespace std;

bool parseBoolExpr(string& expression, int& start) {
    if(expression[start] == 'f') {
        return false;
    } else if(expression[start] == 't') {
        return true;
    }

    char operation = expression[start];
    start += 2;
    bool result = parseBoolExpr(expression, start);

    if(operation == '!') {
        ++start;
        return !result;
    }

    if(operation == '&') {
        while(expression[++start] == ',') {
            result = parseBoolExpr(expression, ++start) && result;
        }
    } else {
        while(expression[++start] == ',') {
            result = parseBoolExpr(expression, ++start) || result;
        }
    }

    return result;
}

bool parseBoolExpr(string expression) {
    int start = 0;

    return parseBoolExpr(expression, start);
}

void test(string expression, bool expected) {
    cout << "Expression: " << expression << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (parseBoolExpr(expression) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test("&(|(f))", false);
    test("|(f,f,f,t)", true);
    test("!(&(f,t))", true);
    test("!(|(f,t))", false);
    test("&(t,t,t)", true);
    test("|(&(t,f),!(f))", true);
    test("!(&(t,t))", false);

    return 0;
}
