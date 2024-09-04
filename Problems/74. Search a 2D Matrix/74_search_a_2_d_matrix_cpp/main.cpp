#include <iostream>
#include <vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix[0].size();

    int a = 0;
    int b = matrix.size() * n - 1;

    while(a <= b) {
        int c = (a + b) / 2;

        if(matrix[c / n][c % n] == target) {
            return true;
        } else if(matrix[c / n][c % n] < target) {
            a = ++c;
        } else {
            b = --c;
        }
    }

    return false;
}
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

void testSearchMatrix(vector<vector<int>>& matrix, int target, bool expected) {
    cout << "Matrix:" << endl;
    printMatrix(matrix);

    cout << "Target: " << target << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (searchMatrix(matrix, target) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    vector<vector<int>> testCase1 = {
        {1, 3, 5},
        {7, 9, 11},
        {13, 15, 17}
    };
    testSearchMatrix(testCase1, 9, true);

    vector<vector<int>> testCase2 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    testSearchMatrix(testCase2, 5, true);

    vector<vector<int>> testCase3 = {
        {10, 20, 30},
        {40, 50, 60},
        {70, 80, 90}
    };
    testSearchMatrix(testCase3, 25, false);

    vector<vector<int>> testCase4 = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    testSearchMatrix(testCase4, 13, false);

    return 0;
}
