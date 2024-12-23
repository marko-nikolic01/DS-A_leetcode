#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> findMatrix(vector<int>& nums) {
    vector<vector<int>> result;

    vector<int> occurences(nums.size(), -1);
    for(int i = nums.size() - 1; i > -1; --i) {
        if(++occurences[nums[i] - 1] == result.size()) {
            result.push_back({nums[i]});
        } else {
            result[occurences[nums[i] - 1]].push_back(nums[i]);
        }
    }

    return result;
}

void printMatrix(vector<vector<int>> matrix) {
    for (vector<int> row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

void test(vector<int> nums, vector<vector<int>> expected) {
    cout << "Input: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected:" << endl;
    printMatrix(expected);

    cout << "Result:" << endl;
    printMatrix(findMatrix(nums));

    cout << endl;
}

int main() {
    vector<int> test1 = {1, 2, 2, 1, 1, 3};
    vector<vector<int>> expected1 = {{3, 1, 2}, {1, 2}, {1}};
    test(test1, expected1);

    vector<int> test2 = {4, 4, 4, 4};
    vector<vector<int>> expected2 = {{4}, {4}, {4}, {4}};
    test(test2, expected2);

    vector<int> test3 = {5, 1, 2, 2, 3, 3, 1};
    vector<vector<int>> expected3 = {{1, 3, 5, 2}, {3, 2, 1}};
    test(test3, expected3);

    vector<int> test4 = {1};
    vector<vector<int>> expected4 = {{1}};
    test(test4, expected4);

    vector<int> test5 = {1, 2, 3};
    vector<vector<int>> expected5 = {{3, 2, 1}};
    test(test5, expected5);

    return 0;
}
