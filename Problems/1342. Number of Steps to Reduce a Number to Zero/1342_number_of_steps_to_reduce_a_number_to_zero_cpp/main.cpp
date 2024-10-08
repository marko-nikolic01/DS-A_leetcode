#include <iostream>

using namespace std;

int numberOfSteps(int num) {
    int steps = 0;

    while(num > 0) {
        if(num % 2 == 0) {
            num /= 2;
        } else {
            num--;
        }

        steps++;
    }

    return steps;
}

void testNumberOfSteps(int input, int expected) {
    cout << "Input: " << input << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numberOfSteps(input) << endl;

    cout << endl;
}

int main()
{
    testNumberOfSteps(14, 6);
    testNumberOfSteps(8, 4);
    testNumberOfSteps(123, 12);
    testNumberOfSteps(0, 0);
    testNumberOfSteps(1, 1);
    testNumberOfSteps(2, 2);

    return 0;
}
