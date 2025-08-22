#include <iostream>
#include <vector>

using namespace std;

int minimumArea(vector<vector<int>>& grid) {
    short m = grid.size();
    short n = grid[0].size();

    short x1 = m;
    short x2 = -1;
    short y1 = n--;
    short y2 = -1;

    short i;
    for(--m; m > -1; --m) {
        for(i = n; i > -1; --i) {
            if(grid[m][i] > 0) {
                if(m < x1) {
                    x1 = m;
                }

                if(m > x2) {
                    x2 = m;
                }

                if(i < y1) {
                    y1 = i;
                }

                if(i > y2) {
                    y2 = i;
                }
            }
        }
    }

    return (++x2 - x1) * (++y2 - y1);
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

    cout << "Result: " << minimumArea(grid) << endl;

    cout << endl;
}

int main() {
    test({{0, 1, 0}, {1, 0, 1}}, 6);
    test({{1, 0}, {0, 0}}, 1);
    test({{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}, 1);
    test({{1, 1, 0, 0}, {0, 1, 1, 1}, {0, 0, 0, 1}}, 12);
    test({{0, 0, 1}, {0, 0, 1}, {1, 1, 1}}, 9);

    return 0;
}
