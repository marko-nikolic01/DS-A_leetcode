#include <iostream>
#include <vector>
#include <climits>

using namespace std;

long long maxMatrixSum(vector<vector<int>>& matrix) {
    long sum = 0;
    int minimum = INT_MAX;
    bool negative = false;

    short j;
    short n = matrix[0].size() - 1;
    for(short i = matrix.size() - 1; i > -1; --i) {
        for(j = n; j > -1; --j) {
            if(matrix[i][j] < 0) {
                matrix[i][j] = -matrix[i][j];
                negative = !negative;
            }

            sum += matrix[i][j];

            if(matrix[i][j] < minimum) {
                minimum = matrix[i][j];
            }
        }
    }

    return negative ? sum - (minimum << 1) : sum;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> matrix, long long expected) {
    cout << "Matrix:" << endl;
    printMatrix(matrix);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxMatrixSum(matrix) << endl;

    cout << endl;
}

int main() {
    test({{1, -1}, {-1, 1}}, 4);
    test({{1, 2, 3}, {-1, -2, -3}, {1, 2, 3}}, 16);
    test({{1, 2}, {3, 4}}, 10);
    test({{-1, -2}, {-3, -4}}, 10);
    test({{-1, 2, -3}, {4, -5, 6}, {-7, 8, -9}}, 43);

    return 0;
}

