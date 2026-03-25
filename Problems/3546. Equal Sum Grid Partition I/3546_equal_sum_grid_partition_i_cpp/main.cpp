#include <iostream>
#include <vector>

using namespace std;

bool canPartitionGrid(vector<vector<int>>& grid) {
    long target = 0;
    long sum = 0;

    int i;
    int j;
    int m = grid.size();
    int n = grid[0].size();
    for(i = 0; i < m; ++i) {
        for (j = 0; j < n; ++j) {
            target += grid[i][j];
        }
    }

    if((target & 1) > 0) {
        return false;
    }

    target >>= 1;

    for(i = 0; i < m - 1; ++i) {
        for(j = 0; j < n; ++j) {
            sum += grid[i][j];

        }

        if(sum == target) {
            return true;
        }
    }

    sum = 0;

    for(j = 0; j < n - 1; ++j) {
        for(i = 0; i < m; i++) {
            sum += grid[i][j];
        }

        if(sum == target) {
            return true;
        }
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
    test({{1, 3}, {2, 4}}, false);
    test({{1, 1}, {1, 1}}, true);
    test({{3, 3, 3}, {1, 4, 4}}, true);
    test({{1, 2, 3}, {3, 2, 1}, {2, 2, 2}}, false);

    return 0;
}
