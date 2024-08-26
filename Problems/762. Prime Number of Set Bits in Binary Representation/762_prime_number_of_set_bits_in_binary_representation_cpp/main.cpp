#include <iostream>

using namespace std;

int countPrimeSetBits(int left, int right) {
    int count = 0;

    while(left <= right) {
        int num = left++;

        int bits = 0;

        while(num > 0) {
            bits += num & 1;
            num >>= 1;
        }

        if(bits == 2 || bits == 3 || bits == 5 || bits == 7 || bits == 11 || bits == 13 || bits == 17 || bits == 19) {
            count++;
        }
    }

    return count;
}

void runTest(int left, int right, int expected) {
    cout << "Range: [" << left << ", " << right << "]" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countPrimeSetBits(left, right) << endl;

    cout << endl;
}

int main() {
    runTest(6, 10, 4);

    runTest(10, 15, 5);

    runTest(1, 20, 14);

    runTest(500, 600, 55);

    runTest(1000, 1020, 7);

    return 0;
}
