#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minOperations(vector<vector<int>>& grid, int x) {
    int m = grid.size();
    int n = grid[0].size();

    vector<short> numbers(m * n);
    vector<int> operations(m * n--);

    int minOperations = 0;

    int i;
    int j;
    for(i = --m; i > -1; --i) {
        for(j = n; j > -1; --j) {
            numbers[minOperations++] = grid[i][j];
        }
    }

    sort(numbers.begin(), numbers.end());
    operations[0] = 0;

    n = ++n * ++m;
    for(i = 1; i < n; ++i) {
        if((numbers[i] - numbers[0]) % x > 0) {
            return -1;
        } else if(numbers[i] == numbers[i - 1]) {
            operations[i] = operations[i - 1];
        } else {
            operations[i] = operations[i - 1] + i * (numbers[i] - numbers[i - 1]) / x;
        }
    }

    minOperations = operations[--n];
    i = 0;
    j = 1;

    for(--n; n > -1; --n) {
        if(numbers[n] < numbers[n + 1]) {
            i += j * (numbers[n + 1] - numbers[n]) / x;

            if(i + operations[n] < minOperations) {
                minOperations = i + operations[n];
            }
        }

        ++j;
    }

    return minOperations;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> grid, int x, int expected) {
    cout << "Matrix:" << endl;
    printMatrix(grid);

    cout << "x: " << x << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minOperations(grid, x) << endl;

    cout << endl;
}

int main() {
    test({{2, 4}, {6, 8}}, 2, 4);
    test({{1, 5}, {2, 3}}, 1, 5);
    test({{1, 2}, {3, 4}}, 2, -1);
    test({{5, 5}, {5, 5}}, 1, 0);
    test({{10, 20, 30}, {40, 50, 60}}, 10, 9);
    test({{5, 15}, {25, 35}}, 10, 4);

    return 0;
}
