#include <iostream>
#include <vector>

using namespace std;

int numDecodings(string s) {
    if(s[0] == '0') {
        return 0;
    }

    int n = s.length();

    if(n == 1) {
        return 1;
    }

    vector<int> counts(n, 0);

    counts[n - 1] = s[n - 1] == '0' ? 0 : 1;

    int number = s[n - 1] - '0';
    if(s[n - 2] == '0') {
        counts[n - 2] = 0;
    } else if((s[n - 2] - '0') * 10 + number > 26) {
        counts[n - 2] = counts[n - 1];
    } else {
        counts[n - 2] = 1 + counts[n - 1];
    }

    number = s[n - 2] - '0';

    for(n = n - 3; n > -1; --n) {
        if(s[n] == '0') {
            counts[n] = 0;
        } else if((s[n] - '0') * 10 + number > 26) {
            counts[n] = counts[n + 1];
        }  else {
            counts[n] = counts[n + 1] + counts[n + 2];
        }

        number = s[n] - '0';
    }

    return counts[0];
}

void runTest(string s, int expected) {
    cout << "Input: \"" << s << "\"" <<endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numDecodings(s) << endl;

    cout << endl;
}

int main() {
    runTest("12", 2);
    runTest("226", 3);
    runTest("06", 0);
    runTest("11106", 2);
    runTest("0", 0);
    runTest("10", 1);
    runTest("27", 1);
    runTest("101", 1);
    runTest("123123", 9);

    return 0;
}
