#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minimumCost(vector<int>& cost) {
    short c = 0;

    sort(cost.begin(), cost.end());

    for(short i = cost.size() - 1; i > -1; --i) {
        c += cost[i];

        if(i > 1) {
            c += cost[--i];
            --i;
        }
    }

    return c;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> cost, int expected) {
    cout << "Costs: ";
    printArray(cost);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minimumCost(cost) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 3}, 5);
    test({6, 5, 7, 9, 2, 2}, 23);
    test({5, 5}, 10);
    test({7}, 7);
    test({4, 4, 4, 4, 4, 4}, 16);

    return 0;
}
