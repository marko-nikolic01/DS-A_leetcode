#include <iostream>

using namespace std;

int differenceOfSums(int n, int m) {
    return n * (n + 1) / 2 - m * (n / m) * (n / m + 1);
}

void test(int n, int m, int expected) {
    cout << "n: " << n << endl;

    cout << "m: " << m << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << differenceOfSums(n, m) << endl;

    cout << endl;
}

int main()
{
    test(10, 3, 19);
    test(5, 6, 15);
    test(5, 1, -15);
    test(1, 1, -1);
    test(1, 2, 1);
    test(27, 7, 294);

    return 0;
}
