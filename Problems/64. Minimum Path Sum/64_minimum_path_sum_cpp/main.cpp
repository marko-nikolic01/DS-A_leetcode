#include <iostream>
#include <vector>

using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int x = grid.size();
    int y = grid[0].size();

    for(int i = x - 2; i > -1; --i) {
        grid[i][y - 1] += grid[i + 1][y - 1];
    }

    for(int i = y - 2; i > -1; --i) {
        grid[x - 1][i] += grid[x - 1][i + 1];
    }

    for(int i = x - 2; i > -1; --i) {
        for(int j = y - 2; j > -1; --j) {
            grid[i][j] += grid[i + 1][j] < grid[i][j + 1] ? grid[i + 1][j] : grid[i][j + 1];
        }
    }

    return grid[0][0];
}

void printGrid(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

void runTest(vector<vector<int>> grid, int expected) {
    cout << "Input:" << endl;
    printGrid(grid);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minPathSum(grid) << endl;

    cout << endl;
}

int main() {
    runTest({{1, 2}, {1, 1}}, 3);

    runTest({{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}, 7);

    runTest({{1, 2}}, 3);

    runTest({{1}, {2}}, 3);

    runTest({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, 21);

    return 0;
}
