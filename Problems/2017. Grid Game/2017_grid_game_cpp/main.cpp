#include <iostream>
#include <vector>

using namespace std;

long long gridGame(vector<vector<int>>& grid) {
    long row2Sum = 0;

    int n = grid[0].size() - 1;
    for(int i = 0; i < n; ++i) {
        row2Sum += grid[1][i];
    }

    long row1Sum = 0;
    long points = row2Sum;

    for(n; n > 0; --n) {
        row1Sum += grid[0][n];
        row2Sum -= grid[1][n - 1];

        if(row1Sum > row2Sum) {
            if(row1Sum < points) {
                points = row1Sum;
            }
        } else if(row2Sum < points) {
            points = row2Sum;
        }
    }

    return points;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> grid, long long expected) {
    cout << "Matrix: ";
    printMatrix(grid);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << gridGame(grid) << endl;

    cout << endl;
}

int main() {
    test({{2, 5, 4}, {1, 5, 1}}, 4);
    test({{3, 3, 1}, {8, 5, 2}}, 4);
    test({{1, 3, 1, 15}, {1, 3, 3, 1}}, 7);
    test({{1}, {2}}, 0);
    test({{10, 20, 30, 40}, {5, 10, 15, 20}}, 30);
    test({{100, 200, 300}, {400, 500, 600}}, 400);

    return 0;
}
