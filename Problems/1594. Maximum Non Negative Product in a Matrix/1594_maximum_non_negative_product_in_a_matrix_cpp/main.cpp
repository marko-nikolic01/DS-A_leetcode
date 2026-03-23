#include <iostream>
#include <vector>

using namespace std;

void maxProductPath(vector<vector<long>>& positive, vector<vector<long>>& negative, long product, short x, short y) {
    if(product < 0) {
        if(product < negative[x][y]) {
            negative[x][y] = product;
        }
    } else if(product > positive[x][y]) {
        positive[x][y] = product;
    }
}

void maxProductPath(vector<vector<long>>& positive, vector<vector<long>>& negative, short cell, short x, short y, short dx, short dy) {
    if(x + dx > -1 && y + dy > -1) {
        if(positive[x + dx][y + dy] > -1) {
            maxProductPath(positive, negative, (long)cell * positive[x + dx][y + dy], x, y);
        }

        if(negative[x + dx][y + dy] < 1) {
            maxProductPath(positive, negative, (long)cell * negative[x + dx][y + dy], x, y);
        }
    }
}

int maxProductPath(vector<vector<int>>& grid) {
    short m = grid.size();
    short n = grid[0].size();
    vector<vector<long>> positive(m, vector<long>(n, -1));
    vector<vector<long>> negative(m, vector<long>(n, 1));
    bool zero = false;

    if(grid[0][0] < 0) {
        negative[0][0] = grid[0][0];
    } else {
        positive[0][0] = grid[0][0];
    }

    short j;
    for(short i = 0; i < m; ++i) {
        for(j = 0; j < n; ++j) {
            if(grid[i][j] == 0) {
                zero = true;
            }

            maxProductPath(positive, negative, grid[i][j], i, j, 0, -1);
            maxProductPath(positive, negative, grid[i][j], i, j, -1, 0);
        }
    }

    return positive[--m][--n] > -1 ? positive[m][n] % 1000000007 : (zero ? 0 : -1);
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

    cout << "Result: " << maxProductPath(grid) << endl;

    cout << endl;
}

int main() {
    test({{-1, -2, -3}, {-2, -3, -3}, {-3, -3, -2}}, -1);
    test({{1, -2, 1}, {1, -2, 1}, {3, -4, 1}}, 8);
    test({{1, 3}, {0, -4}}, 0);
    test({{-1, 3, 0}, {3, -2, 3}, {-1, 1, -4}}, 0);
    test({{0, 4, -1}, {3, 0, 0}, {-3, 1, -2}}, 0);
    test({{1, -1, 2, 1, -1, 0, 0, 4, 3, 2, 0, -2, -2}, {-2, 3, 3, -1, -1, 0, 0, -2, 4, -3, 3, 0, 0}, {-4, -1, -1, -2, 2, -1, -2, -2, 0, 3, -1, -4, 1}, {-3, 4, -3, 0, -3, 1, -3, 1, 4, 4, -4, -4, -2}, {3, -3, 1, 0, -1, -4, -4, -4, 3, 2, 2, 3, 3}, {2, -1, -1, -4, -3, -3, 4, 2, 3, 4, 4, -4, 0}, {4, -1, 2, -3, -1, -1, -3, -4, 4, 4, 4, -3, -1}, {-3, -4, 4, -2, -1, 2, 3, -1, 2, 3, 4, 4, -4}, {-3, -1, -2, 1, 1, -1, -3, -4, -3, 1, -3, 3, -4}, {2, 4, 4, 4, -3, -3, 1, -1, 3, 4, -1, 1, 4}, {2, -2, 0, 4, -1, 0, -2, 4, -4, 0, 0, 2, -3}, {1, 1, -3, 0, -4, -4, -4, -4, 0, -1, -4, -1, 0}, {3, -1, -3, -3, -3, -2, -1, 4, -1, -2, 4, 2, 3}}, 459630706);

    return 0;
}
