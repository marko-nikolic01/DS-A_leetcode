#include <iostream>
#include <vector>
#include <cstring>
#include <functional>
#include <cmath>

using namespace std;

int lenOfVDiagonal(vector<vector<int>>& grid) {
    short m = grid.size(), n = grid[0].size();
    short dirs[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

    vector<vector<vector<vector<short>>>> memo(
        m, vector<vector<vector<short>>>(
            n, vector<vector<short>>(
                4, vector<short>(2, -1))));

    function<short(short, short, short, bool, short)> dfs =
        [&](short cx, short cy, short direction, bool turn, short target) -> short {
        short nx = cx + dirs[direction][0];
        short ny = cy + dirs[direction][1];

        if(nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != target)
            return 0;

        if(memo[nx][ny][direction][turn] != -1)
            return memo[nx][ny][direction][turn];

        short maxStep = dfs(nx, ny, direction, turn, 2 - target);

        if(turn)
            maxStep = max(maxStep, dfs(nx, ny, (direction + 1) % 4, false, 2 - target));

        memo[nx][ny][direction][turn] = maxStep + 1;
        return maxStep + 1;
    };

    short res = 0;
    for(short i = 0; i < m; ++i) {
        for(short j = 0; j < n; ++j) {
            if(grid[i][j] == 1) {
                for(short direction = 0; direction < 4; ++direction) {
                    res = max((int)res, dfs(i, j, direction, true, 2) + 1);
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

int main() {
    test({{2, 2, 1, 2, 2}, {2, 0, 2, 2, 0}, {2, 0, 1, 1, 0}, {1, 0, 2, 2, 2}, {2, 0, 0, 2, 2}}, 5);
    test({{2, 2, 2, 2, 2}, {2, 0, 2, 2, 0}, {2, 0, 1, 1, 0}, {1, 0, 2, 2, 2}, {2, 0, 0, 2, 2}}, 4);
    test({{1, 2, 2, 2, 2}, {2, 2, 2, 2, 0}, {2, 0, 0, 0, 0}, {0, 0, 2, 2, 2}, {2, 0, 0, 2, 0}}, 5);
    test({{1}}, 1);
    test({{1, 2}, {2, 0}}, 1);

    return 0;
}
