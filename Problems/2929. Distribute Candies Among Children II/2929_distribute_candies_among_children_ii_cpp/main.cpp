#include <iostream>

using namespace std;

long long distributeCandies(int n) {
    if (n < 0) {
        return 0;
    }
    return (long)n * (n - 1) / 2;
}

long long distributeCandies(int n, int limit) {
    return distributeCandies(n + 2) - 3 * distributeCandies(n - limit + 1) + 3 * distributeCandies(n - (limit + 1) * 2 + 2) - distributeCandies(n - 3 * (limit + 1) + 2);
}

void test(int n, int limit, int expected) {
    cout << "Candies: " << n << endl;

    cout << "Limit: " << limit << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << distributeCandies(n, limit) << endl;

    cout << endl;
}

int main() {
    test(5, 2, 3);
    test(3, 3, 10);
    test(6, 2, 1);
    test(1, 1, 3);
    test(4, 2, 6);

    return 0;
}
