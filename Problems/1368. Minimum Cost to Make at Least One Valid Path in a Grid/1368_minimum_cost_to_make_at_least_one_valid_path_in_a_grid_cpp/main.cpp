#include <iostream>
#include <vector>

using namespace std;

void minCost(vector<vector<int>>& grid, short& m, short& n, vector<vector<short>>& costs, short x, short y, short currentCost) {
    costs[x][y] = -currentCost - 1;

    if(x > 0) {
        if(grid[x][y] == 4) {
            if(-costs[x - 1][y] - 1 > currentCost) {
                minCost(grid, m, n, costs, x - 1, y, currentCost);
            }
        } else if(-costs[x - 1][y] - 2 > currentCost) {
            minCost(grid, m, n, costs, x - 1, y, currentCost + 1);
        }
    }

    if(x < m) {
        if(grid[x][y] == 3) {
            if(-costs[x + 1][y] - 1 > currentCost) {
                minCost(grid, m, n, costs, x + 1, y, currentCost);
            }
        } else if(-costs[x + 1][y] - 2 > currentCost) {
            minCost(grid, m, n, costs, x + 1, y, currentCost + 1);
        }
    }

    if(y > 0) {
        if(grid[x][y] == 2) {
            if(-costs[x][y - 1] - 1 > currentCost) {
                minCost(grid, m, n, costs, x, y - 1, currentCost);
            }
        } else if(-costs[x][y - 1] - 2 > currentCost) {
            minCost(grid, m, n, costs, x, y - 1, currentCost + 1);
        }
    }

    if(y < n) {
        if(grid[x][y] == 1) {
            if(-costs[x][y + 1] - 1 > currentCost) {
                minCost(grid, m, n, costs, x, y + 1, currentCost);
            }
        } else if(-costs[x][y + 1] - 2 > currentCost) {
            minCost(grid, m, n, costs, x, y + 1, currentCost + 1);
        }
    }
}

int minCost(vector<vector<int>>& grid) {
    short m = grid.size();
    short n = grid[0].size();

    vector<vector<short>> costs(m, vector<short>(n, -1001));

    short cost = 1000;

    minCost(grid, --m, --n, costs, 0, 0, 0);

    return -(++costs[m][n]);
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

    cout << "Result: " << minCost(grid) << endl;

    cout << endl;
}

int main() {
    test({{1, 1, 1, 1}, {2, 2, 2, 2}, {1, 1, 1, 1}, {2, 2, 2, 2}}, 3);
    test({{1, 1, 3}, {3, 2, 2}, {1, 1, 4}}, 0);
    test({{1, 2}, {4, 3}}, 1);
    test({{1, 3, 1}, {3, 4, 2}, {2, 3, 1}}, 2);
    test({{3, 3, 3}, {4, 4, 4}, {1, 1, 1}}, 1);

    return 0;
}
