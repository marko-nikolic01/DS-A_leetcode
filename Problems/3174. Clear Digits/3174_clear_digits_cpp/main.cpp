#include <iostream>
#include <vector>

using namespace std;

string clearDigits(string s) {
    short index = 0;

    short n = s.size();
    for(short i = 0; i < n; ++i) {
        if(s[i] > '/' && s[i] < ':') {
            --index;
        } else {
            s[index++] = s[i];
        }
    }

    s.resize(index);

    return s;
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
    runTestCase("abc456", "");
    runTestCase("a1b2c", "c");
    runTestCase("aaa123", "");
    runTestCase("abc", "abc");
    runTestCase("ab1c2d3e", "ae");
    runTestCase("ab34cd56", "");

    return 0;
}
