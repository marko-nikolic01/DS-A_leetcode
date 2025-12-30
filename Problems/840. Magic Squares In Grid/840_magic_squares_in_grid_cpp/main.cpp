#include <iostream>
#include <vector>

using namespace std;

void numMagicSquaresInside(vector<vector<int>>& grid, short x, short y, short& magicSquares) {
    short sum = 0;

    short i;
    short j;
    for(i = x - 2; i <= x; ++i) {
        for(j = y - 2; j <= y; ++j) {
            if(grid[i][j] < 1 || grid[i][j] > 9) {
                return;
            }

            sum |= 1 << grid[i][j];
        }
    }

    if(sum < 1022) {
        return;
    }

    sum = grid[x][y - 2] + grid[x][y - 1] + grid[x][y];

    if(grid[x - 1][y - 2] + grid[x - 1][y - 1] + grid[x - 1][y] == sum && grid[x - 2][y - 2] + grid[x - 2][y - 1] + grid[x - 2][y] == sum && grid[x - 2][y] + grid[x - 1][y] + grid[x][y] == sum && grid[x - 2][y - 1] + grid[x - 1][y - 1] + grid[x][y - 1] == sum && grid[x - 2][y - 2] + grid[x - 1][y - 2] + grid[x][y - 2] == sum && grid[x][y] + grid[x - 1][y - 1] + grid[x - 2][y - 2] == sum && grid[x][y - 2] + grid[x - 1][y - 1] + grid[x - 2][y] == sum) {
        ++magicSquares;
    }
}

int numMagicSquaresInside(vector<vector<int>>& grid) {
    short magicSquares = 0;

    short j;
    short n = grid[0].size() - 1;
    for(short i = grid.size() - 1; i > 1; --i) {
        for(j = n; j > 1; --j) {
            numMagicSquaresInside(grid, i, j, magicSquares);
        }
    }

    return magicSquares;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> grid, int expected) {
    cout << "Matrix:" << endl;
    printMatrix(grid);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numMagicSquaresInside(grid) << endl;

    cout << endl;
}

int main() {
    test({{4, 3, 8, 4}, {9, 5, 1, 9}, {2, 7, 6, 2}}, 1);
    test({{8}}, 0);
    test({{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}, 0);
    test({{10, 3, 5}, {2, 7, 6}, {4, 9, 8}}, 0);
    test({{4, 3, 8, 4, 3}, {9, 5, 1, 9, 5}, {2, 7, 6, 2, 7}, {4, 3, 8, 4, 3}}, 1);

    return 0;
}
