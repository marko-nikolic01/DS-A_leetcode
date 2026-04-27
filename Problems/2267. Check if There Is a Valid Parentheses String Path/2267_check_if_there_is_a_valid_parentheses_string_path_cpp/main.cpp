#include <iostream>
#include <vector>

using namespace std;

bool hasValidPath(vector<vector<char>>& grid) {
    if(grid[0][0] == ')') {
        return false;
    }

    short m = grid.size();
    short n = grid[0].size();
    vector<vector<vector<bool>>> paths(m, vector<vector<bool>>(n, vector<bool>(m + n, false)));

    paths[0][0][1] = true;

    short j;
    short k;
    for(short i = 0; i < m; ++i) {
        for(j = 0; j < n; ++j) {
            if(grid[i][j] == '(') {
                for(k = m + n - 1; k > 0; --k) {
                    if((i > 0 && paths[i - 1][j][k - 1]) || (j > 0 && paths[i][j - 1][k - 1])) {
                        paths[i][j][k] = true;
                    }
                }
            } else {
                for(k = m + n - 2; k > - 1; --k) {
                    if((i > 0 && paths[i - 1][j][k + 1]) || (j > 0 && paths[i][j - 1][k + 1])) {
                        paths[i][j][k] = true;
                    }
                }
            }
        }
    }

    return paths[--m][--n][0];
}

void printMatrix(vector<vector<char>> matrix) {
    for(vector<char> row : matrix) {
        for(char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<char>> grid, bool expected) {
    cout << "Parentheses:" << endl;
    printMatrix(grid);

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (hasValidPath(grid) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test({{'(', '(', '('}, {')', '(', ')'}, {'(', '(', ')'}, {'(', '(', ')'}}, true);
    test({{')', ')'}, {'(', '('}}, false);
    test({{'(', ')'}}, true);
    test({{')', '(', '('}, {'(', '(', ')'}, {'(', ')', ')'}}, false);
    test({{'(', '(', '('}, {'(', '(', '('}, {'(', '(', ')'}}, false);
    return 0;
}
