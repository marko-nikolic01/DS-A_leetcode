#include <iostream>
#include <vector>

using namespace std;

int largestIsland(vector<vector<int>>& grid) {
    vector<short> islands;
    int islandI = -1;

    vector<int> traversal;
    int x;
    int y;

    short i;
    short j;
    short n = grid.size();
    for(i = n - 1; i > -1; --i) {
        for(j = n - 1; j > -1; --j) {
            if(grid[i][j] == 1) {
                traversal.push_back(i * n + j);

                islands.push_back(0);
                grid[i][j] = ++islandI + 2;

                while(!traversal.empty()) {
                    x = traversal.back();
                    y = x % n;
                    x /= n;
                    traversal.pop_back();

                    ++islands[islandI];

                    if(x > 0 && grid[x - 1][y] == 1) {
                        traversal.push_back((x - 1) * n + y);
                        grid[x - 1][y] = islandI + 2;
                    }

                    if(x < n - 1 && grid[x + 1][y] == 1) {
                        traversal.push_back((x + 1) * n + y);
                        grid[x + 1][y] = islandI + 2;
                    }

                    if(y > 0 && grid[x][y - 1] == 1) {
                        traversal.push_back(x * n + y - 1);
                        grid[x][y - 1] = islandI + 2;
                    }

                    if(y < n - 1 && grid[x][++y] == 1) {
                        traversal.push_back(x * n + y);
                        grid[x][y] = islandI + 2;
                    }
                }
            }
        }
    }

    if(islandI < 0) {
        return 1;
    }

    int largestIslandArea = islands[0];

    int island;

    for(i = --n; i > -1; --i) {
        for(j = n; j > -1; --j) {
            if(grid[i][j] < 1) {
                island = 1;

                islandI = -1;
                x = -1;
                y = -1;

                if(i > 0 && grid[i - 1][j] > 0) {
                    islandI = grid[i - 1][j];
                    island += islands[islandI - 2];
                }

                if(i < n && grid[i + 1][j] > 0) {
                    if(grid[i + 1][j] != islandI) {
                        x = grid[i + 1][j];
                        island += islands[x - 2];
                    }
                }

                if(j > 0 && grid[i][j - 1] > 0) {
                    if(grid[i][j - 1] != islandI && grid[i][j - 1] != x) {
                        y = grid[i][j - 1];
                        island += islands[y - 2];
                    }
                }

                if(j < n && grid[i][j + 1] > 0) {
                    if(grid[i][j + 1] != islandI && grid[i][j + 1] != x && grid[i][j + 1] != y) {
                        island += islands[grid[i][j + 1] - 2];
                    }
                }

                if(island > largestIslandArea) {
                    largestIslandArea = island;
                }
            }
        }
    }

    return largestIslandArea;
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
    cout << "Islands:" << endl;
    printMatrix(grid);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << largestIsland(grid) << endl;

    cout << endl;
}

int main() {
    test({{1, 0}, {0, 1}}, 3);
    test({{1, 1}, {1, 0}}, 4);
    test({{1, 1}, {1, 1}}, 4);
    test({{0, 0}, {0, 0}}, 1);
    test({{1, 0, 1}, {0, 0, 0}, {1, 0, 1}}, 3);

    return 0;
}
