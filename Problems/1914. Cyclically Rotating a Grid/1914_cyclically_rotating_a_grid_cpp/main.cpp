#include <iostream>
#include <vector>

using namespace std;

void rotateGrid(vector<vector<int>>& grid, vector<vector<int>>& rotatedGrid, vector<int>& rotatedLayer, int& k, short& x1, short& x2, short& y1, short& y2) {
    if(x1 > x2 || y1 > y2) {
        return;
    }

    short n = (x2 - x1 + y2 - y1) << 1;
    int rotation = k % n;

    rotatedLayer.resize(n);

    short i = x1;
    short j = y1;
    short iRotated = -1;
    for(i; i <= x2; ++i) {
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

    iRotated = -1;
    for(i; i <= x2; ++i) {
        rotatedGrid[i][j] = rotatedLayer[++iRotated];
    }

    --i;
    while(++j <= y2) {
        rotatedGrid[i][j] = rotatedLayer[++iRotated];
    }

    --j;
    while(--i >= x1) {
        rotatedGrid[i][j] = rotatedLayer[++iRotated];
    }

    ++i;
    while(--j > y1) {
        rotatedGrid[i][j] = rotatedLayer[++iRotated];
    }

    rotateGrid(grid, rotatedGrid, rotatedLayer, k, ++x1, --x2, ++y1, --y2);
}

vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
    short x1 = -1;
    short x2 = grid.size();
    short y1 = -1;
    short y2 = grid[0].size();
    vector<vector<int>> rotatedGrid(x2, vector<int>(y2));
    vector<int> rotatedLayer;

    rotateGrid(grid, rotatedGrid, rotatedLayer, k, ++x1, --x2, ++y1, --y2);

    return rotatedGrid;
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
