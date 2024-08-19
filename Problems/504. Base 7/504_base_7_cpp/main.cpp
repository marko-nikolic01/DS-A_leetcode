#include <iostream>
#include <string>

using namespace std;

string convertToBase7(int num) {
    if(num == 0) {
        return "0";
    }

    string reversedBase7 = "";
    bool isNegative = false;

    if(num < 0) {
        isNegative = true;
        num = -num;
    }

    while(num > 0) {
        reversedBase7 += to_string(num % 7);
        num /= 7;
    }

    string base7 = "";
    int n = reversedBase7.length() - 1;
    for(n; n > -1; --n) {
        base7 += reversedBase7[n];
    }

    return isNegative ? '-' + base7 : base7;
}

void testConvertToBase7() {
    struct TestCase {
        int number;
        string expected;
    };

    TestCase testCases[] = {
        {0, "0"},
        {7, "10"},
        {8, "11"},
        {49, "100"},
        {100, "202"},
        {-7, "-10"},
        {-8, "-11"},
        {-49, "-100"},
        {-100, "-202"}
    };

    for (const auto& testCase : testCases) {
        string result = convertToBase7(testCase.number);
        cout << "Number: " << testCase.number << endl;
        cout << "Expected: " << testCase.expected << endl;
        cout << "Result: " << result << endl;
        cout << endl;
    }
}

int main() {
    testConvertToBase7();
    return 0;
}
