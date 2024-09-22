#include <iostream>
#include <vector>

using namespace std;

int findTargetSumWays(vector<int>& nums, int target, int start) {
    if(start < 0) {
        if(target == 0) {
            return 1;
        }
        return 0;
    }

    return findTargetSumWays(nums, target + nums[start], start - 1) + findTargetSumWays(nums, target - nums[start--], start);
}

int findTargetSumWays(vector<int>& nums, int target) {
    return findTargetSumWays(nums, target, nums.size() - 1);
}

void runTest(vector<int> nums, int target, int expected) {
    cout << "Input: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Target: " << target << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << findTargetSumWays(nums, target) << endl;

    cout << endl;
}

int main() {
    runTest({1, 1, 1, 1, 1}, 3, 5);

    runTest({1}, 1, 1);

    runTest({1, 2, 3}, 4, 1);

    runTest({2, 3, 5}, 8, 0);

    runTest({1, 2}, 4, 0);

    return 0;
}
