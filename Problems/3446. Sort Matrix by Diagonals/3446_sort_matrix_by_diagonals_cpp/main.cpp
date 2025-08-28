#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
    short n = grid.size();
    vector<int> diagonal;
    short x;
    short y = 0;

    short i;
    short iDiagonal;
    for(i = 1; i < n; ++i) {
        x = 0;
        y = i;
        diagonal.resize(0);

        while(x < n && y < n) {
            diagonal.push_back(grid[x++][y++]);
        }

        sort(diagonal.begin(), diagonal.end());

        x = 0;
        y = i;

        iDiagonal = 0;
        while(x < n && y < n) {
            grid[x++][y++] = diagonal[iDiagonal++];
        }
    }

    for(i = 0; i < n; ++i) {
        x = i;
        y = 0;
        diagonal.resize(0);

        while(x < n && y < n) {
            diagonal.push_back(grid[x++][y++]);
        }

        sort(diagonal.begin(), diagonal.end());

        x = i;
        y = 0;

        iDiagonal = diagonal.size();
        while(x < n && y < n) {
            grid[x++][y++] = diagonal[--iDiagonal];
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

void test(vector<vector<int>> grid, vector<vector<int>> expected) {
    cout << "Matrix:" << endl;
    printMatrix(grid);

    cout << "Expected:" << endl;
    printMatrix(expected);

    cout << "Result:" << endl;
    printMatrix(sortMatrix(grid));

    cout << endl;
}

int main() {
    test({{1, 7, 3}, {9, 8, 2}, {4, 5, 6}}, {{8, 2, 3}, {9, 6, 7}, {4, 5, 1}});
    test({{0, 1}, {1, 2}}, {{2, 1}, {1, 0}});
    test({{1}}, {{1}});
    test({{99757, -52290}, {39320, -22679}}, {{99757, -52290}, {39320, -22679}});
    test({{10, 9, 8, 7}, {6, 5, 4, 3}, {2, 1, 0, -1}, {-2, -3, -4, -5}}, {{10, -1, 3, 7}, {6, 5, 4, 8}, {2, 1, 0, 9}, {-2, -3, -4, -5}});

    return 0;
}
