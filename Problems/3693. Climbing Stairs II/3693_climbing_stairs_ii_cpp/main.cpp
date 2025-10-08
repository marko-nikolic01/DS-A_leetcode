#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n, vector<int>& costs) {
    vector<int> stairs(n + 1, 2147483647);
    stairs[0] = 0;

    int i;
    n -= 2;
    for(i = 0; i < n; ++i) {
        stairs[i + 1] = min(stairs[i + 1], stairs[i] + costs[i] + 1);
        stairs[i + 2] = min(stairs[i + 2], stairs[i] + costs[i + 1] + 4);
        stairs[i + 3] = min(stairs[i + 3], stairs[i] + costs[i + 2] + 9);
    }

    stairs[i + 1] = min(stairs[i + 1], stairs[i] + costs[i] + 1);

    n += 2;
    if(i + 2 <= n) {
        stairs[i + 2] = min(stairs[i + 2], stairs[i] + costs[i + 1] + 4);
        ++i;
        stairs[i + 1] = min(stairs[i + 1], stairs[i] + costs[i] + 1);
    }


    return stairs[n];
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(int n, vector<int> costs, int expected) {
    cout << "Steps: " << n << endl;

    cout << "Costs: ";
    printArray(costs);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << climbStairs(n, costs) << endl;

    cout << endl;
}

int main() {
    test(4, {1, 2, 3, 4}, 13);
    test(4, {5, 1, 6, 2}, 11);
    test(3, {9, 8, 3}, 12);
    test(5, {3, 2, 4, 1, 5}, 17);
    test(6, {1, 3, 2, 5, 4, 6}, 23);

    return 0;
}
