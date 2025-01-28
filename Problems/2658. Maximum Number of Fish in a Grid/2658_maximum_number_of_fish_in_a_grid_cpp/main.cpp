#include <iostream>
#include <vector>

using namespace std;

int findMaxFish(vector<vector<int>>& grid) {
    short m = grid.size();
    short n = grid[0].size();

    short fish = 0;
    short currentFish;

    vector<short> water;
    short x;
    short y;

    for(short i = 0; i < m; ++i) {
        for(short j = 0; j < n; ++j) {
            if(grid[i][j] > 0) {
                currentFish = 0;

                water.push_back(i * n + j);

                while(!water.empty()) {
                    x = water.back();
                    y = x % n;
                    x /= n;

                    water.pop_back();

                    currentFish += grid[x][y];
                    grid[x][y] = 0;

                    if(x > 0 && grid[x - 1][y] > 0) {
                        water.push_back((x - 1) * n + y);
                    }

                    if(x + 1 < m && grid[x + 1][y] > 0) {
                        water.push_back((x + 1) * n + y);
                    }

                    if(y > 0 && grid[x][y - 1] > 0) {
                        water.push_back(x * n + y - 1);
                    }

                    if(++y < n && grid[x][y] > 0) {
                        water.push_back(x * n + y);
                    }
                }

                if(currentFish > fish) {
                    fish = currentFish;
                }
            }
        }
    }

    return fish;
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
    cout << "Grid:" << endl;
    printMatrix(grid);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << findMaxFish(grid) << endl;

    cout << endl;
}

int main() {
    test({{0, 2, 1, 0}, {4, 0, 0, 3}, {1, 0, 0, 4}, {0, 3, 2, 0}}, 7);
    test({{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 1}}, 1);
    test({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, 0);
    test({{0, 10, 0}, {0, 10, 0}, {0, 10, 0}}, 30);
    test({{10, 10, 10}, {10, 0, 10}, {10, 10, 10}}, 80);
    test({{1, 2}, {3, 4}}, 10);

    return 0;
}
