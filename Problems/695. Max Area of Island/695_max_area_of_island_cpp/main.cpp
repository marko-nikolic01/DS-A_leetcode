#include <iostream>
#include <vector>

using namespace std;

int maxAreaOfIsland(vector<vector<int>>& grid, int x, int y) {
    if(grid[x][y] == 1) {
        grid[x][y] = -1;

        int area = 1;

        if(x > 0) {
            area += maxAreaOfIsland(grid, x - 1, y);
        }

        if(x < grid.size() - 1) {
            area += maxAreaOfIsland(grid, x + 1, y);
        }

        if(y > 0) {
            area += maxAreaOfIsland(grid, x, y - 1);
        }

        if(y < grid[0].size() - 1) {
            area += maxAreaOfIsland(grid, x, y + 1);
        }

        return area;
    }

    return 0;
}

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int maxArea = 0;

    for(int i = grid.size() - 1; i > -1; --i) {
        for(int j = grid[0].size() - 1; j > -1; --j) {
            int area = maxAreaOfIsland(grid, i, j);
            if(area > maxArea) {
                maxArea = area;
            }
        }
    }

    return maxArea;
}

void printGrid(const vector<vector<int>>& grid) {
    for(const auto& row : grid) {
        for(const auto& cell : row) {
            cout << (cell == -1 ? 1 : cell) << " ";
        }
        cout << endl;
    }
}

void runTest(vector<vector<int>> grid, int expected) {
    cout << "Islands: " << endl;
    printGrid(grid);

    cout << "Expected Max Area: " << expected << endl;

    cout << "Result: " << maxAreaOfIsland(grid) << endl;


    cout << endl;
}

int main() {
    vector<vector<int>> grid1 = {
        {0, 1, 0, 0, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 0, 0, 1},
        {0, 0, 0, 0, 1}
    };
    runTest(grid1, 4);

    vector<vector<int>> grid2 = {
        {1, 0, 0, 1},
        {0, 1, 0, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };
    runTest(grid2, 3);

    vector<vector<int>> grid3 = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };
    runTest(grid3, 8);

    vector<vector<int>> grid4 = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };
    runTest(grid4, 0);

    vector<vector<int>> grid5 = {
        {1, 0, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {1, 1, 1, 0, 0},
        {0, 0, 0, 1, 1},
        {1, 1, 0, 1, 1}
    };
    runTest(grid5, 5);

    vector<vector<int>> grid6 = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    runTest(grid6, 1);

    return 0;
}
