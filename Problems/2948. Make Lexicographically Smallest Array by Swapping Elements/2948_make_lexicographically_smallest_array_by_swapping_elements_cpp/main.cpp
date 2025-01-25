#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
    vector<int> numsCopy = nums;
    sort(numsCopy.begin(), numsCopy.end());

    vector<vector<int>> groups;
    unordered_map<int, int> groupNumbers;
    int groupNumber = 0;

    int n = nums.size();
    for(int i = 0; i < n; ++i) {
        groups.push_back({numsCopy[i]});
        groupNumbers[numsCopy[i]] = groupNumber;

        while(++i < n && numsCopy[i] - numsCopy[i - 1] <= limit) {
            groups[groupNumber].push_back(numsCopy[i]);
            groupNumbers[numsCopy[i]] = groupNumber;
        }

        ++groupNumber;

        --i;
    }

    for(--n; n > -1; --n) {
        nums[n] = groups[groupNumbers[nums[n]]].back();
        groups[groupNumbers[nums[n]]].pop_back();
    }

    return nums;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void printTestCase(vector<int> nums, int limit, vector<int> expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result:   ";
    printArray(lexicographicallySmallestArray(nums, limit));

    cout << endl;
}

int main() {
    vector<int> nums1 = {1, 5, 3, 9, 8};
    int limit1 = 2;
    vector<int> expected1 = {1, 3, 5, 8, 9};
    printTestCase(nums1, limit1, expected1);

    vector<int> nums2 = {1, 7, 6, 18, 2, 1};
    int limit2 = 3;
    vector<int> expected2 = {1, 6, 7, 18, 1, 2};
    printTestCase(nums2, limit2, expected2);

    vector<int> nums3 = {1, 7, 28, 19, 10};
    int limit3 = 3;
    vector<int> expected3 = {1, 7, 28, 19, 10};
    printTestCase(nums3, limit3, expected3);

    vector<int> nums4 = {1, 60, 34, 84, 62, 56, 39, 76, 49, 38};
    int limit4 = 4;
    vector<int> expected4 = {1, 56, 34, 84, 60, 62, 38, 76, 49, 39};
    printTestCase(nums4, limit4, expected4);

    vector<int> nums5 = {10, 20, 30, 40, 50};
    int limit5 = 15;
    vector<int> expected5 = {10, 20, 30, 40, 50};
    printTestCase(nums5, limit5, expected5);

    vector<int> nums6 = {5, 10, 15, 25, 20, 30};
    int limit6 = 10;
    vector<int> expected6 = {5, 10, 15, 20, 25, 30};
    printTestCase(nums6, limit6, expected6);

    vector<int> nums7 = {100, 90, 80, 70, 60, 50};
    int limit7 = 10;
    vector<int> expected7 = {50, 60, 70, 80, 90, 100};
    printTestCase(nums7, limit7, expected7);

    return 0;
}
