#include <iostream>
#include <vector>

using namespace std;

bool numEnclaves(vector<vector<int>>& grid, int x, int y, int& currentEnclaves) {
    currentEnclaves++;
    grid[x][y] <<= 1;

    bool isEnclave = x > 0 && x < grid.size() - 1 && y > 0 && y < grid[0].size() - 1;

    if(x > 0 && grid[x - 1][y] == 1) {
        isEnclave = numEnclaves(grid, x - 1, y, currentEnclaves) && isEnclave;
    }

    if(x < grid.size() - 1 && grid[x + 1][y] == 1) {
        isEnclave = numEnclaves(grid, x + 1, y, currentEnclaves) && isEnclave;
    }

    if(y > 0 && grid[x][y - 1] == 1) {
        isEnclave = numEnclaves(grid, x, y - 1, currentEnclaves) && isEnclave;
    }

    if(y < grid[0].size() - 1 && grid[x][y + 1] == 1) {
        isEnclave = numEnclaves(grid, x, y + 1, currentEnclaves) && isEnclave;
    }

    return isEnclave;
}

int numEnclaves(vector<vector<int>>& grid) {
    int enclaves = 0;

    for(int i = grid.size() - 1; i > -1; --i) {
        for(int j = grid[0].size() - 1; j > -1; --j) {
            if(grid[i][j] == 1) {
                int currentEnclaves = 0;
                if(numEnclaves(grid, i, j, currentEnclaves)) {
                    enclaves += currentEnclaves;
                }
            }
        }
    }

    return enclaves;
}

void printGrid(const vector<vector<int>>& grid) {
    for(const auto& row : grid) {
        for(const auto& cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> grid, int expected) {
    cout << "Enclaves:" << endl;
    printGrid(grid);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numEnclaves(grid) << endl;

    cout << endl;
}

int main() {
    vector<vector<int>> grid1 = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };
    test(grid1, 3);

    vector<vector<int>> grid2 = {
        {0, 1, 1, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {0, 0, 0, 0}
    };
    test(grid2, 0);

    vector<vector<int>> grid3 = {
        {0, 0, 0, 0},
        {0, 1, 1, 0},
        {0, 1, 0, 0},
        {0, 0, 0, 0}
    };
    test(grid3, 3);

    vector<vector<int>> grid4 = {
        {1}
    };
    test(grid4, 0);

    vector<vector<int>> grid5 = {
        {0}
    };
    test(grid5, 0);

    vector<vector<int>> grid6 = {
        {1, 1},
        {1, 1}
    };
    test(grid6, 0);

    vector<vector<int>> grid7 = {
        {0, 0},
        {0, 0}
    };
    test(grid7, 0);

    vector<vector<int>> grid8 = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };
    test(grid8, 1);

    return 0;
}
