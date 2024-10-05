#include <iostream>
#include <vector>

using namespace std;

bool satisfiesConditions(vector<vector<int>>& grid) {
    int m = grid.size();

    for(int n = grid[0].size() - 1; n > -1; --n) {
        if(n > 0 && grid[0][n] == grid[0][n - 1]) {
            return false;
        }

        for(int i = 1; i < m; ++i) {
            if(grid[i][n] != grid[i - 1][n]) {
                return false;
            }
        }
    }

    return true;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

void runTestCase(vector<vector<int>>& matrix, bool expected) {
    cout << "Matrix:" << endl;
    printMatrix(matrix);

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (satisfiesConditions(matrix) ? "true" : "false") << endl;

    cout << endl;
}

int main()
{
    vector<vector<int>> testCase1 = {
        {1, 2, 3},
        {1, 2, 3},
        {1, 2, 3}
    };
    runTestCase(testCase1, true);

    vector<vector<int>> testCase2 = {
        {1, 2, 2},
        {1, 2, 3},
        {1, 2, 3}
    };
    runTestCase(testCase2, false);

    vector<vector<int>> testCase3 = {
        {1, 3, 5},
        {1, 3, 5},
        {1, 3, 5}
    };
    runTestCase(testCase3, true);

    vector<vector<int>> testCase4 = {
        {1, 2, 3},
        {1, 2, 4},
        {1, 2, 3}
    };
    runTestCase(testCase4, false);

    vector<vector<int>> testCase5 = {
        {1}
    };
    runTestCase(testCase5, true);

    return 0;
}
