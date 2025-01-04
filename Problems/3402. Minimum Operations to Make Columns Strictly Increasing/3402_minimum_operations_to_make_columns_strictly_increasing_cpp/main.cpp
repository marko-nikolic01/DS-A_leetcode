#include <iostream>
#include <vector>

using namespace std;

int minimumOperations(vector<vector<int>>& grid) {
    int operations = 0;

    short m = grid.size();
    short n = grid[0].size();
    for(--n; n > -1; --n) {
        for(short i = 1; i < m; ++i) {
            if(grid[i][n] <= grid[i - 1][n]) {
                operations += ++grid[i - 1][n] - grid[i][n];
                grid[i][n] = grid[i - 1][n];
            }
        }
    }

    return operations;
}

void printMatrix(const vector<vector<int>> matrix) {
    for (vector<int> row : matrix) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> grid, int expected) {
    cout << "Matrix:" << endl;
    printMatrix(grid);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minimumOperations(grid) << endl;

    cout << endl;
}

int main() {
    vector<vector<int>> grid1 = {{3, 2}, {1, 3}, {3, 4}, {0, 1}};
    test(grid1, 15);

    vector<vector<int>> grid2 = {{3, 2, 1}, {2, 1, 0}, {1, 2, 3}};
    test(grid2, 12);

    vector<vector<int>> grid3 = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
    test(grid3, 9);

    vector<vector<int>> grid4 = {{1, 2, 1}, {1, 2, 1}, {1, 2, 1}};
    test(grid4, 9);

    vector<vector<int>> grid5 = {{3, 1}, {2, 2}, {1, 3}};
    test(grid5, 6);

    return 0;
}
