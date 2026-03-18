#include <iostream>
#include <vector>

using namespace std;

int countSubmatrices(vector<vector<int>>& grid, int k) {
    int submatrices = grid[0][0] <= k ? 1 : 0;
    int row;

    short i;
    short n = grid[0].size();
    for(i = 1; i < n; ++i) {
        grid[0][i] += grid[0][i - 1];

        if(grid[0][i] <= k) {
            ++submatrices;
        }
    }

    short j;
    short m = grid.size();
    for(i = 1; i < m; ++i) {
        row = grid[i][0];
        grid[i][0] += grid[i - 1][0];

        if(grid[i][0] <= k) {
            ++submatrices;
        }

        for(j = 1; j < n; ++j) {
            row += grid[i][j];
            grid[i][j] = row + grid[i - 1][j];

            if(grid[i][j] <= k) {
                ++submatrices;
            }
        }
    }

    return submatrices;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> grid, int k, int expected) {
    cout << "Matrix:" << endl;
    printMatrix(grid);

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countSubmatrices(grid, k) << endl;

    cout << endl;
}

int main() {
    test({{7, 6, 3}, {6, 6, 1}}, 18, 4);
    test({{7, 2, 9}, {1, 5, 0}, {2, 6, 6}}, 20, 6);
    test({{1, 10}, {7, 2}, {9, 1}, {4, 1}}, 8, 2);
    test({{9, 6, 1}, {5, 8, 10}, {4, 3, 9}, {8, 7, 8}}, 9, 1);
    test({{5}}, 5, 1);

    return 0;
}
