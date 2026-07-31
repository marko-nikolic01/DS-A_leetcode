#include <iostream>

using namespace std;

int smallestNumber(int n, int t) {
    auto check = [&](short num) -> bool {
        short product = 1;

        while(num) {
            product *= num % 10;
            num /= 10;

            if(!product) {
                break;
            }
        }

        return !(product % t);
    };

    while (!check(n)) {
        ++n;
    }

    return n;
}

void test(int n, int t, int expected) {
    cout << "n: " << n << endl;

    cout << "t: " << t << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << smallestNumber(n, t) << endl;

    cout << endl;
}

int main() {
    test(10, 2, 10);
    test(15, 3, 16);
    test(1, 1, 1);
    test(5, 5, 5);
    test(20, 4, 20);

    return 0;
}
