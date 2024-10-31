#include <iostream>
#include <vector>

using namespace std;

int countServers(vector<vector<int>>& grid, int x, int y) {
    int servers = 0;

    bool foundConnection = false;

    int m = grid.size();
    int n = grid[0].size();

    if(grid[x][y] > -1) {
        for(int i = x + 1; i < m; ++i) {
            if(grid[i][y] != 0) {
                foundConnection = true;
                if(grid[i][y] == 1) {
                    grid[i][y] = -1;
                    servers++;
                }
            }
        }
    }

    if(grid[x][y] < 2) {
        for(int i = y + 1; i < n; ++i) {
            if(grid[x][i] != 0) {
                foundConnection = true;
                if(grid[x][i] == 1) {
                    grid[x][i] = 2;
                    servers++;
                }
            }
        }
    }

    return grid[x][y] == 1 ? (foundConnection ? ++servers : 0) : servers;
}

int countServers(vector<vector<int>>& grid) {
    int servers = 0;

    int m = grid.size();
    int n = grid[0].size();

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(grid[i][j] != 0) {
                servers += countServers(grid, i, j);
            }
        }
    }

    return servers;
}

void printGrid(const vector<vector<int>>& grid) {
    for(const auto& row : grid) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>>& grid, int expected) {
    cout << "Servers:" << endl;
    printGrid(grid);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countServers(grid) << endl;

    cout << endl;
}

int main() {
    vector<vector<int>> grid1 = {
        {1, 0},
        {0, 1}
    };
    test(grid1, 0);

    vector<vector<int>> grid2 = {
        {1, 0},
        {1, 1}
    };
    test(grid2, 3);

    vector<vector<int>> grid3 = {
        {1, 0, 0, 1},
        {0, 1, 1, 0},
        {1, 0, 0, 1}
    };
    test(grid3, 6);

    vector<vector<int>> grid4 = {
        {1, 0, 0, 1},
        {0, 0, 0, 0},
        {1, 0, 0, 1}
    };
    test(grid4, 4);

    vector<vector<int>> grid5 = {
        {1, 1},
        {1, 1}
    };
    test(grid5, 4);

    vector<vector<int>> grid6 = {
        {1, 0},
        {0, 0}
    };
    test(grid6, 0);

    vector<vector<int>> grid7 = {
        {1}
    };
    test(grid7, 0);

    vector<vector<int>> grid8 = {
        {0}
    };
    test(grid8, 0);

    vector<vector<int>> grid9 = {
        {1, 0, 1, 0},
        {0, 1, 0, 0},
        {0, 0, 0, 1}
    };
    test(grid9, 2);

    return 0;
}
