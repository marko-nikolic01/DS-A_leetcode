#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
    vector<vector<int>> grid(n, vector<int>(m, 0));
    vector<vector<int>> times(n--, vector<int>(m--, 0));
    queue<pair<int, int>> traversal;
    int x;
    int y;
    int time = 0;

    int i = sources.size();
    while(--i > -1) {
        grid[sources[i][0]][sources[i][1]] = sources[i][2];
        traversal.push({sources[i][0], sources[i][1]});
    }

    while(!traversal.empty()) {
        ++time;

        for(i = traversal.size(); i > 0; --i) {
            x = traversal.front().first;
            y = traversal.front().second;
            traversal.pop();

            if(x > 0) {
                if(grid[x - 1][y] < 1) {
                    grid[x - 1][y] = grid[x][y];
                    times[x - 1][y] = time;
                    traversal.push({x - 1, y});
                } else if(times[x - 1][y] == time && grid[x - 1][y] < grid[x][y]) {
                    grid[x - 1][y] = grid[x][y];
                }
            }

            if(x < n) {
                if(grid[x + 1][y] < 1) {
                    grid[x + 1][y] = grid[x][y];
                    times[x + 1][y] = time;
                    traversal.push({x + 1, y});
                } else if(times[x + 1][y] == time && grid[x + 1][y] < grid[x][y]) {
                    grid[x + 1][y] = grid[x][y];
                }
            }

            if(y > 0) {
                if(grid[x][y - 1] < 1) {
                    grid[x][y - 1] = grid[x][y];
                    times[x][y - 1] = time;
                    traversal.push({x, y - 1});
                } else if(times[x][y - 1] == time && grid[x][y - 1] < grid[x][y]) {
                    grid[x][y - 1] = grid[x][y];
                }
            }

            if(y < m) {
                if(grid[x][y + 1] < 1) {
                    grid[x][y + 1] = grid[x][y];
                    times[x][y + 1] = time;
                    traversal.push({x, y + 1});
                } else if(times[x][y + 1] == time && grid[x][y + 1] < grid[x][y]) {
                    grid[x][y + 1] = grid[x][y];
                }
            }
        }
    }

    return grid;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(int n, int m, vector<vector<int>> sources, vector<vector<int>> expected) {
    cout << "n: " << n << endl;

    cout << "m: " << m << endl;

    cout << "Sources: ";
    for(vector<int> source : sources) {
        cout << "[" << source[0] << ", " << source[1] << ", " << source[2] << "] ";
    }
    cout << endl;

    cout << "Expected:" << endl;
    printMatrix(expected);

    cout << "Result:" << endl;
    printMatrix(colorGrid(n, m, sources));

    cout << endl;
}

int main() {
    test(3, 3, {{0, 0, 1}, {2, 2, 2}}, {{1, 1, 2}, {1, 2, 2}, {2, 2, 2}});
    test(3, 3, {{0, 1, 3}, {1, 1, 5}}, {{3, 3, 3}, {5, 5, 5}, {5, 5, 5}});
    test(2, 2, {{1, 1, 5}}, {{5, 5}, {5, 5}});
    test(1, 3, {{0, 0, 2}, {0, 2, 1}}, {{2, 2, 1}});
    test(2, 3, {{0, 0, 3}}, {{3, 3, 3}, {3, 3, 3}});

    return 0;
}
