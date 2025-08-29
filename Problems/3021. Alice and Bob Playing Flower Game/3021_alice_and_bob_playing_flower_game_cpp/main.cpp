#include <iostream>

using namespace std;

long long flowerGame(int n, int m) {
    return ((long)n * m) >> 1;
}

void test(int n, int m, long long expected) {
    cout << "n: " << n << endl;

    cout << "m: " << m << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << flowerGame(n, m) << endl;

    cout << endl;
}

int main() {
    test(3, 2, 3);
    test(1, 1, 0);
    test(4, 4, 8);
    test(5, 7, 17);
    test(10, 1, 5);

    return 0;
}
