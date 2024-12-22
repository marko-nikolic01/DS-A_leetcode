#include <iostream>
#include <vector>

using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    vector<int> occurences(20001, 0);

    for(int i = nums.size() - 1; i > -1; --i) {
        ++occurences[10000 - nums[i]];
    }

    for(int i = 0; i < 20001; ++i) {
        k -= occurences[i];
        if(k < 1) {
            return 10000 - i;
        }
    }

    return 0;
}

void printTestCase(vector<int> nums, int k, int expected) {
    cout << "Input: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << findKthLargest(nums, k) << endl;

    cout << endl;
}

int main() {
    vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    int k1 = 2;
    printTestCase(nums1, k1, 5);

    vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k2 = 4;
    printTestCase(nums2, k2, 4);

    vector<int> nums3 = {1, 2};
    int k3 = 1;
    printTestCase(nums3, k3, 2);

    vector<int> nums4 = {1};
    int k4 = 1;
    printTestCase(nums4, k4, 1);

    vector<int> nums5 = {-1, -2, -3, -4, -5};
    int k5 = 3;
    printTestCase(nums5, k5, -3);

    return 0;
}
