#include <iostream>
#include <vector>

using namespace std;

bool largestMagicSquare(vector<vector<int>>& grid, short& x, short& y, short& length) {
    int sum = 0;
    int currentSum = 0;

    short i;
    short j = y;
    short xEnd = x + length;
    short yEnd = y + length;
    for(i = x; i < xEnd; ++i) {
        sum += grid[i][j++];
    }

    j = yEnd - 1;
    for(i = x; i < xEnd; ++i) {
        currentSum += grid[i][j--];
    }

    if(currentSum != sum) {
        return false;
    }

    for(i = x; i < xEnd; ++i) {
        currentSum = 0;

        for(j = y; j < yEnd; ++j) {
            currentSum += grid[i][j];
        }

        if(currentSum != sum) {
            return false;
        }
    }

    for(j = y; j < yEnd; ++j) {
        currentSum = 0;

        for(i = x; i < xEnd; ++i) {
            currentSum += grid[i][j];
        }

        if(currentSum != sum) {
            return false;
        }
    }

    return true;
}

int largestMagicSquare(vector<vector<int>>& grid) {
    short m = grid.size();
    short n = grid[0].size();
    short length = min(m, n);

    short i;
    short j;
    while(length > 1) {
        for(i = m - length; i > -1; --i) {
            for(j = n - length; j > -1; --j) {
                if(largestMagicSquare(grid, i, j, length)) {
                    return length;
                }
            }
        }

        --length;
    }

    return length;
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

    cout << "Result: " << largestMagicSquare(grid) << endl;

    cout << endl;
}

int main() {
    test({{7, 1, 4, 5, 6}, {2, 5, 1, 6, 4}, {1, 5, 4, 3, 2}, {1, 2, 7, 3, 4}}, 3);
    test({{5, 1, 3, 1}, {9, 3, 3, 1}, {1, 3, 3, 8}}, 2);
    test({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, 1);
    test({{2, 7, 6}, {9, 5, 1}, {4, 3, 8}}, 3);
    test({{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}}, 4);

    return 0;
}
