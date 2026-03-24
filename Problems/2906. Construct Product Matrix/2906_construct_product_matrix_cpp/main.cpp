#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> products(n, vector<int>(m--));
    long suffixPrefix = 1;

    int i;
    int j;
    for(i = --n; i > -1; --i) {
        for(j = m; j > -1; --j) {
            products[i][j] = suffixPrefix;
            suffixPrefix = suffixPrefix * grid[i][j] % 12345;
        }
    }

    suffixPrefix = 1;

    for(i = 0; i <= n; ++i) {
        for(j = 0; j <= m; ++j) {
            products[i][j] = products[i][j] * suffixPrefix % 12345;
            suffixPrefix = suffixPrefix * grid[i][j] % 12345;
        }
    }

    return products;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> grid, vector<vector<int>> expected) {
    cout << "Matrix:" << endl;
    printMatrix(grid);

    cout << "Expected:" << endl;
    printMatrix(expected);

    cout << "Result:" << endl;
    printMatrix(constructProductMatrix(grid));

    cout << endl;
}

int main() {
    test({{1, 2}, {3, 4}}, {{24, 12}, {8, 6}});
    test({{12345}, {2}, {1}}, {{2}, {0}, {0}});
    test({{1, 1}, {1, 1}}, {{1, 1}, {1, 1}});
    test({{2, 3, 4}}, {{12, 8, 6}});
    test({{1, 2, 3}, {4, 5, 6}}, {{720, 360, 240}, {180, 144, 120}});

    return 0;
}
