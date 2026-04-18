#include <iostream>

using namespace std;

int mirrorDistance(int n) {
    int distance = n;
    int mirror = 0;

    while(n > 0) {
        mirror = 10 * mirror + n % 10;
        n /= 10;
    }

    return abs(distance - mirror);
}

void test(int n, int expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << mirrorDistance(n) << endl;

    cout << endl;
}

int main() {
    test(25, 27);
    test(10, 9);
    test(7, 0);
    test(120, 99);
    test(123, 198);

    return 0;
}
