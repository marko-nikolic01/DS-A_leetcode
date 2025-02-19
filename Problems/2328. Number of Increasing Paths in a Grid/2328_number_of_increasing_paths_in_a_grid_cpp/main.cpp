#include <iostream>
#include <vector>

using namespace std;

void countPaths(vector<vector<int>>& grid, vector<vector<int>>& paths, short& m, short& n, short x, short y) {
    int path = 1;

    if(x > 0 && grid[x - 1][y] > grid[x][y]) {
        if(paths[x - 1][y] < 1) {
            countPaths(grid, paths, m, n, x - 1, y);
        }

        path = (path + paths[x - 1][y]) % 1000000007;
    }

    if(x < m && grid[x + 1][y] > grid[x][y]) {
        if(paths[x + 1][y] < 1) {
            countPaths(grid, paths, m, n, x + 1, y);
        }

        path = (path + paths[x + 1][y]) % 1000000007;
    }

    if(y > 0 && grid[x][y - 1] > grid[x][y]) {
        if(paths[x][y - 1] < 1) {
            countPaths(grid, paths, m, n, x, y - 1);
        }

        path = (path + paths[x][y - 1]) % 1000000007;
    }

    if(y < n && grid[x][y + 1] > grid[x][y]) {
        if(paths[x][y + 1] < 1) {
            countPaths(grid, paths, m, n, x, y + 1);
        }

        path = (path + paths[x][y + 1]) % 1000000007;
    }

    paths[x][y] = path;
}

int countPaths(vector<vector<int>>& grid) {
    short m = grid.size();
    short n = grid[0].size();
    vector<vector<int>> paths(m--, vector<int>(n--, 0));

    int path = 0;

    short y;
    for(short x = m; x > -1; --x) {
        for(y = n; y > -1; --y) {
            if(paths[x][y] < 1) {
                countPaths(grid, paths, m, n, x, y);
            }

            path = (path + paths[x][y]) % 1000000007;
        }
    }

    return path;
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

    cout << "Result: " << countPaths(grid) << endl;

    cout << endl;
}

int main() {
    test({{1, 1}, {3, 4}}, 8);
    test({{1}, {2}}, 3);
    test({{1, 2, 3}, {6, 5, 4}}, 26);
    test({{10, 9, 8}, {7, 6, 5}, {4, 3, 2}}, 53);
    test({{1, 2}, {3, 4}, {5, 6}}, 22);
    test({{1}}, 1);

    return 0;
}

