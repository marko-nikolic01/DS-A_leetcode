#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void permute(vector<int>& nums, vector<vector<int>>& permutations, vector<int>& permutation, int index) {
    int n = nums.size();
    if(index == n) {
        permutations.push_back(permutation);
        return;
    }

    for(int i = index; i < n; ++i) {
        permutation.push_back(nums[i]);

        int temp = nums[i];
        nums[i] = nums[index];
        nums[index] = nums[i];

        permute(nums, permutations, permutation, index + 1);

        permutation.pop_back();

        nums[index] = nums[i];
        nums[i] = temp;
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> permutations;
    vector<int> permutation;

    permute(nums, permutations, permutation, 0);

    return permutations;
}

void printResult(const vector<int>& input, const vector<vector<int>>& expected, const vector<vector<int>>& result) {
    cout << "Input: [";
    for(size_t i = 0; i < input.size(); ++i) {
        cout << input[i];
        if(i < input.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << "Expected: [";
    for(size_t i = 0; i < expected.size(); ++i) {
        cout << "[";
        for(size_t j = 0; j < expected[i].size(); ++j) {
            cout << expected[i][j];
            if(j < expected[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if(i < expected.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << "Result: [";
    for(size_t i = 0; i < result.size(); ++i) {
        cout << "[";
        for(size_t j = 0; j < result[i].size(); ++j) {
            cout << result[i][j];
            if(j < result[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if(i < result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << endl;
}

int main() {
    vector<int> nums1 = {1, 2, 3};
    vector<vector<int>> expected1 = {
        {1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}
    };
    sort(expected1.begin(), expected1.end());
    vector<vector<int>> result1 = permute(nums1);
    sort(result1.begin(), result1.end());
    printResult(nums1, expected1, result1);

    vector<int> nums2 = {0, 1};
    vector<vector<int>> expected2 = {
        {0, 1}, {1, 0}
    };
    sort(expected2.begin(), expected2.end());
    vector<vector<int>> result2 = permute(nums2);
    sort(result2.begin(), result2.end());
    printResult(nums2, expected2, result2);

    vector<int> nums3 = {1};
    vector<vector<int>> expected3 = {
        {1}
    };
    vector<vector<int>> result3 = permute(nums3);
    printResult(nums3, expected3, result3);

    return 0;
}
