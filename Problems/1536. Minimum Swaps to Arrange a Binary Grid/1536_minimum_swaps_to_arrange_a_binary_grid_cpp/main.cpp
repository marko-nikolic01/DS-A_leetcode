#include <iostream>
#include <vector>

using namespace std;

int minSwaps(vector<vector<int>>& grid) {
    short swaps = 0;
    short n = grid.size();
    vector<short> pos(n, -1);
    short temp;

    short i;
    short j;
    for(i = 0; i < n; ++i) {
        for(j = n - 1; j > -1; --j) {
            if(grid[i][j] > 0) {
                pos[i] = j;

                break;
            }
        }
    }

    short k;
    for(i = 0; i < n; ++i) {
        k = -1;
        for(j = i; j < n; ++j) {
            if(pos[j] <= i) {
                swaps += j - i;
                k = j;

                break;
            }
        }

        if(~k != 0) {
            for(j = k; j > i; --j) {
                temp = pos[j];
                pos[j] = pos[j - 1];
                pos[j - 1] = temp;
            }
        } else {
            return -1;
        }
    }

    return swaps;
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

    cout << "Result: " << minSwaps(grid) << endl;

    cout << endl;
}

int main() {
    test({{0, 0, 1}, {1, 1, 0}, {1, 0, 0}}, 3);
    test({{0, 1, 1, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}, {0, 1, 1, 0}}, -1);
    test({{1, 0, 0}, {1, 1, 0}, {1, 1, 1}}, 0);
    test({{0}}, 0);
    test({{0, 0, 0, 0}, {1, 0, 0, 0}, {1, 1, 0, 0}, {1, 1, 1, 0}}, 0);

    return 0;
}
