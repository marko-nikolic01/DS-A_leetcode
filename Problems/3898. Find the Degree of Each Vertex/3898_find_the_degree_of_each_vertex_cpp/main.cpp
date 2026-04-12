#include <iostream>
#include <vector>

using namespace std;

vector<int> findDegrees(vector<vector<int>>& matrix) {
    short j;
    short n = matrix.size();
    for(short i = 0; i < n; ++i) {
        matrix[0][i] = 0;

        for(j = 0; j < n; ++j) {
            if(matrix[i][j] > 0) {
                ++matrix[0][i];
            }
        }
    }

    return matrix[0];
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> mat, vector<int> expected) {
    cout << "Matrix:" << endl;
    printMatrix(mat);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(findDegrees(mat));

    cout << endl;
}

int main() {
    test({{0, 1, 1}, {1, 0, 1}, {1, 1, 0}}, {2, 2, 2});
    test({{0, 1, 0}, {1, 0, 0}, {0, 0, 0}}, {1, 1, 0});
    test({{0}}, {0});
    test({{0, 1, 1, 1}, {1, 0, 0, 0}, {1, 0, 0, 0}, {1, 0, 0, 0}}, {3, 1, 1, 1});
    test({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, {0, 0, 0});

    return 0;
}
