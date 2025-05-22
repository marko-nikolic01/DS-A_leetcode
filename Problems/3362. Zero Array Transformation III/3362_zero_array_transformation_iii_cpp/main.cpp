#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
    sort(queries.begin(), queries.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });

    priority_queue<int> heap;
    vector<int> deltaArray(nums.size() + 1, 0);
    int operations = 0;

    for(int i = 0, j = 0; i < nums.size(); ++i) {
        operations += deltaArray[i];

        while (j < queries.size() && queries[j][0] == i) {
            heap.push(queries[j][1]);
            ++j;
        }

        while (operations < nums[i] && !heap.empty() && heap.top() >= i) {
            operations += 1;
            deltaArray[heap.top() + 1] -= 1;
            heap.pop();
        }

        if (operations < nums[i]) {
            return -1;
        }
    }

    return heap.size();
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, vector<vector<int>> queries, int expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Queries: ";
    for(vector<int> query : queries) {
        cout << "[" << query[0] << ", " << query[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxRemoval(nums, queries) << endl;

    cout << endl;
}

int main() {
    test({2, 0, 2}, {{0, 2}, {0, 2}, {1, 1}}, 1);
    test({1, 2, 3, 4}, {{0, 3}}, -1);
    test({1, 1, 1, 1}, {{1, 3}, {0, 2}, {1, 3}, {1, 2}}, 2);
    test({0, 0, 0}, {{0, 2}, {1, 2}}, 2);
    test({1, 1, 1}, {{0, 1}, {0, 1}, {2, 2}}, 1);

    return 0;
}
