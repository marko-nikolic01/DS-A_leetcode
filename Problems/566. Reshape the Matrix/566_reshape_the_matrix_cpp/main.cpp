#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    int rows = mat.size();
    int columns = mat[0].size();

    int size = c * r;
    if(rows * columns != size) {
        return mat;
    }

    vector<vector<int>> reshaped(r, vector<int>(c));

    for(int i = 0; i < size; ++i) {
        reshaped[i / c][i % c] = mat[i / columns][i % columns];
    }

    return reshaped;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> mat1 = {{1, 2}, {3, 4}};
    int r1 = 1, c1 = 4;
    cout << "Test Case 1:" << endl;
    cout << "Matrix:" << endl;
    printMatrix(mat1);
    cout << "Rows: " << mat1.size() << ", Columns: " << mat1[0].size() << endl;
    vector<vector<int>> reshaped1 = matrixReshape(mat1, r1, c1);
    cout << "Reshaped matrix (" << r1 << "x" << c1 << "):" << endl;
    printMatrix(reshaped1);
    cout << "Rows: " << reshaped1.size() << ", Columns: " << reshaped1[0].size() << endl;
    cout << endl;

    vector<vector<int>> mat2 = {{1, 2, 3, 4}, {5, 6, 7, 8}};
    int r2 = 4, c2 = 2;
    cout << "Test Case 2:" << endl;
    cout << "Matrix:" << endl;
    printMatrix(mat2);
    cout << "Rows: " << mat2.size() << ", Columns: " << mat2[0].size() << endl;
    vector<vector<int>> reshaped2 = matrixReshape(mat2, r2, c2);
    cout << "Reshaped matrix (" << r2 << "x" << c2 << "):" << endl;
    printMatrix(reshaped2);
    cout << "Rows: " << reshaped2.size() << ", Columns: " << reshaped2[0].size() << endl;
    cout << endl;

    vector<vector<int>> mat3 = {{1, 2, 3}, {4, 5, 6}};
    int r3 = 3, c3 = 2;
    cout << "Test Case 3:" << endl;
    cout << "Matrix:" << endl;
    printMatrix(mat3);
    cout << "Rows: " << mat3.size() << ", Columns: " << mat3[0].size() << endl;
    vector<vector<int>> reshaped3 = matrixReshape(mat3, r3, c3);
    cout << "Reshaped matrix (" << r3 << "x" << c3 << "):" << endl;
    printMatrix(reshaped3);
    cout << "Rows: " << reshaped3.size() << ", Columns: " << reshaped3[0].size() << endl;
    cout << endl;

    vector<vector<int>> mat4 = {{1, 2}, {3, 4}, {5, 6}};
    int r4 = 2, c4 = 3;
    cout << "Test Case 4:" << endl;
    cout << "Matrix:" << endl;
    printMatrix(mat4);
    cout << "Rows: " << mat4.size() << ", Columns: " << mat4[0].size() << endl;
    vector<vector<int>> reshaped4 = matrixReshape(mat4, r4, c4);
    cout << "Reshaped matrix (" << r4 << "x" << c4 << "):" << endl;
    printMatrix(reshaped4);
    cout << "Rows: " << reshaped4.size() << ", Columns: " << reshaped4[0].size() << endl;
    cout << endl;

    vector<vector<int>> mat5 = {{1, 2}, {3, 4}, {5, 6}};
    int r5 = 3, c5 = 2;
    cout << "Test Case 5:" << endl;
    cout << "Matrix:" << endl;
    printMatrix(mat5);
    cout << "Rows: " << mat5.size() << ", Columns: " << mat5[0].size() << endl;
    vector<vector<int>> reshaped5 = matrixReshape(mat5, r5, c5);
    cout << "Reshaped matrix (" << r5 << "x" << c5 << "):" << endl;
    printMatrix(reshaped5);
    cout << "Rows: " << reshaped5.size() << ", Columns: " << reshaped5[0].size() << endl;
    cout << endl;

    vector<vector<int>> mat6 = {{1, 2, 3, 4}};
    int r6 = 3, c6 = 2;
    cout << "Test Case 6:" << endl;
    cout << "Original matrix:" << endl;
    printMatrix(mat6);
    cout << "Rows: " << mat6.size() << ", Columns: " << mat6[0].size() << endl;
    vector<vector<int>> reshaped6 = matrixReshape(mat6, r6, c6);
    cout << "Reshaped matrix (" << r6 << "x" << c6 << "):" << endl;
    printMatrix(reshaped6);
    cout << "Rows: " << reshaped6.size() << ", Columns: " << reshaped6[0].size() << endl;

    return 0;
}
