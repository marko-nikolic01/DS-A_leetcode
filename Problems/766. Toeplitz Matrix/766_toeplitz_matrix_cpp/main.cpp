#include <iostream>
#include <vector>

using namespace std;

bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    int x = matrix.size();
    int y = matrix[0].size();

    for(int i = 1; i < x; ++i) {
        for(int j = 1; j < y; j++) {
            if(matrix[i - 1][j - 1] != matrix[i][j]) {
                return false;
            }
        }
    }

    return true;
}

void runTest(vector<vector<int>> matrix, bool expected) {
    cout << "Matrix: " << endl;
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (isToeplitzMatrix(matrix) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    runTest({{1, 2, 3, 4}, {5, 1, 2, 3}, {9, 5, 1, 2}}, true);

    runTest({{1, 2}, {2, 2}}, false);

    runTest({{1, 2, 3}, {4, 1, 2}, {7, 4, 1}}, true);

    runTest({{3, 7, 0, 9}, {1, 3, 7, 0}, {2, 1, 3, 7}}, true);

    runTest({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, false);

    return 0;
}
