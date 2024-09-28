#include <iostream>

using namespace std;

long long coloredCells(int n) {
    return 2l * n-- * n + 1l;
}

void testColoredCells(int n, long long expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << coloredCells(n) << endl;

    cout << endl;
}

int main() {
    testColoredCells(1, 1);
    testColoredCells(2, 5);
    testColoredCells(3, 13);
    testColoredCells(4, 25);
    testColoredCells(5, 41);
    testColoredCells(6, 61);
    testColoredCells(7, 85);
    testColoredCells(8, 113);
    testColoredCells(9, 145);
    testColoredCells(10, 181);

    return 0;
}
