#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int findClosestNumber(vector<int>& nums) {
    int positive = INT_MAX;
    int negative = INT_MIN;

    for(int i = nums.size() - 1; i > -1; --i) {
        if(nums[i] > 0) {
            if(nums[i] < positive) {
                positive = nums[i];
            }
        } else if(nums[i] > negative) {
            negative = nums[i];
        }
    }

    return negative == INT_MIN || positive <= -negative ? positive : negative;
}

void test(vector<int> nums, int expected) {
    int result = findClosestNumber(nums);
    cout << "Input: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << findClosestNumber(nums) << endl;

    cout << endl;
}

int main()
{
    test({-4, -2, 1, 4, 8}, 1);
    test({-4, -2, -1, 4, 8}, -1);
    test({1, 2, 3, 4}, 1);
    test({-3, -2, -1}, -1);
    test({0, -5, 5, 10}, 0);
    test({-7, -2, -6, 4, 6}, -2);
    test({-100}, -100);
    test({0}, 0);

    return 0;
}
