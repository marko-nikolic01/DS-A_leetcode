#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void permuteUnique(vector<int>& nums, vector<vector<int>>& permutations, vector<int>& permutation, int index) {
    int n = nums.size();
    if(index == n) {
        permutations.push_back(permutation);
        return;
    }

    unordered_set<int> used;

    for(int i = index; i < n; ++i) {
        if(used.find(nums[i]) != used.end()) {
            continue;
        }
        used.insert(nums[i]);

        permutation.push_back(nums[i]);

        int temp = nums[i];
        nums[i] = nums[index];
        nums[index] = temp;

        permuteUnique(nums, permutations, permutation, index + 1);

        permutation.pop_back();

        nums[index] = nums[i];
        nums[i] = temp;
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> permutations;
    vector<int> permutation;

    permuteUnique(nums, permutations, permutation, 0);

    return permutations;
}

void printResult(const vector<int>& input, const vector<vector<int>>& result, const vector<vector<int>>& expected) {
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
    vector<int> nums1 = {1, 1, 2};
    vector<vector<int>> result1 = permuteUnique(nums1);
    vector<vector<int>> expected1 = {{1, 1, 2}, {1, 2, 1}, {2, 1, 1}};
    printResult(nums1, result1, expected1);

    vector<int> nums2 = {1, 2, 3};
    vector<vector<int>> result2 = permuteUnique(nums2);
    vector<vector<int>> expected2 = {{1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};
    printResult(nums2, result2, expected2);

    vector<int> nums3 = {1};
    vector<vector<int>> result3 = permuteUnique(nums3);
    vector<vector<int>> expected3 = {{1}};
    printResult(nums3, result3, expected3);

    vector<int> nums4 = {1, 2, 2};
    vector<vector<int>> result4 = permuteUnique(nums4);
    vector<vector<int>> expected4 = {{1, 2, 2}, {2, 1, 2}, {2, 2, 1}};
    printResult(nums4, result4, expected4);

    return 0;
}
