#include <iostream>
#include <vector>

using namespace std;

int getMaximumGold(vector<vector<int>>& grid, int x, int y) {
    int gold = grid[x][y];
    grid[x][y] = 0;

    int maximumPathGold = 0;

    if(x > 0 && grid[x - 1][y] > 0) {
        int pathGold = getMaximumGold(grid, x - 1, y);
        if(pathGold > maximumPathGold) {
            maximumPathGold = pathGold;
        }
    }

    if(x < grid.size() - 1 && grid[x + 1][y] > 0) {
        int pathGold = getMaximumGold(grid, x + 1, y);
        if(pathGold > maximumPathGold) {
            maximumPathGold = pathGold;
        }
    }

    if(y > 0 && grid[x][y - 1] > 0) {
        int pathGold = getMaximumGold(grid, x, y - 1);
        if(pathGold > maximumPathGold) {
            maximumPathGold = pathGold;
        }
    }

    if(y < grid[0].size() - 1 && grid[x][y + 1] > 0) {
        int pathGold = getMaximumGold(grid, x, y + 1);
        if(pathGold > maximumPathGold) {
            maximumPathGold = pathGold;
        }
    }

    grid[x][y] = gold;

    return gold + maximumPathGold;
}

int getMaximumGold(vector<vector<int>>& grid) {
    int maximumGold = 0;

    for(int i = grid.size() - 1; i > -1; --i) {
        for(int j = grid[0].size() - 1; j > -1; --j) {
            if(grid[i][j] > 0) {
                int gold = getMaximumGold(grid, i, j);
                if(gold > maximumGold) {
                    maximumGold = gold;
                }
            }
        }
    }

    return maximumGold;
}

void printGrid(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}


void test(vector<vector<int>>& grid, int expected) {
    cout << "Grid:" << endl;
    printGrid(grid);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << getMaximumGold(grid) << endl;

    cout << endl;
}

int main() {
    vector<vector<int>> grid1 = {{0, 6, 0}, {5, 8, 7}, {0, 9, 0}};
    test(grid1, 24);

    vector<vector<int>> grid2 = {{1, 0, 7}, {2, 0, 6}, {3, 4, 5}, {0, 3, 0}};
    test(grid2, 28);

    vector<vector<int>> grid3 = {{0, 0, 0}, {0, 5, 0}, {0, 0, 0}};
    test(grid3, 5);

    vector<vector<int>> grid4 = {{1}};
    test(grid4, 1);

    vector<vector<int>> grid5 = {{0}};
    test(grid5, 0);

    vector<vector<int>> grid6 = {{1, 1}, {1, 1}};
    test(grid6, 4);

    vector<vector<int>> grid7 = {{0, 0}, {0, 0}};
    test(grid7, 0);

    vector<vector<int>> grid8 = {{1, 0}, {0, 1}};
    test(grid8, 1);

    vector<vector<int>> grid9 = {{1, 1}, {0, 1}};
    test(grid9, 3);

    return 0;
}
