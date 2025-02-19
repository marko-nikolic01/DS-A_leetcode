#include <iostream>
#include <vector>

using namespace std;

void longestIncreasingPath(vector<vector<int>>& matrix, vector<vector<int>>& paths, short& m, short& n, short x, short y) {
    int path = 0;

    if(x > 0 && matrix[x - 1][y] > matrix[x][y]) {
        if(paths[x - 1][y] < 1) {
            longestIncreasingPath(matrix, paths, m, n, x - 1, y);
        }

        if(paths[x - 1][y] > path) {
            path = paths[x - 1][y];
        }
    }

    if(x < m && matrix[x + 1][y] > matrix[x][y]) {
        if(paths[x + 1][y] < 1) {
            longestIncreasingPath(matrix, paths, m, n, x + 1, y);
        }

        if(paths[x + 1][y] > path) {
            path = paths[x + 1][y];
        }
    }

    if(y > 0 && matrix[x][y - 1] > matrix[x][y]) {
        if(paths[x][y - 1] < 1) {
            longestIncreasingPath(matrix, paths, m, n, x, y - 1);
        }

        if(paths[x][y - 1] > path) {
            path = paths[x][y - 1];
        }
    }

    if(y < n && matrix[x][y + 1] > matrix[x][y]) {
        if(paths[x][y + 1] < 1) {
            longestIncreasingPath(matrix, paths, m, n, x, y + 1);
        }

        if(paths[x][y + 1] > path) {
            path = paths[x][y + 1];
        }
    }

    paths[x][y] = ++path;
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    short m = matrix.size();
    short n = matrix[0].size();
    vector<vector<int>> paths(m--, vector<int>(n--, 0));

    int path = 1;

    short y;
    for(short x = m; x > -1; --x) {
        for(y = n; y > -1; --y) {
            if(paths[x][y] < 1) {
                longestIncreasingPath(matrix, paths, m, n, x, y);

                if(paths[x][y] > path) {
                    path = paths[x][y];
                }
            }
        }
    }

    return path;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> matrix, int expected) {
    cout << "Matrix:" << endl;
    printMatrix(matrix);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << longestIncreasingPath(matrix) << endl;

    cout << endl;
}

int main() {
    test({{9,9,4}, {6,6,8}, {2,1,1}}, 4);
    test({{3,4,5}, {3,2,6}, {2,2,1}}, 4);
    test({{1}}, 1);
    test({{1,2,3}, {6,5,4}, {7,8,9}}, 9);
    test({{7,6,1}, {2,3,8}, {5,4,9}}, 4);

    return 0;
}
