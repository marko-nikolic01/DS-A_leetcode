#include <iostream>

using namespace std;

int countOdds(int low, int high) {
    return (++high >> 1) - (low >> 1);
}

void test(int low, int high, int expected) {
    cout << "Low: " << low << endl;

    cout << "High: " << high << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countOdds(low, high) << endl;

    cout << endl;
}

int main() {
    test(3, 7, 3);
    test(8, 10, 1);
    test(0, 0, 0);
    test(1, 1, 1);
    test(4, 15, 6);

    return 0;
}
