#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
    short x1 = -1;
    short x2 = grid.size();
    short y1 = -1;
    short y2 = grid[0].size();
    vector<int> rotatedLayer;
    short rotation;

    short i;
    short j;
    short iRotated;
    short n;
    while(++x1 <= --x2 && ++y1 <= --y2) {
        n = (x2 - x1 + y2 - y1) << 1;
        rotation = k % n;
        rotatedLayer.resize(n);

        j = y1;
        iRotated = -1;
        for(i = x1; i <= x2; ++i) {
            rotatedLayer[(++iRotated + rotation) % n] = grid[i][j];
        }

        --i;
        while(++j <= y2) {
            rotatedLayer[(++iRotated + rotation) % n] = grid[i][j];
        }

        --j;
        while(--i >= x1) {
            rotatedLayer[(++iRotated + rotation) % n] = grid[i][j];
        }

        ++i;
        while(--j > y1) {
            rotatedLayer[(++iRotated + rotation) % n] = grid[i][j];
        }

        for(iRotated = -1; i <= x2; ++i) {
            grid[i][j] = rotatedLayer[++iRotated];
        }

        --i;
        while(++j <= y2) {
            grid[i][j] = rotatedLayer[++iRotated];
        }

        --j;
        while(--i >= x1) {
            grid[i][j] = rotatedLayer[++iRotated];
        }

        ++i;
        while(--j > y1) {
            grid[i][j] = rotatedLayer[++iRotated];
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

    cout << "k: " << k << endl;

    cout << "Expected:" << endl;
    printMatrix(expected);

    cout << "Result:" << endl;
    printMatrix(rotateGrid(grid, k));

    cout << endl;
}

int main() {
    test({{40, 10}, {30, 20}}, 1, {{10, 20}, {40, 30}});
    test({{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}}, 2, {{3, 4, 8, 12}, {2, 11, 10, 16}, {1, 7, 6, 15}, {5, 9, 13, 14}});
    test({{1, 2}, {4, 3}}, 4, {{1, 2}, {4, 3}});
    test({{1, 2, 3, 4}, {8, 7, 6, 5}}, 1, {{2, 3, 4, 5}, {1, 8, 7, 6}});
    test({{1, 2}, {4, 3}}, 1, {{2, 3}, {1, 4}});

    return 0;
}
