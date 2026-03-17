#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int largestSubmatrix(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int submatrix = 0;
    vector<int> currentRow;

    int j;
    for(int i = 0; i < m; ++i) {
        for(j = 0; j < n; ++j) {
            if(matrix[i][j] != 0 && i > 0) {
                matrix[i][j] += matrix[i - 1][j];
            }
        }

        currentRow = matrix[i];
        sort(currentRow.begin(), currentRow.end(), greater());

        for(j = 0; j < n; ++j) {
            if(currentRow[j] * (j + 1) > submatrix) {
                submatrix = currentRow[j] * (j + 1);
            }
        }
    }

    return submatrix;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> matrix, int expected) {
    cout << "Matrix:" << endl;
    printMatrix(matrix);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << largestSubmatrix(matrix) << endl;

    cout << endl;
}

int main() {
    test({{0, 0, 1}, {1, 1, 1}, {1, 0, 1}}, 4);
    test({{1, 0, 1, 0, 1}}, 3);
    test({{1, 1, 0}, {1, 0, 1}}, 2);
    test({{0, 0, 0}, {0, 0, 0}}, 0);
    test({{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}, 9);

    return 0;
}
