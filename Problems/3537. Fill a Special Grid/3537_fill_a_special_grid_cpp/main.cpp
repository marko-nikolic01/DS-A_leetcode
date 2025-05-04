#include <iostream>
#include <vector>

using namespace std;

void specialGrid(vector<vector<int>>& grid, short x1, short x2, short y1, short y2, int from, int to) {
    if(to - from == 1) {
        grid[x1][y1] = from;
        return;
    }

    short half = (x2 - x1) >> 1;

    from = (to - from) >> 2;
    specialGrid(grid, x1, x1 + half, y1, y1 + half, to - from, to);

    to -= from;
    specialGrid(grid, x1 + half, x2, y1, y1 + half, to - from, to);

    to -= from;
    specialGrid(grid, x1 + half, x2, y1 + half, y2, to - from, to);

    to -= from;
    specialGrid(grid, x1, x1 + half, y1 + half, y2, to - from, to);
}

vector<vector<int>> specialGrid(int n) {
    n = 1 << n;
    vector<vector<int>> grid(n, vector<int>(n));

    specialGrid(grid, 0, n, 0, n, 0, n * n);

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

void test(int n, vector<vector<int>> expected) {
    cout << "n: " << n << endl;

    cout << "Expected:" << endl;
    printMatrix(expected);

    cout << "Result:" << endl;
    printMatrix(specialGrid(n));

    cout << endl;
}

int main() {
    vector<vector<int>> expected1 = {
        {0}
    };
    test(0, expected1);

    vector<vector<int>> expected2 = {
        {3, 0},
        {2, 1}
    };
    test(1, expected2);

    vector<vector<int>> expected3 = {
        {15, 12, 3, 0},
        {14, 13, 2, 1},
        {11,  8, 7, 4},
        {10,  9, 6, 5}
    };
    test(2, expected3);

    vector<vector<int>> expected4 = {
        {63, 60, 51, 48, 15, 12, 3, 0},
        {62, 61, 50, 49, 14, 13, 2, 1},
        {59, 56, 55, 52, 11,  8, 7, 4},
        {58, 57, 54, 53, 10,  9, 6, 5},
        {47, 44, 35, 32, 31, 28, 19, 16},
        {46, 45, 34, 33, 30, 29, 18, 17},
        {43, 40, 39, 36, 27, 24, 23, 20},
        {42, 41, 38, 37, 26, 25, 22, 21}
    };
    test(3, expected4);

    return 0;
}
