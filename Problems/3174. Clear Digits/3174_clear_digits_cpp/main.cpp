#include <iostream>
#include <vector>

using namespace std;

string clearDigits(const string& s) {
    vector<char> cleared;

    int clear = 0;

    for (int i = s.length() - 1; i >= 0; --i) {
        if (s[i] >= '0' && s[i] <= '9') {
            clear++;
        } else if (clear > 0) {
            clear--;
        } else {
            cleared.push_back(s[i]);
        }
    }

    return string(cleared.rbegin(), cleared.rend());
}

void runTestCase(const string& input, const string& expected) {
    cout << "Input: \"" << input << "\"" << endl;

    cout << "Expected: \"" << expected << "\"" << endl;

    cout << "Result: \"" << clearDigits(input) << "\"" << endl;

    cout << endl;
}

int main() {
    runTestCase("abc123", "");
    runTestCase("a1b2c3", "");
    runTestCase("123abc456", "");
    runTestCase("a1b2c", "c");
    runTestCase("123", "");
    runTestCase("abc", "abc");
    runTestCase("ab1c2d3e", "ae");
    runTestCase("12ab34cd56", "");

    return 0;
}
