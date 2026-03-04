#include <iostream>
#include <vector>

using namespace std;

int numSpecial(vector<vector<int>>& mat) {
    short special = 0;
    short m = mat.size();
    short n = mat[0].size();
    bool isSpecial;

    short j;
    short k;
    for(short i = 0; i < m; ++i) {
        for(j = 0; j < n; ++j) {
            if(mat[i][j] == 0) {
                continue;
            }

            isSpecial = true;

            for(k = 0; k < m; ++k) {
                if(k != i && mat[k][j] == 1) {
                    isSpecial = false;

                    break;
                }
            }

            for(k = 0; k < n; ++k) {
                if (k != j && mat[i][k] == 1) {
                    isSpecial = false;

                    break;
                }
            }

            if(isSpecial) {
                ++special;
            }
        }
    }

    return special;
}


void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> mat, int expected) {
    cout << "Matrix:" << endl;
    printMatrix(mat);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numSpecial(mat) << endl;

    cout << endl;
}

int main() {
    test({{1, 0, 0}, {0, 0, 1}, {1, 0, 0}}, 1);
    test({{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}, 3);
    test({{0, 0, 0, 1}, {1, 0, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}}, 2);
    test({{1}}, 1);
    test({{0, 0}, {0, 0}, {1, 0}}, 1);

    return 0;
}
