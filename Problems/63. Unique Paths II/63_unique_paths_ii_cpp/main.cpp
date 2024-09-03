#include <iostream>
#include <vector>

using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();

    if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) {
        return 0;
    }

    vector<vector<long long>> paths(m, vector<long long>(n, 0));

    paths[m - 1][n - 1] = -1;

    for (int i = m - 2; i >= 0; --i) {
        if (obstacleGrid[i][n - 1] == 0) {
            paths[i][n - 1] = paths[i + 1][n - 1];
        }
    }

    for (int i = n - 2; i >= 0; --i) {
        if (obstacleGrid[m - 1][i] == 0) {
            paths[m - 1][i] = paths[m - 1][i + 1];
        }
    }

    for (int i = m - 2; i >= 0; --i) {
        for (int j = n - 2; j >= 0; --j) {
            if (obstacleGrid[i][j] == 0) {
                paths[i][j] = paths[i + 1][j] + paths[i][j + 1];
            }
        }
    }

    return -paths[0][0];
}

void printGrid(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void runTest(vector<vector<int>> grid, int expected) {
    cout << "Input:" << endl;
    printGrid(grid);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << uniquePathsWithObstacles(grid) << endl;

    cout << endl;
}

int main() {
    runTest({{0, 0}, {0, 0}}, 2);

    runTest({{0, 0}, {0, 1}}, 0);

    runTest({{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}, 2);

    runTest({{0, 1, 0}, {1, 1, 0}, {0, 0, 0}}, 0);

    runTest({{0}}, 1);

    runTest({{1}}, 0);

    runTest({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, 6);

    return 0;
}

