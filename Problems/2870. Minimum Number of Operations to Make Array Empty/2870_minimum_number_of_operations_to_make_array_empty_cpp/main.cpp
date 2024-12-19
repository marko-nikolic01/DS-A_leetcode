#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int minOperations(vector<int>& nums) {
    unordered_map<int, int> occurences;

    for(int i = nums.size() - 1; i > -1; --i) {
        if(occurences.find(nums[i]) == occurences.end()) {
            occurences[nums[i]] = 1;
        } else {
            ++occurences[nums[i]];
        }
    }

    int operations = 0;

    for (unordered_map<int, int>::iterator it = occurences.begin(); it != occurences.end(); ++it) {
        if(it->second == 1) {
            return -1;
        }

        operations += it->second / 3;

        if(it->second % 3 > 0) {
            ++operations;
        }
    }

    return operations;
}

void test(vector<int> nums, int expected) {
    cout << "Input: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minOperations(nums) << endl;

    cout << endl;
}

int main() {
    vector<int> nums1 = {2, 3, 3, 2, 2, 4, 2, 3, 4};
    test(nums1, 4);

    vector<int> nums2 = {2, 1, 2, 2, 3, 3};
    test(nums2, -1);

    vector<int> nums3 = {1, 2, 3};
    test(nums3, -1);

    vector<int> nums4 = {1, 1, 2, 2, 3, 3};
    test(nums4, 3);

    vector<int> nums5 = {1, 1, 1, 2, 2, 2, 3, 3, 3};
    test(nums5, 3);

    vector<int> nums6 = {1, 5, 2, 6, 6, 6, 5, 1, 2, 6, 6, 2, 6, 7, 7, 6};
    test(nums6, 7);

    return 0;
}
