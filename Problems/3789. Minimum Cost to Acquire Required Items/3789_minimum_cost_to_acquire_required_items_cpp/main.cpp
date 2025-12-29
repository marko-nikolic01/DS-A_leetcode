#include <iostream>

using namespace std;

long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
    return need1 < need2 ? (long)need1 * min(cost1 + cost2, costBoth) + (long)(need2 - need1) * min(cost2, costBoth) : (long)need2 * min(cost1 + cost2, costBoth) + (long)(need1 - need2) * min(cost1, costBoth);
}

void test(int cost1, int cost2, int costBoth, int need1, int need2, long long expected) {
    cout << "Cost 1: " << cost1 << endl;

    cout << "Cost 2: " << cost2 << endl;

    cout << "Cost both: " << costBoth << endl;

    cout << "Requirements 1: " << need1 << endl;

    cout << "Requirements 2: " << need2 << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minimumCost(cost1, cost2, costBoth, need1, need2) << endl;

    cout << endl;
}

int main() {
    test(3, 2, 1, 3, 2, 3);
    test(5, 4, 15, 2, 3, 22);
    test(5, 4, 15, 0, 0, 0);
    test(388168, 988887, 336014, 50411, 252237, 84755163318);
    test(4, 7, 6, 5, 1, 22);
    test(10, 10, 15, 100, 100, 1500);

    return 0;
}
