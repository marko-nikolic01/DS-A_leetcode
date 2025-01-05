#include <iostream>

using namespace std;

int theMaximumAchievableX(int num, int t) {
   return num + 2 * t;
}

void test(int num, int t, int expected) {
    cout << "Number: " << num << endl;

    cout << "t: " << t << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << theMaximumAchievableX(num, t) << endl;

    cout << endl;
}

int main() {
    test(4, 1, 6);
    test(3, 2, 7);
    test(10, 3, 16);
    test(1, 5, 11);
    test(7, 4, 15);
    test(10, 10, 30);
    test(6, 8, 22);
    test(20, 2, 24);
    test(15, 6, 27);
    test(50, 1, 52);

    return 0;
}
