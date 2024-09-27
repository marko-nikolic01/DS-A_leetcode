#include <iostream>

using namespace std;

long long waysToBuyPensPencils(int total, int cost1, int cost2) {
    long long ways = 0;

    while(total > -1) {
        ways += total / cost2 + 1;
        total -= cost1;
    }

    return ways;
}

void test(int total, int cost1, int cost2, long long expected) {
    cout << "Money: " << total << endl;

    cout << "Pen price: " << cost1 << endl;

    cout << "Pencil price: " << cost2 << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << waysToBuyPensPencils(total, cost1, cost2) << endl;

    cout << endl;
}

int main()
{
    test(20, 10, 5, 9);
    test(5, 10, 10, 1);
    test(15, 5, 3, 13);
    test(0, 5, 2, 1);
    test(30, 7, 4, 23);
    test(10, 100, 1, 11);

    return 0;
}
