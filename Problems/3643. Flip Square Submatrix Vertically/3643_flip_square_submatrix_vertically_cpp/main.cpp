#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
    short x1 = x + --k;
    short y1 = y + k;
    short temp;

    short i;
    for(y; y <= y1; ++y) {
        k = x1;
        for(i = x; i < k; ++i) {
            temp = grid[i][y];
            grid[i][y] = grid[k][y];
            grid[k--][y] = temp;
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

void test(vector<vector<int>> grid, int x, int y, int k, vector<vector<int>> expected) {
    cout << "Matrix:" << endl;
    printMatrix(grid);

    cout << "x: " << x << endl;

    cout << "y: " << y << endl;

    cout << "k: " << k << endl;

    cout << "Expected:" << endl;
    printMatrix(expected);

    cout << "Result:" << endl;
    printMatrix(reverseSubmatrix(grid, x, y, k));

    cout << endl;
}

int main() {
    test({{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}}, 1, 0, 3, {{1, 2, 3, 4}, {13, 14, 15, 8}, {9, 10, 11, 12}, {5, 6, 7, 16}});
    test({{3, 4, 2, 3}, {2, 3, 4, 2}}, 0, 2, 2, {{3, 4, 4, 2}, {2, 3, 2, 3}});
    test({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, 0, 0, 3, {{7, 8, 9}, {4, 5, 6}, {1, 2, 3}});
    test({{1, 2}, {3, 4}, {5, 6}}, 0, 0, 2, {{3, 4}, {1, 2}, {5, 6}});
    test({{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}, 1, 1, 2, {{1, 2, 3, 4}, {5, 10, 11, 8}, {9, 6, 7, 12}});

    return 0;
}
