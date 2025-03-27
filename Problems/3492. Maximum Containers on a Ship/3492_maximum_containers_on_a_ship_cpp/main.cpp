#include <iostream>

using namespace std;

int maxContainers(int n, int w, int maxWeight) {
    return min(maxWeight / w, n * n);
}

void test(int n, int w, int maxWeight, int expected) {
    cout << "n: " << n << endl;

    cout << "Container weight: " << w << endl;

    cout << "Maximum weight: " << w << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxContainers(n, w, maxWeight) << endl;

    cout << endl;
}

int main() {
    test(2, 3, 15, 4);
    test(3, 5, 20, 4);
    test(1, 1, 1, 1);
    test(4, 10, 50, 5);
    test(5, 100, 2000, 20);

    return 0;
}
