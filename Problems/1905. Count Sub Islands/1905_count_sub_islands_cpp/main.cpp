#include <iostream>
#include <vector>

using namespace std;

bool countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int x, int y) {
    grid2[x][y] = -1;

    bool isSubIsland = grid1[x][y] == 1;

    if(x > 0 && grid2[x - 1][y] == 1) {
        isSubIsland = countSubIslands(grid1, grid2, x - 1, y) && isSubIsland;
    }

    if(x < grid1.size() - 1 && grid2[x + 1][y] == 1) {
        isSubIsland = countSubIslands(grid1, grid2, x + 1, y) && isSubIsland;
    }

    if(y > 0 && grid2[x][y - 1] == 1) {
        isSubIsland = countSubIslands(grid1, grid2, x, y - 1) && isSubIsland;
    }

    if(y < grid1[0].size() - 1 && grid2[x][y + 1] == 1) {
        isSubIsland = countSubIslands(grid1, grid2, x, y + 1) && isSubIsland;
    }

    return isSubIsland;
}

int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    int subIslands = 0;

    int n = grid1[0].size() - 1;
    for(int i = grid1.size() - 1; i > -1; --i) {
        for(int j = n; j > -1; --j) {
            if(grid2[i][j] == 1 && countSubIslands(grid1, grid2, i, j)) {
                subIslands++;
            }
        }
    }

    return subIslands;
}

void printGrid(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> grid1, vector<vector<int>> grid2, int expected) {
    cout << "Islands 1:" << endl;
    printGrid(grid1);

    cout << "Islands 2:" << endl;
    printGrid(grid2);

    cout << "Expected: " << expected << endl;
    cout << "Result: " << countSubIslands(grid1, grid2) << endl;
    cout << endl;
}

int main() {
    test(
        {{1, 1, 0, 0}, {1, 1, 0, 1}, {0, 0, 1, 1}, {0, 0, 1, 1}},
        {{1, 1, 0, 0}, {1, 0, 0, 0}, {0, 0, 1, 1}, {0, 0, 1, 0}},
        2
    );

    test(
        {{1, 1, 1}, {1, 0, 0}, {0, 1, 1}},
        {{1, 1, 0}, {0, 0, 0}, {0, 1, 1}},
        2
    );

    test(
        {{1, 0, 1}, {1, 1, 0}, {0, 0, 1}},
        {{1, 0, 0}, {0, 0, 0}, {0, 0, 1}},
        2
    );

    test(
        {{1, 1}, {1, 1}},
        {{1, 1}, {1, 1}},
        1
    );

    test(
        {{1, 0, 1}, {1, 1, 0}, {0, 0, 1}},
        {{1, 1, 0}, {1, 0, 0}, {0, 1, 1}},
        0
    );

    test(
        {{1}},
        {{1}},
        1
    );

    test(
        {{1}},
        {{0}},
        0
    );

    test(
        {{0}},
        {{0}},
        0
    );

    test(
        {{0}},
        {{1}},
        0
    );

    return 0;
}
