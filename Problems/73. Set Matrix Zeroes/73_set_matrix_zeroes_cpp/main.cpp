#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    unordered_set<int> rows;
    unordered_set<int> columns;

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(matrix[i][j] == 0) {
                rows.insert(i);
                columns.insert(j);
            }
        }
    }

    for(unordered_set<int>::iterator it = rows.begin(); it != rows.end(); ++it) {
        for(int i = 0; i < n; ++i) {
            matrix[*it][i] = 0;
        }
    }

    for(unordered_set<int>::iterator it = columns.begin(); it != columns.end(); ++it) {
        for(int i = 0; i < m; ++i) {
            matrix[i][*it] = 0;
        }
    }
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

void testSetZeroes(vector<vector<int>>& matrix, const vector<vector<int>>& expected) {
    cout << "Matrix:" << endl;
    printMatrix(matrix);

    cout << "Expected:" << endl;
    printMatrix(expected);

    setZeroes(matrix);
    cout << "Result:" << endl;
    printMatrix(matrix);

    cout << endl;
}

int main() {
    vector<vector<int>> testCase1 = {
        {1, 2, 3},
        {4, 0, 6},
        {7, 8, 9}
    };
    vector<vector<int>> expected1 = {
        {1, 0, 3},
        {0, 0, 0},
        {7, 0, 9}
    };
    testSetZeroes(testCase1, expected1);

    vector<vector<int>> testCase2 = {
        {1, 0, 3},
        {4, 5, 6},
        {0, 8, 9}
    };
    vector<vector<int>> expected2 = {
        {0, 0, 0},
        {0, 0, 6},
        {0, 0, 0}
    };
    testSetZeroes(testCase2, expected2);

    return 0;
}
