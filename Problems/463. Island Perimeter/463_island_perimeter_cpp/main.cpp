#include <iostream>
#include <vector>

using namespace std;

int islandPerimeter(vector<vector<int>>& grid) {
    int perimiter = 0;

    int rows = grid.size();
    int columns = grid[0].size();

    bool isIsland = true;
    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < columns; ++j) {
            if(grid[i][j] == 1) {
                if(j == 0 || grid[i][j - 1] == 0) {
                    perimiter++;
                }

                if(j == columns - 1) {
                    perimiter++;
                }

                if(j < columns - 1 && grid[i][j + 1] == 0) {
                    perimiter++;
                }

                if(i == 0 || grid[i - 1][j] == 0) {
                    perimiter++;
                }

                if(i == rows - 1) {
                    perimiter++;
                }

                if(i < rows - 1 && grid[i + 1][j] == 0) {
                    perimiter++;
                }
            }
        }
    }

    return perimiter;
}

void printGrid(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>>& grid, int expected) {
    cout << "Island Grid:" << endl;
    printGrid(grid);

    int result = islandPerimeter(grid);
    cout << "Expected: " << expected << ", Result: " << result << endl;
    cout << "----------------------------------" << endl;
}

int main() {
    vector<vector<int>> grid1 = {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}
    };

    vector<vector<int>> grid2 = {
        {1}
    };

    vector<vector<int>> grid3 = {
        {1, 0},
        {1, 1}
    };

    vector<vector<int>> grid4 = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };

    vector<vector<int>> grid5 = {
        {1, 1},
        {1, 1}
    };

    test(grid1, 16);
    test(grid2, 4);
    test(grid3, 8);
    test(grid4, 4);
    test(grid5, 8);

    return 0;
}
