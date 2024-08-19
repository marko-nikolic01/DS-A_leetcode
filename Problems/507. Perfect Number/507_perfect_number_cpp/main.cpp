#include <iostream>

using namespace std;

bool checkPerfectNumber(int num) {
    int sum = 0;

    for(int i = 1; i < num / 2 + 1; ++i) {
        if(num % i == 0) {
            sum += i;
        }
    }

    return sum == num;
}

void runTest(int number, bool expected) {
    bool result = checkPerfectNumber(number);

    cout << "Number: " << number << endl;
    cout << "Expected: " << (expected ? "true" : "false") << endl;
    cout << "Result: " << (result ? "true" : "false") << endl << endl;
}

int main() {
    runTest(28, true);
    runTest(6, true);
    runTest(12, false);
    runTest(496, true);
    runTest(7, false);

    return 0;
}
