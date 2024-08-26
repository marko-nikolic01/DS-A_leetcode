#include <iostream>
#include <vector>

using namespace std;

int dominantIndex(vector<int>& nums) {
    int max1 = 0;
    int max2 = -1;

    int n = nums.size();
    for(int i = 1; i < n; ++i) {
        if(nums[i] > nums[max1]) {
            max2 = max1;
            max1 = i;
        } else if(max2 == -1 || nums[i] > nums[max2]) {
            max2 = i;
        }
    }

    return nums[max1] >= 2 * nums[max2] ? max1 : -1;
}

void printTestCase(vector<int> nums, int expected) {
    cout << "Input: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << dominantIndex(nums) << endl;

    cout << endl;
}

int main() {
    vector<int> nums1 = {3, 6, 1, 0};
    int expected1 = 1;
    printTestCase(nums1, expected1);

    vector<int> nums2 = {1, 2, 3, 4};
    int expected2 = -1;
    printTestCase(nums2, expected2);

    vector<int> nums3 = {1, 2};
    int expected3 = 1;
    printTestCase(nums3, expected3);

    vector<int> nums4 = {0, 0, 0, 1};
    int expected4 = 3;
    printTestCase(nums4, expected4);

    vector<int> nums5 = {1, 2, 4, 8};
    int expected5 = 3;
    printTestCase(nums5, expected5);

    return 0;
}
