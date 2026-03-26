#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> canPartitionGrid(vector<vector<int>>& grid, bool a) {
    int m = grid.size();
    int n = grid[0].size();
    vector tmp(n, vector<int>(m));

    int j;
    for(int i = 0; i < m; ++i) {
        for(j = 0; j < n; ++j) {
            tmp[j][m - 1 - i] = grid[i][j];
        }
    }

    return tmp;
}

bool canPartitionGrid(vector<vector<int>>& grid) {
    long total = 0;
    long sum;
    long tag;
    unordered_set<long> exist;

    int i;
    int j;
    int m = grid.size();
    int n = grid[0].size();
    for(i = 0; i < m; ++i) {
        for(j = 0; j < n; ++j) {
            total += grid[i][j];
        }
    }

    for(short k = 0; k < 4; ++k) {
        exist.clear();
        exist.insert(0);
        sum = 0;
        m = grid.size();
        n = grid[0].size();

        if(m < 2) {
            grid = canPartitionGrid(grid, true);
            continue;
        }

        if(n == 1) {
            for(i = 0; i < m - 1; ++i) {
                sum += grid[i][0];
                tag = sum * 2 - total;

                if(tag == 0 || tag == grid[0][0] || tag == grid[i][0]) {
                    return true;
                }
            }

            grid = canPartitionGrid(grid, true);

            continue;
        }

        for(i = 0; i < m - 1; ++i) {
            for(j = 0; j < n; ++j) {
                exist.insert(grid[i][j]);
                sum += grid[i][j];
            }

            tag = sum * 2 - total;

            if(i == 0) {
                if(tag == 0 || tag == grid[0][0] ||
                    tag == grid[0][n - 1]) {
                    return true;
                }

                continue;
            }

            if(exist.contains(tag)) {
                return true;
            }
        }

        grid = canPartitionGrid(grid, true);
    }

    return false;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> grid, bool expected) {
    cout << "Matrix:" << endl;
    printMatrix(grid);

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (canPartitionGrid(grid) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test({{1, 4}, {2, 3}}, true);
    test({{1, 2}, {3, 4}}, true);
    test({{1, 2, 4}, {2, 3, 5}}, false);
    test({{4, 1, 8}, {3, 2, 6}}, false);
    test({{73816}, {71688}}, false);

    return 0;
}
