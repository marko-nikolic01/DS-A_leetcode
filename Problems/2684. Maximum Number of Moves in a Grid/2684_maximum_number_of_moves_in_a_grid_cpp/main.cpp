#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int maxMoves(vector<vector<int>>& grid, unordered_map<int, int>& explored, int x, int y, int moves) {
    int n = grid[0].size();

    if(y == n - 1) {
        return moves;
    }

    int maximumMoves = moves;

    moves++;

    if(grid[x][y] < grid[x][y + 1]) {
        int currentMoves = explored.find(x * n + y + 1) != explored.end() ? explored[x * n + y + 1] : maxMoves(grid, explored, x, y + 1, moves);
        if(currentMoves > maximumMoves) {
            maximumMoves = currentMoves;
        }
    }

    if(x > 0 && grid[x][y] < grid[x - 1][y + 1]) {
        int currentMoves = explored.find((x - 1) * n + y + 1) != explored.end() ? explored[(x - 1) * n + y + 1] : maxMoves(grid, explored, x - 1, y + 1, moves);
        if(currentMoves > maximumMoves) {
            maximumMoves = currentMoves;
        }
    }

    if(x < grid.size() - 1 && grid[x][y] < grid[x + 1][y + 1]) {
        int currentMoves =  explored.find((x + 1) * n + y + 1) != explored.end() ? explored[(x + 1) * n + y + 1] : maxMoves(grid, explored, x + 1, y + 1, moves);
        if(currentMoves > maximumMoves) {
            maximumMoves = currentMoves;
        }
    }

    explored[x * n + y] = maximumMoves;

    return maximumMoves;
}

int maxMoves(vector<vector<int>>& grid) {
    unordered_map<int, int> explored;

    int maximumMoves = 0;

    int m = grid.size();
    int n = grid[0].size();

    for(int i = 0; i < m; ++i) {
        int moves = maxMoves(grid, explored, i, 0, 0);
        if(moves > maximumMoves) {
            maximumMoves = moves;
        }
    }

    return maximumMoves;
}

void printGrid(const vector<vector<int>>& grid) {
    for(const auto& row : grid) {
        for(int val : row) {
            cout << val << " " << val;
        }
        cout << endl;
    }
}

void test(vector<vector<int>> grid, int expected) {
    cout << "Matrix:" << endl;;
    printGrid(grid);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxMoves(grid) << endl;

    cout << endl;
}

int main() {
    vector<vector<int>> grid1 = {
        {3, 4, 5},
        {3, 2, 6},
        {2, 2, 1}
    };
    test(grid1, 2);

    vector<vector<int>> grid2 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    test(grid2, 2);

    vector<vector<int>> grid3 = {
        {8, 1, 6},
        {3, 7, 4},
        {5, 9, 2}
    };
    test(grid3, 1);

    vector<vector<int>> grid4 = {
        {10, 1, 100},
        {10, 1, 100},
        {10, 1, 100}
    };
    test(grid4, 0);

    return 0;
}
