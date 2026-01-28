#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

void minCost(vector<vector<int>>& grid, vector<vector<int>>& costs, vector<vector<int>>& nextCost, vector<tuple<short, short, short>>& sortedGrid, int& cost, int& teleports) {
    short m = grid.size() - 1;
    short n = grid[0].size() - 1;

    int i;
    short j;
    for(i = 0; i <= m; ++i) {
        for(j = 0; j <= n; ++j) {
            nextCost[i][j] = INT_MAX;
        }
    }

    short k;
    short l;
    for(i = 0; i <= m; ++i) {
        for(j = 0; j <= n; ++j) {
            if(i < m && costs[i][j] + grid[i + 1][j] < costs[i + 1][j]) {
                costs[i + 1][j] = costs[i][j] + grid[i + 1][j];
            }

            if(j < n && costs[i][j] + grid[i][j + 1] < costs[i][j + 1]) {
                costs[i][j + 1] = costs[i][j] + grid[i][j + 1];
            }
        }
    }

    i = INT_MAX;

    for(k = ++m * ++n - 1; k > -1; --k) {
        l = k++;

        while(--k > -1 && get<0>(sortedGrid[k]) == get<0>(sortedGrid[l])) {
            if(costs[get<1>(sortedGrid[k])][get<2>(sortedGrid[k])] < i) {
                i = costs[get<1>(sortedGrid[k])][get<2>(sortedGrid[k])];
            }
        }

        while(l > k) {
            nextCost[get<1>(sortedGrid[l])][get<2>(sortedGrid[l])] = i;
            --l;
        }
        ++k;
    }

    if(costs[--m][--n] < cost) {
        cost = costs[m][n];
    }

    if(teleports > 0) {
        minCost(grid, nextCost, costs, sortedGrid, cost, --teleports);
    }
}

int minCost(vector<vector<int>>& grid, int k) {
    int cost = INT_MAX;
    short m = grid.size();
    short n = grid[0].size();
    vector<vector<int>> costs(m, vector<int>(n, 1000000000));
    vector<vector<int>> nextCost(m, vector<int>(n));
    vector<tuple<short, short, short>> sortedGrid;

    short i;
    short j;
    for(i = 0; i < m; ++i) {
        for(j = 0; j < n; ++j) {
            sortedGrid.push_back({grid[i][j], i, j});
        }
    }

    sort(sortedGrid.begin(), sortedGrid.end());
    costs[0][0] = 0;
    minCost(grid, costs, nextCost, sortedGrid, cost, k);

    return cost;
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

    cout << "Result: " << minCost(grid, k) << endl;

    cout << endl;
}

int main() {
    test({{1, 3, 3}, {2, 5, 4}, {4, 3, 5}}, 2, 7);
    test({{1, 2}, {2, 3}, {3, 4}}, 1, 9);
    test({{20, 25, 2}, {15, 22, 15}}, 0, 42);
    test({{3, 1}, {10, 4}}, 7, 4);
    test({{5, 100, 100}, {100, 100, 100}, {100, 100, 1}}, 1, 0);

    return 0;
}
