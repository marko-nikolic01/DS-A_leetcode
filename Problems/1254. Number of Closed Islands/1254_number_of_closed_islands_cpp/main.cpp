#include <iostream>
#include <vector>

using namespace std;

bool closedIsland(vector<vector<int>>& grid, int x, int y) {
    grid[x][y] = -1;

    bool isClosed = x > 0 && x < grid.size() - 1 && y > 0 && y < grid[0].size() - 1;

    if(x > 0 && grid[x - 1][y] == 0) {
        isClosed = closedIsland(grid, x - 1, y) && isClosed;
    }

    if(x < grid.size() - 1 && grid[x + 1][y] == 0) {
        isClosed = closedIsland(grid, x + 1, y) && isClosed;
    }

    if(y > 0 && grid[x][y - 1] == 0) {
        isClosed = closedIsland(grid, x, y - 1) && isClosed;
    }

    if(y < grid[0].size() - 1 && grid[x][y + 1] == 0) {
        isClosed = closedIsland(grid, x, y + 1) && isClosed;
    }

    return isClosed;
}

int closedIsland(vector<vector<int>>& grid) {
    int closedIslands = 0;

    int n = grid[0].size();
    for(int i = grid.size() - 1; i > -1; --i) {
        for(int j = n - 1; j > -1; --j) {
            if(grid[i][j] == 0 && closedIsland(grid, i, j)) {
                closedIslands++;
            }
        }
    }

    return closedIslands;
}

void printGrid(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> grid, int expected) {
    cout << "Islands:" << endl;
    printGrid(grid);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << closedIsland(grid) << endl;

    cout << endl;
}

int main() {
    vector<vector<int>> grid1 = {
        {1, 1, 1, 1, 0, 1, 1},
        {1, 0, 0, 1, 0, 1, 1},
        {1, 0, 1, 1, 0, 0, 1},
        {1, 1, 1, 1, 1, 1, 1}
    };
    test(grid1, 1);

    vector<vector<int>> grid2 = {
        {1, 1, 1, 0, 0, 1, 1},
        {1, 0, 1, 0, 1, 1, 1},
        {1, 0, 0, 1, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1}
    };
    test(grid2, 2);

    vector<vector<int>> grid3 = {
        {1, 1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 1},
        {1, 0, 1, 1, 0, 1},
        {1, 1, 1, 1, 1, 1}
    };
    test(grid3, 1);

    vector<vector<int>> grid4 = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    test(grid4, 1);

    vector<vector<int>> grid5 = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 0, 1}
    };
    test(grid5, 0);

    vector<vector<int>> grid6 = {
        {1},
    };
    test(grid6, 0);

    vector<vector<int>> grid7 = {
        {0},
    };
    test(grid7, 0);

    return 0;
}
