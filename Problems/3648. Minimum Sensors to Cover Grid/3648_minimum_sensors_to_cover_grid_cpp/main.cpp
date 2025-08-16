#include <iostream>

using namespace std;

int minSensors(int n, int m, int k) {
    k <<= 1;

    if(n % ++k > 0) {
        n = n / k + 1;
    } else {
        n /= k;
    }

    if(m % k > 0) {
        m = m / k + 1;
    } else {
        m /= k;
    }

    return n * m;
}

void test(int n, int m, int k, int expected) {
    cout << "n: " << n << endl;

    cout << "m: " << m << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minSensors(n, m, k) << endl;

    cout << endl;
}

int main() {
    test(5, 5, 1, 4);
    test(2, 2, 2, 1);
    test(10, 10, 2, 4);
    test(7, 5, 1, 6);
    test(3, 8, 0, 24);

    return 0;
}
