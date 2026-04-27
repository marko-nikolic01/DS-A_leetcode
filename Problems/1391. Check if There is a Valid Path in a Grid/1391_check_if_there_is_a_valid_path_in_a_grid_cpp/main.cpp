#include <iostream>
#include <vector>

using namespace std;

bool hasValidPath(vector<vector<int>>& grid) {
    short m = grid.size();
    short n = grid[0].size() - 1;
    if(--m < 1 && n < 1) {
        return true;
    }

    vector<vector<tuple<bool, bool, bool, bool>>> transitions = {
        {{false, true, false, true}, {false, false, false, false}, {false, true, false, false}, {false, false, false, true}, {false, true, false, false}, {false, false, false, true}},
        {{false, false, false, false}, {true, false, true, false}, {true, false, false, false}, {true, false, false, false}, {false, false, true, false}, {false, false, true, false}},
        {{false, false, false, true}, {false, false, true, false}, {false, false, false, true}, {false, false, false, true}, {false, false, true, false}, {false, false, true, true}},
        {{false, true, false, false}, {false, false, true, false}, {false, true, false, false}, {false, false, false, false}, {false, true, true, false}, {false, false, true, false}},
        {{false, false, false, true}, {true, false, false, false}, {true, false, false, false}, {true, false, false, true}, {false, false, false, true}, {false, false, false, false}},
        {{false, true, false, false}, {true, false, false, false}, {true, true, false, false}, {true, false, false, false}, {false, true, false, false}, {false, false, false, false}}
    };
    vector<pair<short, short>> traversal;
    short x;
    short y;

    traversal.push_back({0, 0});
    grid[0][0] = -(--grid[0][0]);

    while(!traversal.empty()) {
        x = traversal.back().first;
        y = traversal.back().second;
        traversal.pop_back();

        if(x > 0 && grid[x - 1][y] > 0 && get<0>(transitions[-grid[x][y]][grid[x - 1][y] - 1])) {
            traversal.push_back({x - 1, y});
            grid[x - 1][y] = -(--grid[x - 1][y]);
        }

        if(x < m && grid[x + 1][y] > 0 && get<2>(transitions[-grid[x][y]][grid[x + 1][y] - 1])) {
            if(x + 1 == m && y == n) {
                return true;
            }

            traversal.push_back({x + 1, y});
            grid[x + 1][y] = -(--grid[x + 1][y]);
        }

        if(y > 0 && grid[x][y - 1] > 0 && get<3>(transitions[-grid[x][y]][grid[x][y - 1] - 1])) {
            traversal.push_back({x, y - 1});
            grid[x][y - 1] = -(--grid[x][y - 1]);
        }

        if(y < n && grid[x][y + 1] > 0 && get<1>(transitions[-grid[x][y]][grid[x][y + 1] - 1])) {
            if(x == m && y + 1 == n) {
                return true;
            }

            traversal.push_back({x, y + 1});
            grid[x][y + 1] = -(--grid[x][y + 1]);
        }
    }

    return false;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> grid, bool expected) {
    cout << "Streets:" << endl;
    printMatrix(grid);

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (hasValidPath(grid) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test({{2, 4, 3}, {6, 5, 2}}, true);
    test({{1, 2, 1}, {1, 2, 1}}, false);
    test({{1, 1, 2}}, false);
    test({{1}}, true);
    test({{1, 1, 1}}, true);

    return 0;
}
