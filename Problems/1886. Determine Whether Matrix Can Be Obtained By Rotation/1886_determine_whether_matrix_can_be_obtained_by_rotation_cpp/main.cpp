#include <iostream>
#include <vector>

using namespace std;

bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
    bool isIdentical = true;

    short i;
    short j;
    short n = mat.size() - 1;
    for(i = 0; isIdentical && i <= n; ++i) {
        for(j = 0; isIdentical && j <= n; ++j) {
            if(mat[i][j] != target[i][j]) {
                isIdentical = false;
            }
        }
    }

    if(isIdentical) {
        return true;
    }

    isIdentical = true;


    for(i = 0; isIdentical && i <= n; ++i) {
        for(j = 0; isIdentical && j <= n; ++j) {
            if(mat[j][n - i] != target[i][j]) {
                isIdentical = false;
            }
        }
    }

    if(isIdentical) {
        return true;
    }

    isIdentical = true;


    for(i = 0; isIdentical && i <= n; ++i) {
        for(j = 0; isIdentical && j <= n; ++j) {
            if(mat[n - i][n - j] != target[i][j]) {
                isIdentical = false;
            }
        }
    }

    if(isIdentical) {
        return true;
    }

    isIdentical = true;


    for(i = 0; isIdentical && i <= n; ++i) {
        for(j = 0; isIdentical && j <= n; ++j) {
            if(mat[n - j][i] != target[i][j]) {
                isIdentical = false;
            }
        }
    }

    return isIdentical;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> mat, vector<vector<int>> target, bool expected) {
    cout << "Matrix:" << endl;
    printMatrix(mat);

    cout << "Target:" << endl;
    printMatrix(target);

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (findRotation(mat, target) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test({{0, 1}, {1, 0}}, {{0, 1}, {1, 0}}, true);
    test({{0, 1}, {1, 0}}, {{1, 0}, {0, 1}}, true);
    test({{0, 0, 0}, {0, 1, 0}, {1, 1, 1}}, {{1, 1, 1}, {0, 1, 0}, {0, 0, 0}}, true);
    test({{0, 1}, {1, 1}}, {{1, 0}, {0, 1}}, false);
    test({{1, 1}, {0, 1}}, {{1, 1}, {1, 0}}, true);

    return 0;
}
