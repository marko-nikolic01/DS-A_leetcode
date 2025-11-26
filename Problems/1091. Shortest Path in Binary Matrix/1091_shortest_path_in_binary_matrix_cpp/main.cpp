#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    if(grid[0][0] < 1) {
        short n = grid.size();
        if(n < 2) {
            return 1;
        }

        queue<pair<short, short>> traversal;
        vector<pair<short, short>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        short x;
        short y;
        short path = 1;

        traversal.push({0, 0});
        ++grid[0][0];

        short i;
        short j;
        while(!traversal.empty()) {
            ++path;

            for(i = traversal.size(); i > 0; --i) {
                x = traversal.front().first;
                y = traversal.front().second;
                traversal.pop();

                for(j = 0; j < 8; ++j) {
                    x += directions[j].first;
                    y += directions[j].second;

                    if(x > -1 && x < n && y > -1 && y < n && grid[x][y] < 1) {
                        if(x == n - 1 && x == y) {
                            return path;
                        }

                        traversal.push({x, y});
                        ++grid[x][y];
                    }

                    x -= directions[j].first;
                    y -= directions[j].second;
                }
            }
        }
    }

    return -1;
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

    cout << "Result: " << shortestPathBinaryMatrix(grid) << endl;

    cout << endl;
}

int main() {
    test({{0, 1}, {1, 0}}, 2);
    test({{0, 0, 0}, {1, 1, 0}, {1, 1, 0}}, 4);
    test({{1, 0, 0}, {1, 1, 0}, {1, 1, 0}}, -1);
    test({{1, 1}, {1, 0}}, -1);
    test({{0}}, 1);
    test({{1}}, -1);
    test({{0, 1, 1}, {1, 0, 1}, {1, 1, 0}}, 3);

    return 0;
}
