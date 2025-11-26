#include <iostream>
#include <vector>

using namespace std;

int numberOfPaths(vector<vector<int>>& grid, int k) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<vector<int>>> paths(m, vector<vector<int>>(n, vector<int>(k, 0)));
    short remainder;

    remainder = grid[0][0] % k;
    ++paths[0][0][remainder];

    int j;
    short l;
    for(j = 1; j < m; ++j) {
        l = (grid[j][0] + remainder) % k;
        ++paths[j][0][l];
        remainder = l;
    }

    remainder = grid[0][0] % k;

    for(j = 1; j < n; ++j) {
        l = (grid[0][j] + remainder) % k;
        ++paths[0][j][l];
        remainder = l;
    }

    for(int i = 1; i < m; ++i) {
        for(j = 1; j < n; ++j) {
            for(l = 0; l < k; ++l) {
                remainder = (l + grid[i][j]) % k;
                paths[i][j][remainder] = ((paths[i][j][remainder] + paths[i - 1][j][l]) % 1000000007 + paths[i][j - 1][l]) % 1000000007;
            }
        }
    }

    return paths[--m][--n][0];
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> grid, int k, int expected) {
    cout << "Matrix:" << endl;
    printMatrix(grid);

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numberOfPaths(grid, k) << endl;

    cout << endl;
}

int main() {
    test({{5, 2, 4}, {3, 0, 5}, {0, 7, 2}}, 3, 2);
    test({{0, 0}}, 5, 1);
    test({{7, 3, 4, 9}, {2, 3, 6, 2}, {2, 3, 7, 0}}, 1, 10);
    test({{1}}, 1, 1);
    test({{1}}, 2, 0);

    return 0;
}
