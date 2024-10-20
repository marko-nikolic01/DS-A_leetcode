#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<int> onesRow(m, 0);
    vector<int> onesColumn(n, 0);

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(grid[i][j] == 1) {
                onesRow[i] += 2;
                onesColumn[j] += 2;
            }
        }
    }

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            grid[i][j] = onesRow[i] + onesColumn[j] - m - n;
        }
    }

    return grid;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> grid, vector<vector<int>> expected) {
    cout << "Matrix:" << endl;
    printMatrix(grid);

    cout << "Expected:" << endl;
    printMatrix(expected);

    cout << "Result:" << endl;
    printMatrix(onesMinusZeros(grid));

    cout << endl;
}

int main() {
    test({{0, 0}, {0, 0}}, {{-4, -4}, {-4, -4}});
    test({{1, 1}, {1, 1}}, {{4, 4}, {4, 4}});
    test({{1, 0}, {0, 1}}, {{0, 0}, {0, 0}});
    test({{1, 1, 0}, {0, 0, 0}}, {{1, 1, -1}, {-3, -3, -5}});
    test({{1, 0, 1}, {1, 1, 0}}, {{3, 1, 1}, {3, 1, 1}});

    return 0;
}
