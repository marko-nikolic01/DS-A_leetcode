#include <iostream>
#include <vector>

using namespace std;

bool containsCycle(vector<vector<char>>& grid) {
    short m = grid.size();
    short n = grid[0].size();

    vector<tuple<short, short, short>> traversal;
    short x;
    short y;
    short direction;

    short j;
    --n;
    for(short i = --m; i > -1; --i) {
        for(j = n; j > -1; --j) {
            if(grid[i][j] > 96) {
                traversal.push_back({i, j, 0});
                grid[i][j] -= 32;

                while(!traversal.empty()) {
                    tie(x, y, direction) = traversal.back();
                    traversal.pop_back();

                    if(direction != 1 && x > 0) {
                        if(grid[x][y] == grid[x - 1][y]) {
                            return true;
                        } else if(grid[x][y] == grid[x - 1][y] - 32) {
                            traversal.push_back({x - 1, y, 2});
                            grid[x - 1][y] -= 32;
                        }
                    }

                    if(direction != 2 && x < m) {
                        if(grid[x][y] == grid[x + 1][y]) {
                            return true;
                        } else if(grid[x][y] == grid[x + 1][y] - 32) {
                            traversal.push_back({x + 1, y, 1});
                            grid[x + 1][y] -= 32;
                        }
                    }

                    if(direction != 3 && y > 0) {
                        if(grid[x][y] == grid[x][y - 1]) {
                            return true;
                        } else if(grid[x][y] == grid[x][y - 1] - 32) {
                            traversal.push_back({x, y - 1, 4});
                            grid[x][y - 1] -= 32;
                        }
                    }

                    if(direction != 4 && y < n) {
                        if(grid[x][y] == grid[x][y + 1]) {
                            return true;
                        } else if(grid[x][y] == grid[x][y + 1] - 32) {
                            traversal.push_back({x, ++y, 3});
                            grid[x][y] -= 32;
                        }
                    }
                }
            }
        }
    }

    return false;
}

void printMatrix(vector<vector<char>> matrix) {
    for(vector<char> row : matrix) {
        for(char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<char>> grid, bool expected) {
    cout << "Matrix:" << endl;
    printMatrix(grid);

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (containsCycle(grid) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test({{'a','a','a','a'},{'a','b','b','a'},{'a','b','b','a'},{'a','a','a','a'}}, true);
    test({{'c','c','c','a'},{'c','d','c','c'},{'c','c','e','c'},{'f','c','c','c'}}, true);
    test({{'a','b','b'},{'b','z','b'},{'b','b','a'}}, false);
    test({{'a','a'},{'a','a'}}, true);
    test({{'a','a'},{'a','b'}}, false);
    test({{'d','b','b'},{'c','a','a'},{'b','a','c'},{'c','c','c'},{'d','d','a'}}, false);

    return 0;
}
