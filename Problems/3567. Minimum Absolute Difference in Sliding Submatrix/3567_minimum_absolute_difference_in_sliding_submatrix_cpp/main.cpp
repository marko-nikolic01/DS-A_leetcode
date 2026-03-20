#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
    short m = grid.size();
    short n = grid[0].size();
    vector<vector<int>> result(m - k + 1, vector<int>(n - k + 1));
    vector<int> kGrid;
    short y;
    short x;
    int kMinimum;

    short j;
    for(short i = 0; i + k <= m; ++i) {
        for(j = 0; j + k <= n; ++j) {
            kGrid.resize(0);

            for(x = i; x < i + k; ++x) {
                for(y = j; y < j + k; ++y) {
                    kGrid.push_back(grid[x][y]);
                }
            }

            kMinimum = INT_MAX;
            sort(kGrid.begin(), kGrid.end());

            y = kGrid.size();
            for(x = 1; x < y; ++x) {
                if(kGrid[x] == kGrid[x - 1]) {
                    continue;
                }

                kMinimum = min(kMinimum, kGrid[x] - kGrid[x - 1]);
            }

            if(kMinimum != INT_MAX) {
                result[i][j] = kMinimum;
            }
        }
    }

    return result;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> grid, int k, vector<vector<int>> expected) {
    cout << "Matrix:" << endl;
    printMatrix(grid);

    cout << "k: " << k << endl;

    cout << "Expected:" << endl;
    printMatrix(expected);

    cout << "Result:" << endl;
    printMatrix(minAbsDiff(grid, k));

    cout << endl;
}

int main() {
    test({{1, 8}, {3, -2}}, 2, {{2}});
    test({{3, -1}}, 1, {{0, 0}});
    test({{1, -2, 3}, {2, 3, 5}}, 2, {{1, 2}});
    test({{5, 5, 5}, {5, 5, 5}, {5, 5, 5}}, 2, {{0, 0}, {0, 0}});
    test({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, 2, {{1, 1}, {1, 1}});

    return 0;
}
