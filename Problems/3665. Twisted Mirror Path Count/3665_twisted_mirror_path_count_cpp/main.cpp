#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int uniquePaths(vector<vector<int>>& grid) {
    short m = grid.size();
    short n = grid[0].size();
    vector<vector<pair<int, int>>> paths(m--, vector<pair<int, int>>(n--, {0, 0}));
    paths[0][0].first = 1;

    queue<pair<short, short>> traversal;
    traversal.push({0, 0});

    short x;
    short y;

    while(!traversal.empty()) {
        x = traversal.front().first;
        y = traversal.front().second;
        traversal.pop();

        if(grid[x][y] < 1) {
            if(x < m) {
                if(paths[x + 1][y].first < 1 && paths[x + 1][y].second < 1) {
                    traversal.push({x + 1, y});
                }

                paths[x + 1][y].first = (paths[x][y].first + paths[x][y].second) % 1000000007;
            }

            if(y < n) {
                if(paths[x][y + 1].first < 1 && paths[x][y + 1].second < 1) {
                    traversal.push({x, y + 1});
                }

                paths[x][y + 1].second = (paths[x][y].first + paths[x][y].second) % 1000000007;
            }
        } else {
            if(x < m && paths[x][y].second > 0) {
                if(paths[x + 1][y].first < 1 && paths[x + 1][y].second < 1) {
                    traversal.push({x + 1, y});
                }

                paths[x + 1][y].first = paths[x][y].second;
            }

            if(y < n && paths[x][y].first > 0) {
                if(paths[x][y + 1].first < 1 && paths[x][y + 1].second < 1) {
                    traversal.push({x, y + 1});
                }

                paths[x][y + 1].second = paths[x][y].first;
            }
        }
    }

    return (paths[m][n].first + paths[m][n].second) % 1000000007;
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

    cout << "Result: " << uniquePaths(grid) << endl;

    cout << endl;
}

int main() {
    test({{0, 0}, {0, 0}}, 2);
    test({{0, 1, 0}, {0, 0, 1}, {1, 0, 0}}, 5);
    test({{0, 1, 1}, {1, 1, 0}}, 1);
    test({{0, 1}, {1, 0}}, 2);
    test({{0, 0, 1, 0}, {0, 1, 0, 0}, {0, 0, 0, 0}}, 6);

    return 0;
}
