#include <iostream>
#include <vector>

using namespace std;

int countSquares(vector<vector<int>>& matrix) {
    int squares = 0;

    int m = matrix.size();
    int n = matrix[0].size();

    for(int i = 0; i < m; ++i) {
        if(matrix[i][0] == 1) {
            squares++;
        }
    }

    for(int i = 1; i < n; ++i) {
        if(matrix[0][i] == 1) {
            squares++;
        }
    }

    if(m < 2) {
        return squares;
    }

    int rowStreak = matrix[0][0];

    for(int i = 1; i < n; ++i) {
        if(matrix[1][i] == 1) {
            if(matrix[0][i] == 1) {
                if(matrix[1][i - 1] > 0 && rowStreak > 0) {
                    matrix[1][i]++;
                    squares += 2;
                } else {
                    squares++;
                }
            } else {
                squares++;
            }
            rowStreak = matrix[0][i]++;
        } else {
            rowStreak = matrix[0][i];
            matrix[0][i] = 0;
        }
    }

    for(int i = 2; i < m; ++i) {
        rowStreak = matrix[i][0];
        for(int j = 1; j < n; ++j) {
            if(matrix[i][j] == 1) {
                int squaresToAdd = ++rowStreak < ++matrix[0][j] ? rowStreak : matrix[0][j];
                if(matrix[i - 1][j - 1] + 1 < squaresToAdd) {
                    squaresToAdd = matrix[i - 1][j - 1] + 1;
                }

                squares += squaresToAdd;
                matrix[i][j] = squaresToAdd;
            } else {
                rowStreak = 0;
                matrix[0][j] = 0;
            }
        }
    }

    return squares;
}

void test(vector<vector<int>> matrix, int expected) {
    cout << "Matrix:" << endl;
    for (const auto& row : matrix) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countSquares(matrix) << endl;

    cout << endl;
}

int main() {
    test({{1, 0, 1}, {1, 1, 0}, {1, 1, 0}}, 7);
    test({{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}, 14);
    test({{1, 0, 1}, {0, 1, 0}, {1, 0, 1}}, 5);
    test({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, 0);
    test({{1, 1}, {1, 1}}, 5);
    test({{1, 1, 0, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 0}}, 21);
    test({{1, 0, 1}}, 2);
    test({{1}}, 1);
    test({{0}}, 0);

    return 0;
}
