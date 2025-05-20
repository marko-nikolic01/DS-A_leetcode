#include <iostream>
#include <vector>

using namespace std;

bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    vector<int> decrements(n + 1, 0);

    int i;
    for(i = queries.size() - 1; i > -1; --i) {
        ++decrements[queries[i][0]];
        --decrements[++queries[i][1]];
    }

    int currentDecrements = 0;

    for(i = 0; i < n; ++i) {
        currentDecrements += decrements[i];

        if(currentDecrements < nums[i]) {
            return false;
        }
    }

    return true;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, vector<vector<int>> queries, bool expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Queries: ";
    for(vector<int> query : queries) {
        cout << "[" << query[0] << ", " << query[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (isZeroArray(nums, queries) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test({1, 0, 1}, {{0, 2}}, true);
    test({4, 3, 2, 1}, {{1, 3}, {0, 2}}, false);
    test({1, 2, 1}, {{0, 2}, {1, 1}}, true);
    test({2, 1, 2}, {{0, 2}}, false);
    test({3, 3, 3}, {{0, 2}, {0, 2}, {0, 2}}, true);

    return 0;
}
