#include <iostream>

using namespace std;

string toHex(int num) {
    if (num == 0) {
        return "0";
    }

    string hex = "";
    const char digits[] = "0123456789abcdef";

    while (num != 0 && hex.length() < 8) {
        hex = digits[num & 15] + hex;
        num = num >> 4;
    }

    return hex;
}

int main()
{
    int testNumbers[] = {0, 1, 15, 16, 255, 256, -1, -16, 123456789};
    int numTestCases = sizeof(testNumbers) / sizeof(testNumbers[0]);

    for (int i = 0; i < numTestCases; ++i) {
        int num = testNumbers[i];
        string hex = toHex(num);
        cout << "Number: " << num << " Hex: " << hex << endl << endl;
    }

    return 0;
}
