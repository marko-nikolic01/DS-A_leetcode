#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>> transposedMatrix(n--, vector<int> (m));

    for(--m; m > -1; --m) {
        for(int j = n; j > -1; --j) {
            transposedMatrix[j][m] = matrix[m][j];
        }
    }

    return transposedMatrix;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}

void testTranspose(vector<vector<int>>& matrix, vector<vector<int>>& expected) {
    cout << "Matrix:" << endl;
    printMatrix(matrix);

    cout << "Expected:" << endl;
    printMatrix(expected);

    cout << "Result:" << endl;
    printMatrix(transpose(matrix));

    cout << endl;
}

int main() {
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6}
    };
    vector<vector<int>> expected1 = {
        {1, 4},
        {2, 5},
        {3, 6}
    };
    testTranspose(matrix1, expected1);

    vector<vector<int>> matrix2 = {
        {1, 2},
        {3, 4},
        {5, 6}
    };
    vector<vector<int>> expected2 = {
        {1, 3, 5},
        {2, 4, 6}
    };
    testTranspose(matrix2, expected2);

    vector<vector<int>> matrix3 = {
        {7, 8},
        {9, 10}
    };
    vector<vector<int>> expected3 = {
        {7, 9},
        {8, 10}
    };
    testTranspose(matrix3, expected3);

    vector<vector<int>> matrix4 = {
        {1}
    };
    vector<vector<int>> expected4 = {
        {1}
    };
    testTranspose(matrix4, expected4);

    vector<vector<int>> matrix5 = {
        {1, 2, 3, 4}
    };
    vector<vector<int>> expected5 = {
        {1},
        {2},
        {3},
        {4}
    };
    testTranspose(matrix5, expected5);

    vector<vector<int>> matrix6 = {
        {1},
        {2},
        {3},
        {4}
    };
    vector<vector<int>> expected6 = {
        {1, 2, 3, 4}
    };
    testTranspose(matrix6, expected6);

    return 0;
}
