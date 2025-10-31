#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<short, short>> rottenOranges;
    short freshOranges = 0;
    short time = 0;

    short x;
    short y;
    short m = grid.size();
    short n = grid[0].size();
    for(x = 0; x < m; ++x) {
        for(y = 0; y < n; ++y) {
            if(grid[x][y] > 1) {
                rottenOranges.push({x, y});
            } else if(grid[x][y] > 0) {
                ++freshOranges;
            }
        }
    }

    short i;
    --m;
    --n;
    while(freshOranges > 0 && !rottenOranges.empty()) {
        ++time;

        for(i = rottenOranges.size(); i > 0; --i) {
            x = rottenOranges.front().first;
            y = rottenOranges.front().second;
            rottenOranges.pop();

            if(x > 0 && grid[x - 1][y] == 1) {
                --freshOranges;
                ++grid[x - 1][y];
                rottenOranges.push({x - 1, y});
            }

            if(x < m && grid[x + 1][y] == 1) {
                --freshOranges;
                ++grid[x + 1][y];
                rottenOranges.push({x + 1, y});
            }

            if(y > 0 && grid[x][y - 1] == 1) {
                --freshOranges;
                ++grid[x][y - 1];
                rottenOranges.push({x, y - 1});
            }

            if(y < n && grid[x][y + 1] == 1) {
                --freshOranges;
                ++grid[x][y + 1];
                rottenOranges.push({x, y + 1});
            }
        }
    }

    return freshOranges < 1 ? time : -1;
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
    cout << "Oranges:" << endl;
    printMatrix(grid);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << orangesRotting(grid) << endl;

    cout << endl;
}

int main() {
    test({{2, 1, 1}, {1, 1, 0}, {0, 1, 1}}, 4);
    test({{2, 1, 1}, {0, 1, 1}, {1, 0, 1}}, -1);
    test({{0, 2}}, 0);
    test({{1, 1}, {1, 1}}, -1);
    test({{2, 2, 2}, {2, 2, 2}}, 0);
    test({{2, 1, 0}, {1, 1, 1}, {0, 1, 2}}, 2);
    test({{1}}, -1);
    test({{2}}, 0);

    return 0;
}
