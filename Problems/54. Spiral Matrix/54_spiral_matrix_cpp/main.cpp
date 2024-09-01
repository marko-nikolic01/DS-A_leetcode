#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> spiral = {};

    int n = matrix.size();
    int m = matrix[0].size();

    int minX = 0;
    int maxX = n;
    int minY = -1;
    int maxY = m - 1;

    int stepX = 0;
    int stepY = 1;

    int size = 0;

    int x = 0;
    int y = -1;
    while(size < n * m) {
        x += stepX;
        y += stepY;

        spiral.push_back(matrix[x][y]);
        size++;

        if(x == minX && y == maxY) {
            stepX = 1;
            stepY = 0;
            maxX--;
        } else if(x == maxX && y == maxY) {
            stepX = 0;
            stepY = -1;
            minY++;
        } else if(x == maxX && y == minY) {
            stepX = -1;
            stepY = 0;
            minX++;
        } else if(x == minX && y == minY) {
            stepX = 0;
            stepY = 1;
            maxY--;
        }
    }

    return spiral;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

void runTest(vector<vector<int>>& matrix, const vector<int>& expected) {
    cout << "Matrix:" << endl;;
    printMatrix(matrix);

    cout << "Expected: ";
    for (int num : expected) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Result: ";
    for (int num : spiralOrder(matrix)) {
        cout << num << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    vector<int> expected1 = {1, 2, 3, 6, 9, 8, 7, 4, 5};
    runTest(matrix1, expected1);

    vector<vector<int>> matrix2 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    vector<int> expected2 = {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};
    runTest(matrix2, expected2);

    vector<vector<int>> matrix3 = {
        {1}
    };
    vector<int> expected3 = {1};
    runTest(matrix3, expected3);

    vector<vector<int>> matrix4 = {
        {1, 2},
        {3, 4}
    };
    vector<int> expected4 = {1, 2, 4, 3};
    runTest(matrix4, expected4);

    return 0;
}
