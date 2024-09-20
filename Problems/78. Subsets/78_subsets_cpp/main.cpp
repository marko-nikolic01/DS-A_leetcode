#include <iostream>
#include <vector>

using namespace std;

 void subsets(vector<int>& nums, vector<vector<int>>& subsetsList, vector<int>& subset, int index) {
    subsetsList.push_back(subset);

    int n = nums.size();
    if(index == n) {
        return;
    }

    for(index; index < n; ++index) {
        subset.push_back(nums[index]);
        subsets(nums, subsetsList, subset, index + 1);
        subset.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> subsetsList = {};
    vector<int> subset = {};

    subsets(nums, subsetsList, subset, 0);

    return subsetsList;
}

void printVector(const vector<int>& vec) {
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout << vec[i];
        if (i < vec.size() - 1) cout << ", ";
    }
    cout << "]";
}

void testSubsets(const vector<int>& input, const vector<vector<int>>& expected) {
    vector<vector<int>> result = subsets(const_cast<vector<int>&>(input));

    cout << "Input: ";
    printVector(input);
    cout << endl;

    cout << "Expected: ";
    for (const auto& vec : expected) {
        printVector(vec);
        cout << " ";
    }
    cout << endl;

    cout << "Result: ";
    for (const auto& vec : result) {
        printVector(vec);
        cout << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    vector<int> input1 = {};
    vector<vector<int>> expected1 = {{}};
    testSubsets(input1, expected1);

    vector<int> input2 = {1};
    vector<vector<int>> expected2 = { {}, {1} };
    testSubsets(input2, expected2);

    vector<int> input3 = {1, 2};
    vector<vector<int>> expected3 = { {}, {1}, {1, 2}, {2} };
    testSubsets(input3, expected3);

    vector<int> input4 = {1, 2, 3};
    vector<vector<int>> expected4 = { {}, {1}, {1, 2}, {1, 2, 3}, {1, 3}, {2}, {2, 3}, {3} };
    testSubsets(input4, expected4);

    vector<int> input5 = {1, 2, 3, 4};
    vector<vector<int>> expected5 = { {}, {1}, {1, 2}, {1, 2, 3}, {1, 2, 3, 4}, {1, 2, 4}, {1, 3}, {1, 3, 4}, {1, 4}, {2}, {2, 3}, {2, 3, 4}, {2, 4}, {3}, {3, 4}, {4} };
    testSubsets(input5, expected5);

    return 0;
}
