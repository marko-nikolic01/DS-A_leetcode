#include <iostream>
#include <vector>

using namespace std;

void solve(vector<vector<char>>& board, vector<vector<bool>>& surrounded, short x, short y, short& m, short& n) {
    surrounded[x][y] = false;

    if(x > 0 && board[x - 1][y] == 'O' && surrounded[x - 1][y]) {
        solve(board, surrounded, x - 1, y, m, n);
    }

    if(x < m && board[x + 1][y] == 'O' && surrounded[x + 1][y]) {
        solve(board, surrounded, x + 1, y, m, n);
    }

    if(y > 0 && board[x][y - 1] == 'O' && surrounded[x][y - 1]) {
        solve(board, surrounded, x, y - 1, m, n);
    }

    if(y < n && board[x][y + 1] == 'O' && surrounded[x][y + 1]) {
        solve(board, surrounded, x, y + 1, m, n);
    }
}

void solve(vector<vector<char>>& board) {
    short m = board.size();
    short n = board[0].size();
    vector<vector<bool>> surrounded(m, vector<bool>(n--, true));

    short i;
    for(i = --m; i > -1; --i) {
        if(board[i][0] == 'O' && surrounded[i][0]) {
            solve(board, surrounded, i, 0, m, n);
        }

        if(board[i][n] == 'O' && surrounded[i][n]) {
            solve(board, surrounded, i, n, m, n);
        }
    }

    for(i = n; i > -1; --i) {
        if(board[0][i] == 'O' && surrounded[0][i]) {
            solve(board, surrounded, 0, i, m, n);
        }

        if(board[m][i] == 'O' && surrounded[m][i]) {
            solve(board, surrounded, m, i, m, n);
        }
    }

    --n;
    for(--m; m > 0; --m) {
        for(i = n; i > 0; --i) {
            if(surrounded[m][i]) {
                board[m][i] = 'X';
            }
        }
    }
}

void printMatrix(vector<vector<char>> matrix) {
    for(vector<char> row : matrix) {
        for(char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<char>> board, vector<vector<char>> expected) {
    cout << "Board:" << endl;
    printMatrix(board);

    cout << "Expected:" << endl;
    printMatrix(expected);

    solve(board);
    cout << "Result:" << endl;
    printMatrix(board);

    cout << endl;
}

int main() {
    vector<vector<char>> board1 = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };
    vector<vector<char>> expected1 = {
        {'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X'}
    };
    test(board1, expected1);

    vector<vector<char>> board2 = {
        {'X'}
    };
    vector<vector<char>> expected2 = {
        {'X'}
    };
    test(board2, expected2);

    vector<vector<char>> board3 = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'X', 'X'}
    };
    vector<vector<char>> expected3 = {
        {'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X'}
    };
    test(board3, expected3);

    vector<vector<char>> board4 = {
        {'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O'}
    };
    vector<vector<char>> expected4 = {
        {'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O'}
    };
    test(board4, expected4);

    vector<vector<char>> board5 = {
        {'X', 'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'O', 'X'},
        {'X', 'O', 'O', 'O', 'X'},
        {'X', 'O', 'X', 'O', 'X'},
        {'X', 'X', 'X', 'X', 'X'}
    };
    vector<vector<char>> expected5 = {
        {'X', 'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X', 'X'}
    };
    test(board5, expected5);

    vector<vector<char>> board6 = {
        {'X', 'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'O', 'X'},
        {'X', 'O', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'O', 'X'},
        {'X', 'O', 'O', 'O', 'X'},
        {'X', 'X', 'X', 'X', 'X'}
    };
    vector<vector<char>> expected6 = {
        {'X', 'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X', 'X'},
        {'X', 'X', 'X', 'X', 'X'}
    };
    test(board6, expected6);

    return 0;
}
