#include <iostream>
#include <vector>

using namespace std;

bool checkXMatrix(vector<vector<int>>& grid) {
    int n = grid.size();

    int diagonal = 0;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(j == diagonal || j == n - diagonal - 1) {
                if(grid[i][j] == 0) {
                    return false;
                }
            } else if(grid[i][j] != 0) {
                return false;
            }
        }
        diagonal++;
    }

    return true;
}

void printMatrix(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> matrix, bool expected) {
    cout << "Matrix:" << endl;
    printMatrix(matrix);

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (checkXMatrix(matrix) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test({{2, 0, 0, 1},
          {0, 3, 1, 0},
          {0, 5, 2, 0},
          {4, 0, 0, 2}}, true);

    test({{2, 0, 0, 1},
          {0, 0, 1, 0},
          {0, 5, 2, 0},
          {4, 0, 0, 2}}, false);

    test({{5, 0, 0, 0, 1},
          {0, 3, 0, 2, 0},
          {0, 0, 4, 0, 0},
          {0, 7, 0, 6, 0},
          {9, 0, 0, 0, 8}}, true);

    test({{5, 0, 0, 0, 1},
          {0, 3, 0, 2, 0},
          {0, 1, 4, 0, 0},
          {0, 7, 0, 6, 0},
          {9, 0, 0, 0, 8}}, false);

    test({{1}}, true);

    test({{0}}, false);

    return 0;
}
