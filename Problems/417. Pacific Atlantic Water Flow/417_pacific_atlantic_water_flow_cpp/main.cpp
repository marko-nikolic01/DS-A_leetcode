#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    short m = heights.size();
    short n = heights[0].size();
    vector<vector<bool>> pacific(m, vector<bool>(n, false));
    vector<vector<bool>> atlantic(m--, vector<bool>(n--, false));
    vector<vector<int>> both;

    vector<pair<short, short>> traversal;
    short x;
    short y;

    for(x = m; x > -1; --x) {
        pacific[x][0] = true;
        traversal.push_back({x, 0});
    }

    for(y = n; y > 0; --y) {
        pacific[0][y] = true;
        traversal.push_back({0, y});
    }

    while(!traversal.empty()) {
        x = traversal.back().first;
        y = traversal.back().second;
        traversal.pop_back();

        if(x > 0 && !pacific[x - 1][y] && heights[x - 1][y] >= heights[x][y]) {
            pacific[x - 1][y] = true;
            traversal.push_back({x - 1, y});
        }

        if(x < m && !pacific[x + 1][y] && heights[x + 1][y] >= heights[x][y]) {
            pacific[x + 1][y] = true;
            traversal.push_back({x + 1, y});
        }

        if(y > 0 && !pacific[x][y - 1] && heights[x][y - 1] >= heights[x][y]) {
            pacific[x][y - 1] = true;
            traversal.push_back({x, y - 1});
        }

        if(y < n && !pacific[x][y + 1] && heights[x][y + 1] >= heights[x][y]) {
            pacific[x][y + 1] = true;
            traversal.push_back({x, y + 1});
        }
    }

    for(x = m; x > -1; --x) {
        atlantic[x][n] = true;
        traversal.push_back({x, n});
    }

    for(y = n - 1; y > -1; --y) {
        atlantic[m][y] = true;
        traversal.push_back({m, y});
    }

    while(!traversal.empty()) {
        x = traversal.back().first;
        y = traversal.back().second;
        traversal.pop_back();

        if(pacific[x][y]) {
            both.push_back({x, y});
        }

        if(x > 0 && !atlantic[x - 1][y] && heights[x - 1][y] >= heights[x][y]) {
            atlantic[x - 1][y] = true;
            traversal.push_back({x - 1, y});
        }

        if(x < m && !atlantic[x + 1][y] && heights[x + 1][y] >= heights[x][y]) {
            atlantic[x + 1][y] = true;
            traversal.push_back({x + 1, y});
        }

        if(y > 0 && !atlantic[x][y - 1] && heights[x][y - 1] >= heights[x][y]) {
            atlantic[x][y - 1] = true;
            traversal.push_back({x, y - 1});
        }

        if(y < n && !atlantic[x][y + 1] && heights[x][y + 1] >= heights[x][y]) {
            atlantic[x][y + 1] = true;
            traversal.push_back({x, y + 1});
        }
    }

    return both;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> heights, vector<vector<int>> expected) {
    cout << "Island: ";
    printMatrix(heights);

    cout << "Expected: ";
    for(vector<int> e : expected) {
        cout << "[" << e[0] << " " << e[1] << "] ";
    }
    cout << endl;

    cout << "Result: ";
    for(vector<int> result : pacificAtlantic(heights)) {
        cout << "[" << result[0] << " " << result[1] << "] ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    test({{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}}, {{4, 0}, {3, 0}, {3, 1}, {2, 2}, {0, 4}, {1, 4}, {1, 3}});
    test({{1}}, {{0, 0}});
    test({{5, 5, 5, 5}, {4, 4, 4, 4}, {5, 5, 5, 5}}, {{2, 0}, {2, 1}, {2, 2}, {0, 3}, {0, 2}, {0, 1}, {0, 0}, {1, 3}, {1, 2}, {1, 1}, {1, 0}, {2, 3}});
    test({{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}, {{2, 0}, {1, 0}, {1, 1}, {0, 1}, {0, 0}, {2, 1}, {0, 2}, {1, 2}, {2, 2}});
    test({{10, 9, 8}, {9, 8, 7}, {8, 7, 6}}, {{2, 0}, {1, 0}, {0, 0}, {0, 1}, {0, 2}});

    return 0;
}
