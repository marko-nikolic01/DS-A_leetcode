#include <iostream>

using namespace std;

string toLowerCase(string s) {
    int n = s.length();
    for(int i = 0; i < n; ++i) {
        if(s[i] >= 65 && s[i] <= 90) {
            s[i] += 32;
        }
    }

    return s;
}

void runTest(const string& input, const string& expected) {
    string result = toLowerCase(input);

    cout << "Input: " << input << endl;
    cout << "Expected: " << expected << endl;
    cout << "Result: " << result << endl;
    cout << endl;
}

int main() {
    runTest("Hello World", "hello world");

    runTest("C++ Programming", "c++ programming");

    runTest("TEST CASE", "test case");

    runTest("lowercase", "lowercase");

    runTest("UPPERCASE123", "uppercase123");

    runTest("lowercase123", "lowercase123");

    return 0;
}
