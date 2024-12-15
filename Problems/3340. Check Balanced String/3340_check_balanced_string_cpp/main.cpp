#include <iostream>

using namespace std;

bool isBalanced(string num) {
    int n = num.length();

    for(int i = 1; i < n; i += 2) {
        num[0] -= num[i];
    }

    for(int i = 2; i < n; i += 2) {
        num[0] += num[i];
    }

    return (n & 1) == 1 ? num[0] == '0' : num[0] == 0;
}

void test(string num, bool expected) {
    cout << "Number: " << num << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (isBalanced(num) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test("123321", true);
    test("123456", false);
    test("112233", true);
    test("111", false);
    test("21", false);
    test("1357", false);
    test("121", true);

    return 0;
}
