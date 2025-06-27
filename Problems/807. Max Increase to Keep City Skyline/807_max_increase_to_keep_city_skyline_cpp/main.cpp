#include <iostream>
#include <vector>

using namespace std;

int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    short n = grid.size();
    vector<short> skylineHorizontal(n, 0);
    vector<short> skylineVertical(n, 0);

    short i;
    short j;
    for(i = 0; i < n; ++i) {
        for(j = 0; j < n; ++j) {
            if(grid[i][j] > skylineHorizontal[i]) {
                skylineHorizontal[i] = grid[i][j];
            }

            if(grid[j][i] > skylineVertical[i]) {
                skylineVertical[i] = grid[j][i];
            }
        }
    }

    int increase = 0;

    for(i = 0; i < n; ++i) {
        for(j = 0; j < n; ++j) {
            increase += min(skylineHorizontal[i], skylineVertical[j]) - grid[i][j];
        }
    }

    return increase;
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
    cout << "City:" << endl;
    printMatrix(grid);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxIncreaseKeepingSkyline(grid) << endl;

    cout << endl;
}

int main() {
    test({{3, 0, 8, 4}, {2, 4, 5, 7}, {9, 2, 6, 3}, {0, 3, 1, 0}}, 35);
    test({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, 0);
    test({{5, 5, 5}, {5, 5, 5}, {5, 5, 5}}, 0);
    test({{1, 2}, {3, 4}}, 1);
    test({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, 6);

    return 0;
}
