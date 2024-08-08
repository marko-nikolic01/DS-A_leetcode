#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int a = 0, b = nums.size() - 1;

    while(a <= b) {
        int current = (a + b) / 2;
        if(nums[current] == target) {
            return current;
        } else if(nums[current] > target) {
            b = current - 1;
        } else {
            a = current + 1;
        }
    }

    return a;
}

void testSearchInsert(vector<int>& nums, int target, int expected) {
    int result = searchInsert(nums, target);
    cout << "nums: { ";
    for(int num : nums) cout << num << " ";
    cout << "}, target: " << target << " -> result: " << result << ", expected: " << expected << endl;
    cout << (result == expected ? "Test Passed" : "Test Failed") << endl;
}

int main() {
    cout << "Running tests for searchInsert function..." << endl;

    vector<int> nums1 = {1, 3, 5, 6};
    testSearchInsert(nums1, 5, 2);

    vector<int> nums2 = {1, 3, 5, 6};
    testSearchInsert(nums2, 2, 1);

    vector<int> nums3 = {1, 3, 5, 6};
    testSearchInsert(nums3, 7, 4);

    vector<int> nums4 = {1, 3, 5, 6};
    testSearchInsert(nums4, 0, 0);

    vector<int> nums5 = {};
    testSearchInsert(nums5, 1, 0);

    vector<int> nums6 = {1};
    testSearchInsert(nums6, 0, 0);

    vector<int> nums7 = {1};
    testSearchInsert(nums7, 2, 1);

    cout << "All tests completed." << endl;

    return 0;
}
