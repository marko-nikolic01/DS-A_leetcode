#include <iostream>

using namespace std;

string reverseOnlyLetters(string s) {
    int a = 0;
    int b = s.length() - 1;

    while(a < b) {
        if((s[a] < 'A' || s[a] > 'Z') && (s[a] < 'a' || s[a] > 'z')) {
            a++;
        } else if((s[b] < 'A' || s[b] > 'Z') && (s[b] < 'a' || s[b] > 'z')) {
            b--;
        } else {
            char temp = s[a];
            s[a++] = s[b];
            s[b--] = temp;
        }
    }

    return s;
}

void runTest(const string& input, const string& expected) {
    cout << "Input: \"" << input << "\"" << endl;

    cout << "Expected: \"" << expected << "\"" << endl;

    cout << "Result: \"" << reverseOnlyLetters(input) << "\"" << endl;

    cout << endl;
}

int main() {
    runTest("ab-cd", "dc-ba");
    runTest("a-bC-dEf-ghIj", "j-Ih-gfE-dCba");
    runTest("Test1ng-Leet=code-Q!", "Qedo1ct-eeLg=ntse-T!");
    runTest("7_28]", "7_28]");
    runTest("", "");
    runTest("abc", "cba");

    return 0;
}
