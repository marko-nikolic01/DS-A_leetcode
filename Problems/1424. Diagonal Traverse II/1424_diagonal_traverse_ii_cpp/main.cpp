#include <iostream>
#include <vector>

using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    vector<int> traversal;

    int m = nums.size();

    int diagonalsSize = m;
    vector<vector<int>> diagonals(diagonalsSize);

    for(--m; m > -1; --m) {
        int n = nums[m].size();
        for(int j = 0; j < n; ++j) {
            if(m + j >= diagonalsSize) {
                diagonals.push_back({nums[m][j]});
                ++diagonalsSize;
            } else {
                diagonals[m + j].push_back(nums[m][j]);
            }
        }
    }

    for(++m; m < diagonalsSize; ++m) {
        traversal.insert(traversal.end(), diagonals[m].begin(), diagonals[m].end());
    }

    return traversal;
}

void printMatrix(vector<vector<int>> matrix) {
    for (vector<int> row : matrix) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> nums, vector<int> expected) {
    cout << "Matrix:" << endl;
    printMatrix(nums);

    cout << "Expected: ";
    for (int e : expected) {
        cout << e << " ";
    }
    cout << endl;

    cout << "Result: ";
    for (int result : findDiagonalOrder(nums)) {
        cout << result << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    vector<vector<int>> nums1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> expected1 = {1, 4, 2, 7, 5, 3, 8, 6, 9};
    test(nums1, expected1);

    vector<vector<int>> nums2 = {{1, 2, 3, 4, 5}, {6, 7}, {8}, {9, 10, 11}, {12, 13, 14, 15, 16}};
    vector<int> expected2 = {1, 6, 2, 8, 7, 3, 9, 4, 12, 10, 5, 13, 11, 14, 15, 16};
    test(nums2, expected2);

    vector<vector<int>> nums3 = {{1}};
    vector<int> expected3 = {1};
    test(nums3, expected3);

    vector<vector<int>> nums4 = {{1, 2}, {3}};
    vector<int> expected4 = {1, 3, 2};
    test(nums4, expected4);

    vector<vector<int>> nums5 = {{1}, {2}, {3}};
    vector<int> expected5 = {1, 2, 3};
    test(nums5, expected5);

    return 0;
}
