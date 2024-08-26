#include <iostream>
#include <vector>

using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    for(int i = cost.size() - 3; i > -1; --i) {
        if(cost[i + 1] < cost[i + 2]) {
            cost[i] += cost[i + 1];
        } else {
            cost[i] += cost[i + 2];
        }
    }

    return cost[0] < cost[1] ? cost[0] : cost[1];
}

void printTestCase(vector<int> costs, int expected) {
    cout << "Costs: ";
    for (int c : costs) {
        cout << c << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minCostClimbingStairs(costs) << endl;

    cout << endl;
}

int main() {
    vector<int> costs1 = {10, 15, 20};
    int expected1 = 15;
    printTestCase(costs1, expected1);

    vector<int> costs2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    int expected2 = 6;
    printTestCase(costs2, expected2);

    vector<int> costs3 = {0, 0, 1, 1};
    int expected3 = 1;
    printTestCase(costs3, expected3);

    vector<int> costs4 = {1, 2, 3, 4, 5};
    int expected4 = 6;
    printTestCase(costs4, expected4);

    vector<int> costs5 = {10, 5, 15, 5, 10};
    int expected5 = 10;
    printTestCase(costs5, expected5);

    return 0;
}
