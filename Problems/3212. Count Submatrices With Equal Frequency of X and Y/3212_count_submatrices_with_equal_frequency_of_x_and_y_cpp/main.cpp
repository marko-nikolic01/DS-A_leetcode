#include <iostream>
#include <vector>
#include <array>

using namespace std;

int numberOfSubmatrices(vector<vector<char>>& grid) {
    int submatrices = 0;
    short n = grid.size();
    short m = grid[0].size();
    vector<vector<array<int, 2>>> sum(n + 1, vector<array<int, 2>>(m + 1));

    short j;
    for(short i = 0; i < n; ++i) {
        for(j = 0; j < m; ++j) {
            if(grid[i][j] == 'X') {
                sum[i + 1][j + 1][0] = sum[i + 1][j][0] + sum[i][j + 1][0] - sum[i][j][0] + 1;
                sum[i + 1][j + 1][1] = 1;
            } else if(grid[i][j] == 'Y') {
                sum[i + 1][j + 1][0] = sum[i + 1][j][0] + sum[i][j + 1][0] - sum[i][j][0] - 1;
                sum[i + 1][j + 1][1] = sum[i + 1][j][1] | sum[i][j + 1][1];
            } else {
                sum[i + 1][j + 1][0] = sum[i + 1][j][0] + sum[i][j + 1][0] - sum[i][j][0];
                sum[i + 1][j + 1][1] = sum[i + 1][j][1] | sum[i][j + 1][1];
            }

            submatrices += (!sum[i + 1][j + 1][0] && sum[i + 1][j + 1][1]) ? 1 : 0;
        }
    }

    return submatrices;
}

void printMatrix(vector<vector<char>> matrix) {
    for(vector<char> row : matrix) {
        for(char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<char>> grid, int expected) {
    cout << "Matrix:" << endl;
    printMatrix(grid);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numberOfSubmatrices(grid) << endl;

    cout << endl;
}

int main() {
    test({{'X', 'Y', '.'}, {'Y', '.', '.'}}, 3);
    test({{'X', 'X'}, {'X', 'Y'}}, 0);
    test({{'.',  '.'}, {'.', '.'}}, 0);
    test({{'X', 'Y'}, {'X', 'Y'}}, 2);
    test({{'Y', 'X'}, {'X', 'Y'}}, 3);

    return 0;
}
