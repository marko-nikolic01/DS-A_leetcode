#include <iostream>
#include <vector>

using namespace std;

int countNegatives(vector<vector<int>>& grid) {
    short negatives = 0;
    short left;
    short right;
    short middle;

    short m = grid.size();
    short n = grid[0].size();
    short nCurrent = n - 1;
    for(short i = 0; i < m; ++i) {
        left = 0;
        right = nCurrent;

        while(left <= right) {
            middle = (left + right) >> 1;

            if(grid[i][middle] > -1) {
                left = ++middle;
            } else if(middle < 1 || grid[i][middle - 1] > -1) {
                negatives += n - middle;
                nCurrent = middle;
                break;
            } else {
                right = --middle;
            }
        }
    }

    return negatives;
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

    cout << "Result: " << countNegatives(grid) << endl;

    cout << endl;
}

int main() {
    test({{4, 3, 2, -1}, {3, 2, 1, -1}, {1, 1, -1, -2}, {-1, -1, -2, -3}}, 8);
    test({{3, 2}, {1, 0}}, 0);
    test({{-1}}, 1);
    test({{1}}, 0);
    test({{5, 4, 3}, {2, 1, 0}}, 0);
    test({{10, 5, 0, -1, -2}, {8, 3, -1, -2, -3}, {6, 1, -2, -3, -4}}, 8);
    return 0;
}
