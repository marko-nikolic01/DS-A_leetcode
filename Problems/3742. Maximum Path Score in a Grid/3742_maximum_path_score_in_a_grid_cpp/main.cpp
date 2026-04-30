#include <iostream>
#include <vector>

using namespace std;

int maxPathScore(vector<vector<int>>& grid, int k) {
    if(k < 1 && grid[0][0] > 0) {
        return -1;
    }

    short m = grid.size();
    short n = grid[0].size();
    vector<vector<vector<unsigned short>>> scores(m, vector<vector<unsigned short>>(n, vector<unsigned short>(++k, 0)));
    int cost;

    if(grid[0][0] > 0) {
        scores[0][0][1] = grid[0][0];
    } else {
        ++scores[0][0][0];
    }

    short j;
    short l;
    for(short i = 0; i < m; ++i) {
        for(j = 0; j < n; ++j) {
            cost = grid[i][j] < 1 ? 0 : 1;

            if(i > 0) {
                for(l = 0; l < k - cost; ++l) {
                    if(scores[i - 1][j][l] > 0 && scores[i - 1][j][l] + grid[i][j] > scores[i][j][l + cost]) {
                        scores[i][j][l + cost] = scores[i - 1][j][l] + grid[i][j];
                    }
                }
            }

            if(j > 0) {
                for(l = 0; l < k - cost; ++l) {
                    if(scores[i][j - 1][l] > 0 && scores[i][j - 1][l] + grid[i][j] > scores[i][j][l + cost]) {
                        scores[i][j][l + cost] = scores[i][j - 1][l] + grid[i][j];
                    }
                }
            }
        }
    }

    cost = scores[--m][--n][0];

    for(j = 1; j < k; ++j) {
        if(scores[m][n][j] > cost) {
            cost = scores[m][n][j];
        }
    }

    return --cost;
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

    cout << "Result: " << maxPathScore(grid, k) << endl;

    cout << endl;
}

int main() {
    test({{0, 1}, {2, 0}}, 1, 2);
    test({{0, 1}, {1, 2}}, 1, -1);
    test({{0}}, 0, 0);
    test({{0, 1, 2}}, 2, 3);
    test({{0, 1}, {0, 2}}, 1, 2);

    return 0;
}
