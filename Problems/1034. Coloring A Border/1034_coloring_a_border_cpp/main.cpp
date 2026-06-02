#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
    vector<pair<short, short>> traversal;
    short originalColor = grid[row][col];

    traversal.push_back({row, col});
    grid[row][col] = -originalColor;

    short m = grid.size() - 1;
    short n = grid[0].size() - 1;
    while(!traversal.empty()) {
        row = traversal.back().first;
        col = traversal.back().second;
        traversal.pop_back();

        if(row > 0 && grid[row - 1][col] == originalColor) {
            traversal.push_back({row - 1, col});
            grid[row - 1][col] = -originalColor;
        }

        if(row < m && grid[row + 1][col] == originalColor) {
            traversal.push_back({row + 1, col});
            grid[row + 1][col] = -originalColor;
        }

        if(col > 0 && grid[row][col - 1] == originalColor) {
            traversal.push_back({row, col - 1});
            grid[row][col - 1] = -originalColor;
        }

        if(col < n && grid[row][col + 1] == originalColor) {
            traversal.push_back({row, col + 1});
            grid[row][col + 1] = -originalColor;
        }
    }

    for(row = m; row > -1; --row) {
        for(col = n; col > -1; --col) {
            if(grid[row][col] < 0 && row > 0 && row < m && col > 0 && col < n && abs(grid[row - 1][col]) == originalColor && abs(grid[row + 1][col]) == originalColor && abs(grid[row][col - 1]) == originalColor && abs(grid[row][col + 1]) == originalColor) {
                grid[row][col] = originalColor;
            }
        }
    }

    for(row = m; row > -1; --row) {
        for(col = n; col > -1; --col) {
            if(grid[row][col] < 0) {
                grid[row][col] = color;
            }
        }
    }

    return grid;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> grid, int row, int col, int color, vector<vector<int>> expected) {
    cout << "Matrix:" << endl;
    printMatrix(grid);

    cout << "Row: " << row << endl;

    cout << "Column: " << col << endl;

    cout << "Color: " << color << endl;

    cout << "Expected:" << endl;
    printMatrix(expected);

    cout << "Result:" << endl;
    printMatrix(colorBorder(grid, row, col , color));

    cout << endl;
}

int main() {
    test({{1, 1}, {1, 2}}, 0, 0, 3, {{3, 3}, {3, 2}});
    test({{1, 2, 2}, {2, 3, 2}}, 0, 1, 3, {{1, 3, 3}, {2, 3, 3}});
    test({{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}, 1, 1, 2, {{2, 2, 2}, {2, 1, 2}, {2, 2, 2}});
    test({{1}}, 0, 0, 5, {{5}});
    test({{1, 1, 1}, {1, 2, 1}, {1, 1, 1}}, 0, 0, 3, {{3, 3, 3}, {3, 2, 3}, {3, 3, 3}});

    return 0;
}
