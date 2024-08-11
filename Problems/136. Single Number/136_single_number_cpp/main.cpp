#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
    int result = 0;

    for(int i = 0; i < nums.size(); ++i) {
        result ^= nums[i];
    }

    return result;
}

int main() {
    vector<int> nums1 = {4, 1, 2, 1, 2};
    vector<int> nums2 = {2, 2, 1};
    vector<int> nums3 = {1, 4, 4};
    vector<int> nums4 = {7};

    cout << "Single number in [4, 1, 2, 1, 2]: " << singleNumber(nums1) << endl;
    cout << "Single number in [2, 2, 1]: " << singleNumber(nums2) << endl;
    cout << "Single number in [1, 4, 4]: " << singleNumber(nums3) << endl;
    cout << "Single number in [7]: " << singleNumber(nums4) << endl;

    return 0;
}
