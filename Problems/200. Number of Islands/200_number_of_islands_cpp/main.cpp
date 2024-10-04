#include <iostream>
#include <vector>

using namespace std;

void numIslands(vector<vector<char>>& grid, int x, int y) {
    grid[x][y] = '0';

    int m = grid.size() - 1;
    int n = grid[0].size() - 1;

    if(x > 0 && grid[x - 1][y] == '1') {
        numIslands(grid, x - 1, y);
    }

    if(x < m && grid[x + 1][y] == '1') {
        numIslands(grid, x + 1, y);
    }

    if(y > 0 && grid[x][y - 1] == '1') {
        numIslands(grid, x, y - 1);
    }

    if(y < n && grid[x][y + 1] == '1') {
        numIslands(grid, x, y + 1);
    }
}

int numIslands(vector<vector<char>>& grid) {
    int islands = 0;

    int n = grid[0].size() - 1;
    for(int i = grid.size() - 1; i > -1; --i) {
        for(int j = n; j > -1; --j) {
            if(grid[i][j] == '1') {
                islands++;
                numIslands(grid, i, j);
            }
        }
    }

    return islands;
}

void runTest(vector<vector<char>> grid, int expected) {
    cout << "Grid:" << endl;
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            cout << cell << ' ';
        }
        cout << endl;
    }
    cout << "Expected: " << expected << endl;

    cout << "Result: " << numIslands(grid) << endl;

    cout << endl;
}

int main() {
    vector<vector<char>> grid1 = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    runTest(grid1, 3);

    vector<vector<char>> grid2 = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    runTest(grid2, 1);

    vector<vector<char>> grid3 = {
        {'1', '0', '0', '0', '1'},
        {'0', '0', '1', '0', '0'},
        {'1', '0', '0', '1', '0'},
        {'0', '0', '0', '0', '1'}
    };
    runTest(grid3, 6);

    vector<vector<char>> grid4 = {
        {'1', '1', '1'},
        {'0', '1', '0'},
        {'1', '1', '1'}
    };
    runTest(grid4, 1);

    vector<vector<char>> grid5 = {
        {'0', '0', '0'},
        {'0', '0', '0'},
        {'0', '0', '0'}
    };
    runTest(grid5, 0);

    vector<vector<char>> grid6 = {
        {'1'}
    };
    runTest(grid6, 1);

    vector<vector<char>> grid7 = {
        {'0'}
    };
    runTest(grid7, 0);

    return 0;
}
