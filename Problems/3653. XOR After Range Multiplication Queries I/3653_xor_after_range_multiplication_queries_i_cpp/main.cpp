#include <iostream>
#include <vector>

using namespace std;

int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
    short i;
    int n = queries.size();
    for(i = 0; i < n; ++i) {
        for(queries[i][0]; queries[i][0] <= queries[i][1]; queries[i][0] += queries[i][2]) {
            nums[queries[i][0]] = ((long)nums[queries[i][0]] * queries[i][3]) % 1000000007;
        }
    }

    n = nums[0];

    for(i = nums.size() - 1; i > 0; --i) {
        n ^= nums[i];
    }

    return n;
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
        cout << "[" << query[0] << ", " << query[1] << ", " << query[2] << ", " << query[3] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << xorAfterQueries(nums, queries) << endl;

    cout << endl;
}

int main() {
    test({1, 1, 1}, {{0, 2, 1, 4}}, 4);
    test({2, 3, 1, 5, 4}, {{1, 4, 2, 3}, {0, 2, 1, 2}}, 31);
    test({5, 2, 3}, {{0, 2, 1, 2}}, 8);
    test({1, 2, 3, 4, 5}, {{0, 4, 2, 2}, {1, 3, 1, 3}}, 16);
    test({10, 20, 30}, {{0, 1, 1, 5}, {1, 2, 1, 2}}, 198);

    return 0;
}
