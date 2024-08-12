#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> distinct;

    for(int i = 0; i < nums.size(); ++i) {
        if(distinct.find(nums[i]) != distinct.end()) {
            return true;
        }
        distinct.insert(nums[i]);
    }
    return false;
}

void printResult(const vector<int>& nums, bool result, bool expected) {
    cout << "Input: [";
    for(size_t i = 0; i < nums.size(); ++i) {
        if (i != 0) cout << ", ";
        cout << nums[i];
    }
    cout << "]\nExpected: " << (expected ? "True" : "False") << "\n";
    cout << "Result: " << (result ? "True" : "False") << "\n\n";
}

int main() {
    vector<int> nums1 = {1, 2, 3, 4, 5};
    bool result1 = containsDuplicate(nums1);
    printResult(nums1, result1, false);

    vector<int> nums2 = {1, 2, 3, 2, 5};
    bool result2 = containsDuplicate(nums2);
    printResult(nums2, result2, true);

    vector<int> nums3 = {1, 1, 1, 1, 1};
    bool result3 = containsDuplicate(nums3);
    printResult(nums3, result3, true);

    return 0;
}
