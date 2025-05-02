#include <iostream>

using namespace std;

int findClosest(int x, int y, int z) {
    x = abs(z - x);
    y = abs(z - y);

    return x < y ? 1 : (x > y ? 2 : 0);
}

void test(int x, int y, int z, int expected) {
    cout << "x: " << x << endl;

    cout << "y: " << y << endl;

    cout << "z: " << z << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << findClosest(x, y, z) << endl;

    cout  << endl;
}

int main() {
    test(1, 2, 3, 2);
    test(5, 3, 4, 0);
    test(-2, 7, 1, 1);
    test(10, 1, 5, 2);
    test(100, 100, 100, 0);

    return 0;
}
