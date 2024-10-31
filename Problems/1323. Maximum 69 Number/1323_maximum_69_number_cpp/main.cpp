#include <iostream>

using namespace std;

int maximum69Number (int num) {
    int powerOf10 = 1;
    int powerOf10At6 = 0;

    int copy = num;
    while(copy > 0) {
        if(copy % 10 == 6) {
            powerOf10At6 = powerOf10;
        }
        copy /= 10;
        powerOf10 *= 10;
    }

    return num + 3 * powerOf10At6;
}

void runTest(int num, int expected) {
    cout << "Number: " << num << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maximum69Number(num) << endl;

    cout << endl;
}

int main() {
    runTest(9669, 9969);
    runTest(9996, 9999);
    runTest(9999, 9999);
    runTest(6969, 9969);
    runTest(6696, 9696);
    runTest(6666, 9666);
    runTest(6966, 9966);
    runTest(6699, 9699);
    runTest(9696, 9996);
    runTest(6669, 9669);
    runTest(666, 966);
    runTest(69, 99);
    runTest(96, 99);
    runTest(999, 999);
    runTest(66969, 96969);
    runTest(6, 9);
    runTest(9, 9);

    return 0;
}

