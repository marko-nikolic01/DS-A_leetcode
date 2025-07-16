#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int minimumObstacles(vector<vector<int>>& grid) {
    auto cmp = [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
        return get<2>(a) > get<2>(b);
    };
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, decltype(cmp)> traversal(cmp);
    traversal.push({0, 0, 0});
    grid[0][0] = -1;

    int x;
    int y;
    int obstacles;

    int m = grid.size() - 1;
    int n = grid[0].size() - 1;
    while(true) {
        x = get<0>(traversal.top());
        y = get<1>(traversal.top());
        obstacles = get<2>(traversal.top());
        traversal.pop();

        if(x > 0 && grid[x - 1][y] > -1) {
            traversal.push({x - 1, y, grid[x - 1][y] > 0 ? obstacles + 1 : obstacles});
            grid[x - 1][y] = -1;
        }

        if(x < m && grid[x + 1][y] > -1) {
            if(x + 1 == m && y == n) {
                return obstacles;
            }

            traversal.push({x + 1, y, grid[x + 1][y] > 0 ? obstacles + 1 : obstacles});
            grid[x + 1][y] = -1;
        }

        if(y > 0 && grid[x][y - 1] > -1) {
            traversal.push({x, y - 1, grid[x][y - 1] > 0 ? obstacles + 1 : obstacles});
            grid[x][y - 1] = -1;
        }

        if(y < n && grid[x][y + 1] > -1) {
            if(x == m && y + 1 == n) {
                return obstacles;
            }

            traversal.push({x, y + 1, grid[x][y + 1] > 0 ? obstacles + 1 : obstacles});
            grid[x][y + 1] = -1;
        }
    }

    return 0;
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

    cout << "Result: " << minimumObstacles(grid) << endl;

    cout << endl;
}

int main() {
    test({{0, 1, 1}, {1, 1, 0}, {1, 1, 0}}, 2);
    test({{0, 1, 0, 0, 0}, {0, 1, 0, 1, 0}, {0, 0, 0, 1, 0}}, 0);
    test({{0, 1, 1}, {0, 1, 1}, {0, 0, 0}}, 0);
    test({{0, 1, 1}, {1, 0, 1}, {1, 1, 0}}, 2);
    test({{0, 1, 1, 1}, {0, 0, 0, 1}, {1, 1, 0, 0}}, 0);

    return 0;
}
