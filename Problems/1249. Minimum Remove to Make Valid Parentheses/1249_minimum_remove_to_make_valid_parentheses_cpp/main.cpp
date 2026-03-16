#include <iostream>
#include <vector>

using namespace std;

string minRemoveToMakeValid(string s) {
    string result = "";
    int openParenthesesCount = 0;
    vector<char> arr(s.begin(), s.end());

    int i;
    int n = arr.size();
    for(i = 0; i < n; ++i) {
        if(arr[i] == '(') {
            ++openParenthesesCount;
        } else if (arr[i] == ')') {
            if (openParenthesesCount == 0) {
                arr[i] = '*';
            } else {
                --openParenthesesCount;
            }
        }
    }

    for(i = --n; i > -1; --i) {
        if(openParenthesesCount > 0 && arr[i] == '(') {
            arr[i] = '*';
            --openParenthesesCount;
        }
    }


    for(i = 0; i <= n; ++i) {
        if(arr[i] != '*')
            result.push_back(arr[i]);
    }

    return result;
}

void test(string s, string expected) {
    cout << "String: " << "\"" << s << "\"" << endl;

    cout << "Expected: " << "\"" << expected << "\"" << endl;

    cout << "Result: " << "\"" << minRemoveToMakeValid(s) << "\"" << endl;

    cout << endl;
}

int main() {
    test("lee(t(c)o)de)", "lee(t(c)o)de");
    test("a)b(c)d", "ab(c)d");
    test("))((", "");
    test("abcdef", "abcdef");
    test("(a(b(c)d)", "(a(bc)d)");

    return 0;
}
