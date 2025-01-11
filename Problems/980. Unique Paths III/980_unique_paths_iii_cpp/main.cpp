#include <iostream>
#include <vector>

using namespace std;

void uniquePathsIII(vector<vector<int>>& grid, int& paths, short cells, short x, short y, short obstacles) {
    ++cells;

    short m = grid.size();
    short n = grid[0].size();

    if(grid[x][y] == 2) {
        if(m * n - obstacles == cells) {
            ++paths;
        }
        return;
    }

    grid[x][y] = -1;

    if(x > 0 && grid[x - 1][y] > -1) {
        uniquePathsIII(grid, paths, cells, x - 1, y, obstacles);
    }

    if(x < --m && grid[x + 1][y] > -1) {
        uniquePathsIII(grid, paths, cells, x + 1, y, obstacles);
    }

    if(y > 0 && grid[x][y - 1] > -1) {
        uniquePathsIII(grid, paths, cells, x, y - 1, obstacles);
    }

    if(y < --n && grid[x][y + 1] > -1) {
        uniquePathsIII(grid, paths, cells, x, y + 1, obstacles);
    }

    grid[x][y] = 0;
}

int uniquePathsIII(vector<vector<int>>& grid) {
    short obstacles = 0;
    short x;
    short y;

    short n = grid[0].size();
    for(short i = grid.size() - 1; i > -1; --i) {
        for(short j = 0; j < n; ++j) {
            if(grid[i][j] == -1) {
                ++obstacles;
            } else if(grid[i][j] == 1) {
                x = i;
                y = j;
            }
        }
    }

    int paths = 0;

    uniquePathsIII(grid, paths, 0, x, y, obstacles);

    return paths;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void testCase(vector<vector<int>> grid, int expected) {
    cout << "Matrix:" << endl;
    printMatrix(grid);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << uniquePathsIII(grid) << endl;

    cout << endl;
}

int main() {
    testCase({{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 2, -1}}, 2);
    testCase({{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 2}}, 4);
    testCase({{0, 1}, {2, 0}}, 0);
    testCase({{1, 0, -1}, {0, 0, 0}, {2, -1, 0}}, 0);
    testCase({{1, 0}, {0, 2}}, 0);

    return 0;
}
