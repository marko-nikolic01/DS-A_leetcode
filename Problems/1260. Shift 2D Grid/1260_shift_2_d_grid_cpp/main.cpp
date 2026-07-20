#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    short previous;
    short temp;

    short j;
    short l;
    short m = grid.size();
    short n = grid[0].size();
    short mn = m * n;
    for(short i = 0; i < m; ++i) {
        for(j = 0; j < n; ++j) {
            if(grid[i][j] > -1001) {
                previous = grid[i][j];

                for(l = (i * n + j + k) % mn; grid[l / n][l % n] > -1001; l = (l + k) % mn) {
                    temp = grid[l / n][l % n];
                    grid[l / n][l % n] = previous - 2001;
                    previous = temp;
                }
            }
        }
    }

    while(--m > -1) {
        for(j = 0; j < n; ++j) {
            grid[m][j] += 2001;
        }
    }

    return grid;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> grid, int k, vector<vector<int>> expected) {
    cout << "Matrix:" << endl;
    printMatrix(grid);

    cout << "k:" << k << endl;

    cout << "Expected:" << endl;
    printMatrix(expected);

    cout << "Result:" << endl;
    printMatrix(shiftGrid(grid, k));

    cout << endl;
}

int main() {
    test({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, 1, {{9, 1, 2}, {3, 4, 5}, {6, 7, 8}});
    test({{3, 8, 1, 9}, {19, 7, 2, 5}, {4, 6, 11, 10}, {12, 0, 21, 13}}, 4, {{12, 0, 21, 13}, {3, 8, 1, 9}, {19, 7, 2, 5}, {4, 6, 11, 10}});
    test({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, 9, {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    test({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, 0, {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}});
    test({{5}}, 100, {{5}});

    return 0;
}
