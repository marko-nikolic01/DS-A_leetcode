#include <iostream>
#include <vector>

using namespace std;

bool areSimilar(vector<vector<int>>& mat, int k) {
    short n = mat[0].size();

    k %= n;

    short j;
    short m = mat.size();
    for(short i = 0; i < m; ++i) {
        for(j = 0; j < n; ++j) {
            if(mat[i][j] != mat[i][(j + k) % n]) {
                return false;
            }
        }
    }

    return true;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> mat, int k, bool expected) {
    cout << "Matrix:" << endl;
    printMatrix(mat);

    cout << "k: " << k << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (areSimilar(mat, k) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, 4, false);
    test({{1, 2, 1, 2}, {5, 5, 5, 5}, {6, 3, 6, 3}}, 2, true);
    test({{2, 2}, {2, 2}}, 3, true);
    test({{1, 2, 3}, {4, 5, 6}}, 3, true);
    test({{1, 2, 3}, {4, 5, 6}}, 6, true);

    return 0;
}
