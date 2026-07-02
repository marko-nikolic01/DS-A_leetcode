#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool findSafeWalk(vector<vector<int>>& grid, int health) {
    queue<pair<short, short>> safe;
    queue<pair<short, short>> unsafe;
    short x;
    short y;

    (grid[0][0] < 1 ? safe : unsafe).push({0, 0});
    grid[0][0] = -1;

    short i;
    short m = grid.size() - 1;
    short n = grid[0].size() - 1;
    while(true) {
        while(!safe.empty()) {
            x = safe.front().first;
            y = safe.front().second;
            safe.pop();

            if(x == m && y == n) {
                return true;
            }

            if(x < m && grid[x + 1][y] > -1) {
                (grid[++x][y] < 1 ? safe : unsafe).push({x, y});
                grid[x--][y] = -1;
            }

            if(y < n && grid[x][y + 1] > -1) {
                (grid[x][++y] < 1 ? safe : unsafe).push({x, y});
                grid[x][y--] = -1;
            }

            if(x > 0 && grid[x - 1][y] > -1) {
                (grid[--x][y] < 1 ? safe : unsafe).push({x, y});
                grid[x++][y] = -1;
            }

            if(y > 0 && grid[x][--y] > -1) {
                (grid[x][y] < 1 ? safe : unsafe).push({x, y});
                grid[x][y] = -1;
            }
        }

        if(--health < 1) {
            break;
        }

        for(i = unsafe.size(); i > 0; --i) {
            x = unsafe.front().first;
            y = unsafe.front().second;
            unsafe.pop();

            if(x == m && y == n) {
                return true;
            }

            if(x < m && grid[x + 1][y] > -1) {
                (grid[++x][y] < 1 ? safe : unsafe).push({x, y});
                grid[x--][y] = -1;
            }

            if(y < n && grid[x][y + 1] > -1) {
                (grid[x][++y] < 1 ? safe : unsafe).push({x, y});
                grid[x][y--] = -1;
            }

            if(x > 0 && grid[x - 1][y] > -1) {
                (grid[--x][y] < 1 ? safe : unsafe).push({x, y});
                grid[x++][y] = -1;
            }

            if(y > 0 && grid[x][--y] > -1) {
                (grid[x][y] < 1 ? safe : unsafe).push({x, y});
                grid[x][y] = -1;
            }
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

void test(vector<vector<int>> grid, int health, bool expected) {
    cout << "Safeness:" << endl;
    printMatrix(grid);

    cout << "Health: " << health << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (findSafeWalk(grid, health) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test({{0, 1, 0, 0, 0}, {0, 1, 0, 1, 0}, {0, 0, 0, 1, 0}}, 1, true);
    test({{0, 1, 1, 0, 0, 0}, {1, 0, 1, 0, 0, 0}, {0, 1, 1, 1, 0, 1}, {0, 0, 1, 0, 1, 0}}, 3, false);
    test({{1, 1, 1}, {1, 0, 1}, {1, 1, 1}}, 5, true);
    test({{0, 0}, {0, 0}}, 1, true);
    test({{1, 1}, {1, 1}}, 2, false);

    return 0;
}
