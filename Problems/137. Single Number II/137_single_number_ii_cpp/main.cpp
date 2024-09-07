#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int singleNumber(vector<int>& nums) {
    int number = 0;

    unordered_map<int, int> occurences;

    for(int n = nums.size() - 1; n > -1; --n) {
        if(occurences.find(nums[n]) == occurences.end()) {
            occurences[nums[n]] = 0;
        }

        if(occurences[nums[n]] < 2) {
            number ^= nums[n];
            occurences[nums[n]]++;
        }
    }

    return number;
}

void testSingleNumber(vector<int> nums, int expected) {
    cout << "Input: [";
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result:   " << singleNumber(nums) << endl;

    cout << endl;
}

int main() {
    vector<int> nums1 = {2, 2, 3, 2};
    int expected1 = 3;
    testSingleNumber(nums1, expected1);

    vector<int> nums2 = {0, 1, 0, 1, 0, 1, 99};
    int expected2 = 99;
    testSingleNumber(nums2, expected2);

    vector<int> nums3 = {-1, -1, -1, -2, -2, -2, -3};
    int expected3 = -3;
    testSingleNumber(nums3, expected3);

    vector<int> nums4 = {5, 5, 5, 1};
    int expected4 = 1;
    testSingleNumber(nums4, expected4);

    vector<int> nums5 = {7};
    int expected5 = 7;
    testSingleNumber(nums5, expected5);

    return 0;
}
