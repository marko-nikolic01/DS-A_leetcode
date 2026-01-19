#include <iostream>
#include <vector>

using namespace std;

int maxSideLength(vector<vector<int>>& grid, short x1, short y1, short x2, short y2) {
    return grid[x2][y2] - grid[x1 - 1][y2] - grid[x2][y1 - 1] + grid[x1 - 1][y1 - 1];
}

int maxSideLength(vector<vector<int>>& mat, int threshold) {
    short side = 0;
    short m = mat.size();
    short n = mat[0].size();
    vector<vector<int>> grid(m + 1, vector<int>(n + 1));

    short i;
    short j;
    for(i = 1; i <= m; ++i) {
        for(j = 1; j <= n; ++j) {
            grid[i][j] = grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1] + mat[i - 1][j - 1];
        }
    }

    short k;
    short o = min(m, n);
    for(i = 1; i <= m; ++i) {
        for(j = 1; j <= n; ++j) {
            for(k = side + 1; k <= o; ++k) {
                if(i + k - 1 <= m && j + k - 1 <= n && maxSideLength(grid, i, j, i + k - 1, j + k - 1) <= threshold) {
                    ++side;
                } else {
                    break;
                }
            }
        }
    }

    return side;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> mat, int threshold, int expected) {
    cout << "Matrix:" << endl;
    printMatrix(mat);

    cout << "Threshold: " << threshold << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxSideLength(mat, threshold) << endl;

    cout << endl;
}

int main() {
    test({{1, 1, 3, 2, 4, 3, 2}, {1, 1, 3, 2, 4, 3, 2}, {1, 1, 3, 2, 4, 3, 2}}, 4, 2);
    test({{2, 2, 2, 2, 2}, {2, 2, 2, 2, 2}, {2, 2, 2, 2, 2}, {2, 2, 2, 2, 2}, {2, 2, 2, 2, 2}}, 1, 0);
    test({{5}}, 5, 1);
    test({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, 4, 1);
    test({{1, 1}, {1, 1}}, 4, 2);

    return 0;
}
