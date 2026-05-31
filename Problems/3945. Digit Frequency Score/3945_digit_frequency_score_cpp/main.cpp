#include <iostream>

using namespace std;

int digitFrequencyScore(int n) {
    short score = 0;

    while(n > 0) {
        score += n % 10;
        n /= 10;
    }

    return score;
}

void test(int n, int expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << digitFrequencyScore(n) << endl;

    cout << endl;
}

int main() {
    test(122, 5);
    test(101, 2);
    test(999, 27);
    test(111, 3);
    test(123, 6);

    return 0;
}
