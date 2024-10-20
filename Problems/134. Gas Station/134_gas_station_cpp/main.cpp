#include <iostream>
#include <vector>

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int totalGas = 0;
    int totalCost = 0;

    int currentGas = 0;
    int startingPoint = 0;

    int n = gas.size();
    for(int i = 0; i < n; ++i) {
        if(currentGas < 0) {
            startingPoint = i;
            currentGas = 0;
        }

        totalGas += gas[i];
        totalCost += cost[i];

        currentGas += gas[i] - cost[i];
    }

    return totalCost > totalGas ? -1 : startingPoint;
}
void test(vector<int> gas, vector<int> cost, int expected) {
    cout << "Gas: ";
    for (int g : gas) {
        cout << g << " ";
    }
    cout << endl;

    cout << "Cost: ";
    for (int c : cost) {
        cout << c << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << canCompleteCircuit(gas, cost) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 3, 4, 5}, {3, 4, 5, 1, 2}, 3);
    test({2, 3, 4}, {3, 4, 3}, -1);
    test({4, 5, 2, 6, 5}, {3, 4, 3, 4, 5}, 0);
    test({1, 2, 3}, {2, 3, 1}, 2);
    test({5, 1, 2, 3, 4}, {4, 4, 1, 5, 1}, 4);

    return 0;
}
