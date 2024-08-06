#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s) {
    stack<char> openParentheses;

    for(int i = 0; i < s.length(); ++i) {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
            openParentheses.push(s[i]);
        } else {
            if(openParentheses.empty() ||
                (s[i] == ')' && openParentheses.top() != '(') ||
                (s[i] == ']' && openParentheses.top() != '[') ||
                (s[i] == '}' && openParentheses.top() != '{')) {
                return false;
            }
            openParentheses.pop();
        }
    }

    if(openParentheses.empty()) {
        return true;
    }
    return false;
}

int main()
{
    string s = "()[]{}";

    bool result = isValid(s);

    if(result) {
        cout << "Parentheses are valid." << endl;
    } else {
        cout << "Parentheses aren't valid." << endl;
    }
    return 0;
}
