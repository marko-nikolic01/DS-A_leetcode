#include <iostream>
#include <vector>

using namespace std;

short minimumSum(vector<vector<int>>& grid, short x1, short x2, short y1, short y2) {
    short top1 = x2 + 1;
    short bottom1 = x1 - 1;
    short left1 = y2 + 1;
    short right1 = y1 - 1;
    bool hasOne = false;

    short j;
    for(short i = x1; i <= x2; ++i) {
        for(j = y1; j <= y2; ++j) {
            if(grid[i][j] > 0) {
                hasOne = true;

                if(i < top1) {
                    top1 = i;
                }

                if(i > bottom1) {
                    bottom1 = i;
                }

                if(j < left1) {
                    left1 = j;
                }

                if(j > right1) {
                    right1 = j;
                }
            }
        }
    }

    return hasOne ? (++bottom1 - top1) * (++right1 - left1) : 0;
}

short minimumSum(short x1, short x2, short y1, short y2, vector<vector<int>>& grid) {
    short minimumArea = 1000;
    short area1;
    short area2;
    bool hasOne = false;

    short i;
    for(i = x1; i < x2; ++i) {
        area1 = minimumSum(grid, x1, i, y1, y2);

        if(area1 < 1) {
            continue;
        }

        area2 = minimumSum(grid, i + 1, x2, y1, y2);

        if(area2 < 1) {
            continue;
        }

        if(area1 + area2 < minimumArea) {
            minimumArea = area1 + area2;
            hasOne = true;
        }
    }

    for(i = y1; i < y2; ++i) {
        area1 = minimumSum(grid, x1, x2, y1, i);

        if(area1 < 1) {
            continue;
        }

        area2 = minimumSum(grid, x1, x2, i + 1, y2);

        if(area2 < 1) {
            continue;
        }

        if(area1 + area2 < minimumArea) {
            minimumArea = area1 + area2;
            hasOne = true;
        }
    }

    return hasOne ? minimumArea : 0;
}

int minimumSum(vector<vector<int>>& grid) {
    short minimumArea = 1000;
    short area1;
    short area23;

    short i;
    short m = grid.size() - 1;
    short n = grid[0].size() - 1;
    for(i = 0; i < m; ++i) {
        area1 = minimumSum(grid, 0, i, 0, n);

        if(area1 < 1) {
            continue;
        }

        area23 = minimumSum(i + 1, m, 0, n, grid);

        if(area23 < 1) {
            continue;
        }

        if(area1 + area23 < minimumArea) {
            minimumArea = area1 + area23;
        }
    }

    for(i = m; i > 0; --i) {
        area1 = minimumSum(grid, i, m, 0, n);

        if(area1 < 1) {
            continue;
        }

        area23 = minimumSum(0, i - 1, 0, n, grid);

        if(area23 < 1) {
            continue;
        }

        if(area1 + area23 < minimumArea) {
            minimumArea = area1 + area23;
        }
    }

    for(i = 0; i < n; ++i) {
        area1 = minimumSum(grid, 0, m, 0, i);

        if(area1 < 1) {
            continue;
        }

        area23 = minimumSum(0, m, i + 1, n, grid);

        if(area23 < 1) {
            continue;
        }

        if(area1 + area23 < minimumArea) {
            minimumArea = area1 + area23;
        }
    }

    for(i = n; i > 0; --i) {
        area1 = minimumSum(grid, 0, m, i, n);

        if(area1 < 1) {
            continue;
        }

        area23 = minimumSum(0, m, 0, i - 1, grid);

        if(area23 < 1) {
            continue;
        }

        if(area1 + area23 < minimumArea) {
            minimumArea = area1 + area23;
        }
    }

    return minimumArea;
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

    cout << "Result: " << minimumSum(grid) << endl;

    cout << endl;
}

int main() {
    test({{1, 0, 1}, {1, 1, 1}}, 5);
    test({{1, 0, 1, 0}, {0, 1, 0, 1}}, 5);
    test({{1, 1, 0, 1}, {0, 0, 0, 1}, {1, 1, 0, 1}}, 7);
    test({{1, 1, 1}, {1, 1, 1}}, 6);
    test({{1, 0, 0, 0, 1}, {0, 0, 0, 0, 0}, {1, 0, 0, 0, 1}}, 5);

    return 0;
}
