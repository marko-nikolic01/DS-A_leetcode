#include <iostream>
#include <vector>

using namespace std;

int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size(), sum = 0, k = 0;
    vector<int> differenceArray(n + 1);

    for (int index = 0; index < n; index++) {
        while (sum + differenceArray[index] < nums[index]) {
            k++;

            if (k > queries.size()) {
                return -1;
            }
            int left = queries[k - 1][0], right = queries[k - 1][1],
                val = queries[k - 1][2];

            if (right >= index) {
                differenceArray[max(left, index)] += val;
                differenceArray[right + 1] -= val;
            }
        }

        sum += differenceArray[index];
    }
    return k;
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
        cout << "[" << query[0] << ", " << query[1] << ", " << query[2] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minZeroArray(nums, queries) << endl;

    cout << endl;
}

int main() {
    test({2, 0, 2}, {{0, 2, 1}, {0, 2, 1}, {1, 1, 3}}, 2);
    test({4, 3, 2, 1}, {{1, 3, 2}, {0, 2, 1}}, -1);
    test({0, 0, 0}, {{0, 2, 1}, {0, 1, 2}}, 0);
    test({1, 1, 1}, {{0, 2, 1}}, 1);
    test({3, 2, 5}, {{0, 0, 1}, {2, 2, 2}, {0, 2, 2}, {0, 2, 1}}, 4);

    return 0;
}
