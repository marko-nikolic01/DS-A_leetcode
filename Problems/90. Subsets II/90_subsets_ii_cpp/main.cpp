#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void subsetsWithDup(vector<int>& nums, vector<vector<int>>& subsets, vector<int>& subset, int start) {
    int n = nums.size();
    for(int i = start; i < n; ++i) {
        if(nums[i] != nums[start]) {
            subsetsWithDup(nums, subsets, subset, i);
            break;
        } else if(i > start) {
            continue;
        }

        subset.push_back(nums[i]);
        subsets.push_back(subset);
        subsetsWithDup(nums, subsets, subset, i + 1);
        subset.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> subsets = {{}};
    vector<int> subset;

    subsetsWithDup(nums, subsets, subset, 0);

    return subsets;
}

void printSubsets(const vector<vector<int>>& subsets) {
    cout << "[";
    for (size_t i = 0; i < subsets.size(); ++i) {
        cout << "[";
        for (size_t j = 0; j < subsets[i].size(); ++j) {
            cout << subsets[i][j];
            if (j < subsets[i].size() - 1) cout << ", ";
        }
        cout << "]";
        if (i < subsets.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

void runTest(vector<int>& nums, const string& expected) {
    cout << "Input: [";
    for (size_t i = 0; i < nums.size(); ++i) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: ";
    printSubsets(subsetsWithDup(nums));

    cout << endl;
}

int main() {
    vector<int> test1 = {1, 2, 3};
    runTest(test1, "[[], [1], [1, 2], [1, 2, 3], [1, 3], [2], [2, 3], [3]]");

    vector<int> test2 = {1, 2, 2};
    runTest(test2, "[[], [1], [1, 2], [1, 2, 2], [2], [2, 2]]");

    vector<int> test3 = {2, 2, 2};
    runTest(test3, "[[], [2], [2, 2], [2, 2, 2]]");

    vector<int> test4 = {};
    runTest(test4, "[[]]");

    return 0;
}
