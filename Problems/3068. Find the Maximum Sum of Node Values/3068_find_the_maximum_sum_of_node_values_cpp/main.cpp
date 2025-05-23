#include <iostream>
#include <vector>

using namespace std;

long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
    long long sum = 0;
    int count = 0, positiveMinimum = (1 << 30), negativeMaximum = -1 * (1 << 30);

    for(int nodeValue : nums) {
        int operatedNodeValue = nodeValue ^ k;
        sum += nodeValue;
        int netChange = operatedNodeValue - nodeValue;

        if(netChange > 0) {
            positiveMinimum = min(positiveMinimum, netChange);
            sum += netChange;
            count++;
        } else {
            negativeMaximum = max(negativeMaximum, netChange);
        }
    }

    if(count % 2 == 0) {
        return sum;
    }

    return max(sum - positiveMinimum, sum + negativeMaximum);
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int k, vector<vector<int>> edges, long long expected) {
    cout << "Values: ";
    printArray(nums);

    cout << "k: " << k << endl;

    cout << "Edges: ";
    for(vector<int> edge : edges) {
        cout << "[" << edge[0] << ", " << edge[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maximumValueSum(nums, k, edges) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 1}, 3, {{0, 1}, {0, 2}}, 6);
    test({2, 3}, 7, {{0, 1}}, 9);
    test({7, 7, 7, 7, 7, 7}, 3, {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}}, 42);
    test({1, 1, 1, 1}, 4, {{0, 1}, {1, 2}, {2, 3}}, 20);
    test({8, 9, 10}, 5, {{0, 1}, {1, 2}}, 37);

    return 0;
}
