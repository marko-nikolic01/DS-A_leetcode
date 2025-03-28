#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
    short n = queries.size();
    vector<pair<int, short>> queriesSorted(n);

    short i = 0;
    for(i; i < n; ++i) {
        queriesSorted[i].first = queries[i];
        queriesSorted[i].second = i;
    }

    sort(queriesSorted.begin(), queriesSorted.end(), [](const auto& a, const auto& b) {
        return a.first > b.first;
    });

    priority_queue<pair<int, pair<short, short>>, vector<pair<int, pair<short, short>>>, greater<pair<int, pair<short, short>>>> traversal;
    traversal.push({grid[0][0], {0, 0}});
    grid[0][0] = -grid[0][0];

    int points = 0;
    short x;
    short y;

    --i;
    short m = grid.size() - 1;
    n = grid[0].size() - 1;
    while(i > -1 && !traversal.empty()) {
        x = traversal.top().second.first;
        y = traversal.top().second.second;

        if(queriesSorted[i].first > -grid[x][y]) {
            traversal.pop();
            ++points;

            if(x > 0 && grid[x - 1][y] > 0) {
                traversal.push({grid[x - 1][y], {x - 1, y}});
                grid[x - 1][y] = -grid[x - 1][y];
            }

            if(x < m && grid[x + 1][y] > 0) {
                traversal.push({grid[x + 1][y], {x + 1, y}});
                grid[x + 1][y] = -grid[x + 1][y];
            }

            if(y > 0 && grid[x][y - 1] > 0) {
                traversal.push({grid[x][y - 1], {x, y - 1}});
                grid[x][y - 1] = -grid[x][y - 1];
            }

            if(y < n && grid[x][++y] > 0) {
                traversal.push({grid[x][y], {x, y}});
                grid[x][y] = -grid[x][y];
            }
        } else {
            queries[queriesSorted[i--].second] = points;
        }
    }

    while(i > -1) {
        queries[queriesSorted[i--].second] = points;
    }

    return queries;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> grid, vector<int> queries, vector<int> expected) {
    cout << "Matrix:" << endl;
    printMatrix(grid);

    cout << "Queries: ";
    printArray(queries);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(maxPoints(grid, queries));

    cout << endl;
}

int main() {
    test({{1, 2, 3}, {2, 5, 7}, {3, 5, 1}}, {5, 6, 2}, {5, 8, 1});
    test({{5, 2, 1}, {1, 1, 2}}, {3}, {0});
    test({{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}, {2, 3, 1}, {9, 9, 0});
    test({{10, 20, 30}, {20, 50, 70}, {30, 60, 90}}, {15, 25, 10, 60}, {1, 3, 0, 6});
    test({{1, 1}, {1, 2}}, {1, 2, 3}, {0, 3, 4});

    return 0;
}
