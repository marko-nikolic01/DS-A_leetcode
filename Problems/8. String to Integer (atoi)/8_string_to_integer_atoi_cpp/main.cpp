#include <iostream>
#include <climits>

using namespace std;

int myAtoi(string s) {
    long integer = 0;
    bool isNegative = false;

    int i = 0;
    int n = s.length();

    while (i < n && s[i] == ' ') {
        i++;
    }

    if (i < n && (s[i] == '+' || s[i] == '-')) {
        isNegative = (s[i] == '-');
        i++;
    }

    while(i < n) {
        if(s[i] != '0') {
            break;
        }
        i++;
    }

    while (i < n && s[i] >= '0' && s[i] <= '9') {
        int digit = s[i] - '0';

        if (integer > INT_MAX / 10 || (integer == INT_MAX / 10 && digit > (isNegative ? 8 : 7))) {
            return isNegative ? INT_MIN : INT_MAX;
        }

        integer = integer * 10 + digit;
        i++;
    }

    return isNegative ? -integer : integer;
}

void testMyAtoi(string s, int expected) {
    cout << "Input: \"" << s << "\"" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << myAtoi(s) << endl;

    cout << endl;
}

int main() {
    testMyAtoi("42", 42);
    testMyAtoi("   -42", -42);
    testMyAtoi("4193 with words", 4193);
    testMyAtoi("words and 987", 0);
    testMyAtoi("-91283472332", INT_MIN);
    testMyAtoi("91283472332", INT_MAX);
    testMyAtoi("  +00123", 123);
    testMyAtoi("-000000000000001", -1);
    testMyAtoi("2147483648", INT_MAX);
    testMyAtoi("-2147483649", INT_MIN);

    return 0;
}
