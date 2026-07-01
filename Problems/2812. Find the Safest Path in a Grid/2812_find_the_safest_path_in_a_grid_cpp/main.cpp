#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int maximumSafenessFactor(vector<vector<int>>& grid) {
    queue<pair<short, short>> thieves;
    priority_queue<tuple<short, short, short>> traversal;
    short safeness = 0;
    short x;
    short y;

    short n = grid.size();
    for(x = --n; x > -1; --x) {
        for(y = n; y > -1; --y) {
            if(grid[x][y] > 0) {
                --grid[x][y];
                thieves.push({x, y});
            } else {
                grid[x][y] = -1;
            }
        }
    }

    int i;
    while(!thieves.empty()) {
        ++safeness;

        for(i = thieves.size(); i > 0; --i) {
            x = thieves.front().first;
            y = thieves.front().second;
            thieves.pop();

            if(x > 0 && grid[x - 1][y] < 0) {
                grid[--x][y] = safeness;
                thieves.push({x++, y});
            }

            if(x < n && grid[x + 1][y] < 0) {
                grid[++x][y] = safeness;
                thieves.push({x--, y});
            }

            if(y > 0 && grid[x][y - 1] < 0) {
                grid[x][--y] = safeness;
                thieves.push({x, y++});
            }

            if(y < n && grid[x][++y] < 0) {
                grid[x][y] = safeness;
                thieves.push({x, y});
            }
        }
    }

    traversal.push({grid[0][0], 0, 0});
    grid[0][0] = -1;

    while(true) {
        safeness = get<0>(traversal.top());
        x = get<1>(traversal.top());
        y = get<2>(traversal.top());
        traversal.pop();

        if(x == n && y == n) {
            break;
        }

        if(x > 0 && grid[x - 1][y] > -1) {
            traversal.push({min((short)grid[--x][y], safeness), x, y});
            grid[x++][y] = -1;
        }

        if(x < n && grid[x + 1][y] > -1) {
            traversal.push({min((short)grid[++x][y], safeness), x, y});
            grid[x--][y] = -1;
        }

        if(y > 0 && grid[x][y - 1] > -1) {
            traversal.push({min((short)grid[x][--y], safeness), x, y});
            grid[x][y++] = -1;
        }

        if(y < n && grid[x][++y] > -1) {
            traversal.push({min((short)grid[x][y], safeness), x, y});
            grid[x][y] = -1;
        }
    }

    return safeness;
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
    cout << "Thieves:" << endl;
    printMatrix(grid);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maximumSafenessFactor(grid) << endl;

    cout << endl;
}

int main() {
    test({{1, 0, 0}, {0, 0, 0}, {0, 0, 1}}, 0);
    test({{0, 0, 1}, {0, 0, 0}, {0, 0, 0}}, 2);
    test({{0, 0, 0, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}, {1, 0, 0, 0}}, 2);
    test({{1}}, 0);
    test({{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}}, 2);

    return 0;
}
