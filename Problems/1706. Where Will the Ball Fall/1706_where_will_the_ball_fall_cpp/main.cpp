#include <iostream>
#include <vector>

using namespace std;

vector<int> findBall(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<int> dropLocations(n);

    for(int i = 0; i < n; ++i) {
        int x = 0;
        int y = i;

        while(x < m) {
            if(grid[x][y] == 1) {
                if(y < n - 1 && grid[x][y + 1] == 1) {
                    x++;
                    y++;
                } else {
                    break;
                }
            } else {
               if(y > 0 && grid[x][y - 1] == -1) {
                    x++;
                    y--;
                } else {
                    break;
                }
            }
        }

        dropLocations[i] = x < m ? -1 : y;
    }

    return dropLocations;
}

void printGrid(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void runTestCase(vector<vector<int>>& grid, vector<int>& expected) {
    cout << "Box:" << endl;
    printGrid(grid);

    vector<int> result = findBall(grid);

    cout << "Expected: ";
    for (int ball : expected) {
        cout << ball << " ";
    }
    cout << endl;

    cout << "Result:   ";
    for (int ball : result) {
        cout << ball << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    vector<vector<int>> grid1 = {
        {1, 1, 1, -1, -1},
        {1, 1, 1, -1, -1},
        {1, 1, 1, 1, -1},
        {-1, -1, -1, -1, -1},
        {1, 1, 1, 1, 1}
    };
    vector<int> expected1 = {3, -1, -1, -1, -1};
    runTestCase(grid1, expected1);

    vector<vector<int>> grid2 = {
        {1, 1, 1, -1, -1},
        {1, 1, 1, -1, -1},
        {1, 1, 1, 1, -1},
        {1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1}
    };
    vector<int> expected2 = {1, -1, -1, -1, -1};
    runTestCase(grid2, expected2);

    vector<vector<int>> grid3 = {
        {-1, 1},
        {1, -1},
    };
    vector<int> expected3 = {-1, -1};
    runTestCase(grid3, expected3);

    return 0;
}
