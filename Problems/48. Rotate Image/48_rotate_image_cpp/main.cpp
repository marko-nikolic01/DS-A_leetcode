#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();

    for(int i = 0; i < n / 2; ++i) {
        for(int j = i; j < n - i - 1; ++j) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[n - j - 1][i];
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
            matrix[j][n - i - 1] = temp;
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

int main() {
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    cout << "Matrix:" << endl;
    printMatrix(matrix1);
    rotate(matrix1);
    cout << "Result:" << endl;
    printMatrix(matrix1);
    cout << endl;

    vector<vector<int>> matrix2 = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}
    };
    cout << "Matrix" << endl;
    printMatrix(matrix2);
    rotate(matrix2);
    cout << "Result:" << endl;
    printMatrix(matrix2);
    cout << endl;

    vector<vector<int>> matrix3 = {
        {1}
    };
    cout << "Matrix:" << endl;
    printMatrix(matrix3);
    rotate(matrix3);
    cout << "Result:" << endl;
    printMatrix(matrix3);
    cout << endl;

    vector<vector<int>> matrix4 = {
        {1, 2},
        {3, 4}
    };
    cout << "Matrix:" << endl;
    printMatrix(matrix4);
    rotate(matrix4);
    cout << "Result:" << endl;
    printMatrix(matrix4);
    cout << endl;

    return 0;
}
