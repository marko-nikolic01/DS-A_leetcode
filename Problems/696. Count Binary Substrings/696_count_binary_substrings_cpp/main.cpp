#include <iostream>

using namespace std;

int countBinarySubstrings(string s) {
    int count = 0;

    int zeros = 0;
    int ones = 0;

    bool previous = false;

    int n = s.length();
    for(int i = 0; i < n; ++i) {
        if(s[i] == '0') {
            if(previous) {
                zeros = 0;
            }

            previous = false;
            zeros++;

            if(zeros <= ones) {
                count++;
            }
        } else {
            if(!previous) {
                ones = 0;
            }

            previous = true;
            ones++;

            if(ones <= zeros) {
                count++;
            }
        }
    }

    return count;
}

void runTest(string binary, int expected) {
    int result = countBinarySubstrings(binary);
    cout << "Binary: " << binary << endl;
    cout << "Expected: " << expected << endl;
    cout << "Result: " << result << endl;
    cout << endl;
}

int main() {
    runTest("00110011", 6);
    runTest("10101", 4);
    runTest("000111", 3);
    runTest("0000", 0);
    runTest("1111", 0);

    return 0;
}
