#include <iostream>
#include <vector>

using namespace std;

int countIslands(vector<vector<int>>& grid, int k) {
    int islands = 0;
    long islandValue;

    vector<pair<short, short>> traversal;
    short x;
    short y;

    short j;
    short m = grid.size();
    short n = grid[0].size() - 1;
    for(short i = --m; i > -1; --i) {
        for(j = n; j > -1; --j) {
            if(grid[i][j] > 0) {
                islandValue = 0;
                traversal.push_back({i, j});

                while(!traversal.empty()) {
                    x = traversal.back().first;
                    y = traversal.back().second;
                    traversal.pop_back();

                    islandValue += grid[x][y];
                    grid[x][y] = 0;

                    if(x > 0 && grid[x - 1][y] > 0) {
                        traversal.push_back({x - 1, y});
                    }

                    if(x < m && grid[x + 1][y] > 0) {
                        traversal.push_back({x + 1, y});
                    }

                    if(y > 0 && grid[x][y - 1] > 0) {
                        traversal.push_back({x, y - 1});
                    }

                    if(y < n && grid[x][y + 1] > 0) {
                        traversal.push_back({x, ++y});
                    }
                }

                if(islandValue % k < 1) {
                    ++islands;
                }
            }
        }
    }

    return islands;
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
    cout << "Islands:" << endl;
    printMatrix(grid);

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countIslands(grid, k) << endl;

    cout << endl;
}

int main() {
    test({{0, 2, 1, 0, 0}, {0, 5, 0, 0, 5}, {0, 0, 1, 0, 0}, {0, 1, 4, 7, 0}, {0, 2, 0, 0, 8}}, 5, 2);
    test({{3, 0, 3, 0}, {0, 3, 0, 3}, {3, 0, 3, 0}}, 3, 6);
    test({{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}, 3, 1);
    test({{2, 0, 2, 0}, {0, 0, 0, 0}, {2, 0, 2, 0}}, 4, 0);
    test({{5, 0, 0}, {0, 5, 0}, {0, 0, 5}}, 5, 3);

    return 0;
}
