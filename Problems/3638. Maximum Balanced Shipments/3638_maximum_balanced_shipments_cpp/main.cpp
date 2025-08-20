#include <iostream>
#include <vector>

using namespace std;

int maxBalancedShipments(vector<int>& weight) {
    int balancedShipments = 0;
    int maxWeight = 0;

    int n = weight.size();
    for(int i = 1; i < n; ++i) {
        if(weight[i] < weight[maxWeight]) {
            ++balancedShipments;
            ++i;
        }

        maxWeight = i;
    }

    return balancedShipments;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> weight, int expected) {
    cout << "Weights: ";
    printArray(weight);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxBalancedShipments(weight) << endl;

    cout << endl;
}

int main() {
    test({2, 5, 1, 4, 3}, 2);
    test({4, 4}, 0);
    test({1, 2, 3, 4, 5}, 0);
    test({5, 4, 3, 2, 1}, 2);
    test({1, 7, 2, 6, 4, 3}, 2);
    test({3, 5, 1, 4, 2}, 2);

    return 0;
}
