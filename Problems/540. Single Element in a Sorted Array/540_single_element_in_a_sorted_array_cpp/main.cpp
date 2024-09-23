#include <iostream>
#include <vector>

using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();

    int a = 0;
    int b = n - 1;

    while(a <= b) {
        int c = (a + b) / 2;

        if(c == 0 || c == n - 1) {
            return nums[c];
        }

        if(nums[c - 1] < nums[c] && nums[c] < nums[c + 1]) {
            return nums[c];
        }

        if(c % 2 == 0) {
            if(nums[c - 1] == nums[c]) {
                b = --c;
            } else {
                a = ++c;
            }
        } else {
            if(nums[c - 1] == nums[c]) {
                a = ++c;
            } else {
                b = --c;
            }
        }
    }

    return 0;
}

void testSingleNonDuplicate(vector<int>& nums, int expected) {
    cout << "Input: ";
    for (int n : nums) {
        cout << n << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << singleNonDuplicate(nums) << endl;

    cout << endl;
}

int main() {
    vector<int> nums1 = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    testSingleNonDuplicate(nums1, 2);

    vector<int> nums2 = {3, 3, 7, 7, 10, 11, 11};
    testSingleNonDuplicate(nums2, 10);

    vector<int> nums3 = {1, 1, 2};
    testSingleNonDuplicate(nums3, 2);

    vector<int> nums4 = {0, 0, 1, 1, 2, 2, 3};
    testSingleNonDuplicate(nums4, 3);

    vector<int> nums5 = {5};
    testSingleNonDuplicate(nums5, 5);

    return 0;
}
