#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int swimInWater(vector<vector<int>>& grid) {
    short n = grid.size();
    if(--n < 1) {
        return 0;
    }

    auto cmp = [](const tuple<short, short, short>& a, const tuple<short, short, short>& b) {
        return get<0>(a) > get<0>(b);
    };
    priority_queue<tuple<short, short, short>, vector<tuple<short, short, short>>, decltype(cmp)> traversal(cmp);
    traversal.push({grid[0][0], 0, 0});

    short time = 0;
    short currentTime;
    short x;
    short y;

    while(true) {
        currentTime = get<0>(traversal.top());
        x = get<1>(traversal.top());
        y = get<2>(traversal.top());
        traversal.pop();

        grid[x][y] = -1;

        if(currentTime > time) {
            time = currentTime;
        }

        if(x > 0 && grid[x - 1][y] > -1) {
            traversal.push({grid[x - 1][y], x - 1, y});
        }

        if(x < n && grid[x + 1][y] > -1) {
            if(x + 1 == n && y == n) {
                if(grid[x + 1][y] > time) {
                    time = grid[x + 1][y];
                }
                break;
            }

            traversal.push({grid[x + 1][y], x + 1, y});
        }

        if(y > 0 && grid[x][y - 1] > -1) {
            traversal.push({grid[x][y - 1], x, y - 1});
        }

        if(y < n && grid[x][++y] > -1) {
            if(x == n && y == n) {
                if(grid[x][y] > time) {
                    time = grid[x][y];
                }
                break;
            }

            traversal.push({grid[x][y], x, y});
        }
    }

    return time;
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
    cout << "Elevation:" << endl;
    printMatrix(grid);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << swimInWater(grid) << endl;

    cout << endl;
}

int main() {
    test({{0}}, 0);
    test({{0, 2}, {1, 3}}, 3);
    test({{0, 1, 2}, {3, 4, 5}, {6, 7, 8}}, 8);
    test({{0, 100, 2}, {3, 1, 4}, {6, 5, 8}}, 8);
    test({{0, 1, 2, 3, 4}, {24, 23, 22, 21, 5}, {12, 13, 14, 15, 16}, {11, 17, 18, 19, 20}, {10, 9, 8, 7, 6}}, 16);

    return 0;
}
