#include <iostream>
#include <vector>

using namespace std;

int findMiddleIndex(vector<int>& nums) {
    int sum = 0;

    int n = nums.size();
    for(int i = 0; i < n; ++i) {
        sum += nums[i];
    }

    int currentSum = 0;

    for(int i = 0; i < n; ++i) {
        if(currentSum == sum - nums[i] - currentSum) {
            return i;
        }
        currentSum += nums[i];
    }

    return -1;
}

void runTestCase(vector<int> nums, int expected) {
    cout << "Input: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << findMiddleIndex(nums) << endl;

    cout << endl;
}

int main() {
    runTestCase({2, 3, -1, 8, 4}, 3);
    runTestCase({1, 2, 3}, -1);
    runTestCase({1, 1, 1, 1, 1}, 2);
    runTestCase({0, 0, 0, 0, 0}, 0);
    runTestCase({-1, -1, -1, -1, -1}, 2);

    return 0;
}
