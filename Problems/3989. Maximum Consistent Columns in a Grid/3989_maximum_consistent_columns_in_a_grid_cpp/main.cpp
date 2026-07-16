#include <iostream>
#include <vector>

using namespace std;

int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
    short columns = 0;
    short n = grid[0].size();
    vector<short> groups(n, 0);

    short j;
    short k;
    short m = grid.size();
    for(short i = 0; i < n; ++i) {
        for(j = i - 1; j >= groups[i]; --j) {
            for(k = 0; k < m; ++k) {
                if(abs(grid[k][i] - grid[k][j]) > limit) {
                    break;
                }
            }

            if(k == m && groups[j] >= groups[i]) {
                groups[i] = groups[j] + 1;
            }
        }

        if(groups[i] > columns) {
            columns = groups[i];
        }
    }

    return ++columns;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> grid, int limit, int expected) {
    cout << "Matrix:" << endl;
    printMatrix(grid);

    cout << "Limit: " << limit << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxConsistentColumns(grid, limit) << endl;

    cout << endl;
}

int main() {
    test({{-2, 0, 3}}, 2, 2);
    test({{1, -1, 1}, {2, 2, 2}}, 1, 2);
    test({{-5, 5}}, 9, 1);
    test({{21, 9, 18, 37, 16, 30, -16, 26, -14, -11, -17, 16, 23, 4, -2, 13, 37, -5, 27, -17, 34, -16, -10, 19, -17, 30, 6}}, 36, 21);
    test({{5}}, 0, 1);

    return 0;
}
