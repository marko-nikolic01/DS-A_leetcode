#include <iostream>
#include <vector>

using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    short n = grid.size();
    int nSquared = (int)n * n;

    int firstN2Sum = nSquared * (nSquared + 1) / 2;
    long firstN2SquaredSum = (long)firstN2Sum * (2 * nSquared + 1) / 3;

    int sum = 0;
    long sumSquared = 0;

    short j;
    for(short i = --n; i > -1; --i) {
        for(j = n; j > -1; --j) {
            sum += grid[i][j];
            sumSquared += grid[i][j] * grid[i][j];
        }
    }

    firstN2Sum = sum - firstN2Sum;
    nSquared = (sumSquared - firstN2SquaredSum) / firstN2Sum;

    return {(nSquared + firstN2Sum) / 2, (nSquared - firstN2Sum) / 2};
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

void test(vector<vector<int>> grid, vector<int> expected) {
    cout << "Matrix:" << endl;
    printMatrix(grid);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(findMissingAndRepeatedValues(grid));

    cout << endl;
}

int main() {
    test({{1, 3}, {2, 2}}, {2, 4});
    test({{9, 1, 7}, {8, 9, 2}, {3, 4, 6}}, {9, 5});
    test({{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 11}, {13, 14, 15, 16}}, {11, 12});
    test({{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 16, 18, 19, 20}, {21, 22, 23, 24, 25}}, {16, 17});
    test({{1, 2, 3, 4, 5, 6}, {7, 8, 9, 10, 11, 12}, {13, 14, 15, 16, 17, 18}, {19, 20, 21, 22, 23, 24}, {25, 26, 27, 27, 29, 30}, {31, 32, 33, 34, 35, 36}}, {27, 28});

    return 0;
}
