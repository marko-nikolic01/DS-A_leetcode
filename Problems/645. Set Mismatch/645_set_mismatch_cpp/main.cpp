#include <iostream>
#include <vector>

using namespace std;

vector<int> findErrorNums(vector<int>& nums) {
    int n = nums.size();
    vector<int> found(n, 0);

    int missing = 0;

    vector<int> result;

    for(int i = 0; i < n; ++i) {
        missing ^= i + 1;

        if(found[nums[i] - 1] == 0) {
            found[nums[i] - 1]++;
            missing ^= nums[i];
        } else {
            result.push_back(nums[i]);
        }
    }

    result.push_back(missing);

    return result;
}

void runTest(vector<int> nums, vector<int> expected) {
    cout << "Input: ";
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> result = findErrorNums(nums);

    cout << "Expected: ";
    for(int num : expected) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Result: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    vector<int> nums1 = {1, 2, 2, 4};
    vector<int> expected1 = {2, 3};
    runTest(nums1, expected1);

    vector<int> nums2 = {3, 2, 2};
    vector<int> expected2 = {2, 1};
    runTest(nums2, expected2);

    vector<int> nums3 = {1, 1};
    vector<int> expected3 = {1, 2};
    runTest(nums3, expected3);

    vector<int> nums4 = {4, 3, 3, 1};
    vector<int> expected4 = {3, 2};
    runTest(nums4, expected4);

    vector<int> nums5 = {2, 2};
    vector<int> expected5 = {2, 1};
    runTest(nums5, expected5);

    return 0;
}
