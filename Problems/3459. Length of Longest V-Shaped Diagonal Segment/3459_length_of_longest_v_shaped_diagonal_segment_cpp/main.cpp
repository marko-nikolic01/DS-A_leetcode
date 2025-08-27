#include <iostream>
#include <vector>

using namespace std;

int lenOfVDiagonal(vector<vector<int>>& grid) {
    short m = grid.size(), n = grid[0].size();
    short dirs[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    short memo[m][n][4][2];
    memset(memo, -1, sizeof(memo));

    function<short(short, short, short, bool, short)> dfs =
        [&](short cx, short cy, short direction, bool turn, short target) -> int {
        short nx = cx + dirs[direction][0];
        short ny = cy + dirs[direction][1];

        if(nx < 0 || ny < 0 || nx >= m || ny >= n ||
            grid[nx][ny] != target) {
            return 0;
        }

        if (memo[nx][ny][direction][turn] != -1) {
            return memo[nx][ny][direction][turn];
        }

        short maxStep = dfs(nx, ny, direction, turn, 2 - target);

        if(turn) {
            maxStep = fmax(maxStep, dfs(nx, ny, (direction + 1) % 4, false,2 - target));
        }

        memo[nx][ny][direction][turn] = maxStep + 1;

        return maxStep + 1;
    };

    short res = 0;

    short j;
    short direction;
    for (short i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            if (grid[i][j] == 1) {
                for (direction = 0; direction < 4; ++direction) {
                    res = fmax(res, dfs(i, j, direction, true, 2) + 1);
                }
            }
        }
    }

    return res;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> grid, int expected) {
    cout << "Matrix:" << endl;
    printMatrix(grid);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << lenOfVDiagonal(grid) << endl;

    cout << endl;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
