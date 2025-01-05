#include <iostream>
#include <vector>

using namespace std;

bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
    char oppositeColor = color == 'W' ? 'B' : 'W';

    if(rMove > 1 && board[rMove - 1][cMove] == oppositeColor) {
        for(short i = rMove - 2; i > -1 && board[i][cMove] != '.'; --i) {
            if(board[i][cMove] == color) {
                return true;
            }
        }
    }

    if(rMove < 6 && board[rMove + 1][cMove] == oppositeColor) {
        for(short i = rMove + 2; i < 8 && board[i][cMove] != '.'; ++i) {
            if(board[i][cMove] == color) {
                return true;
            }
        }
    }

    if(cMove > 1 && board[rMove][cMove - 1] == oppositeColor) {
        for(short i = cMove - 2; i > -1 && board[rMove][i] != '.'; --i) {
            if(board[rMove][i] == color) {
                return true;
            }
        }
    }

    if(cMove < 6 && board[rMove][cMove + 1] == oppositeColor) {
        for(short i = cMove + 2; i < 8 && board[rMove][i] != '.'; ++i) {
            if(board[rMove][i] == color) {
                return true;
            }
        }
    }

    if(rMove > 1 && cMove > 1 && board[rMove - 1][cMove - 1] == oppositeColor) {
        for(short i = rMove - 2, j = cMove - 2; i > -1 && j > -1 && board[i][j] != '.'; --i, --j) {
            if(board[i][j] == color) {
                return true;
            }
        }
    }

    if(rMove > 1 && cMove < 6 && board[rMove - 1][cMove + 1] == oppositeColor) {
        for(short i = rMove - 2, j = cMove + 2; i > -1 && j < 8 && board[i][j] != '.'; --i, ++j) {
            if(board[i][j] == color) {
                return true;
            }
        }
    }

    if(rMove < 6 && cMove > 1 && board[rMove + 1][cMove - 1] == oppositeColor) {
        for(short i = rMove + 2, j = cMove - 2; i < 8 && j > -1 && board[i][j] != '.'; ++i, --j) {
            if(board[i][j] == color) {
                return true;
            }
        }
    }

    if(rMove < 6 && cMove < 6 && board[rMove + 1][cMove + 1] == oppositeColor) {
        for(short i = rMove + 2, j = cMove + 2; i < 8 && j < 8 && board[i][j] != '.'; ++i, ++j) {
            if(board[i][j] == color) {
                return true;
            }
        }
    }

    return false;
}

void printMatrix(const vector<vector<char>> matrix) {
    for (vector<char> row : matrix) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<char>> board, int rMove, int cMove, char color, bool expected) {
    cout << "Board: " << endl;
    printMatrix(board);

    cout << "Row move: " << rMove << endl;

    cout << "Column move: " << cMove << endl;

    cout << "Color: " << color << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (checkMove(board, rMove, cMove, color) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    vector<vector<char>> board1 = {
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', 'B', '.', '.', '.', '.'},
        {'.', '.', '.', 'W', '.', '.', '.', '.'},
        {'.', '.', '.', 'W', '.', '.', '.', '.'},
        {'W', 'B', 'B', '.', 'W', 'W', 'W', 'B'},
        {'.', '.', '.', 'B', '.', '.', '.', '.'},
        {'.', '.', '.', 'B', '.', '.', '.', '.'},
        {'.', '.', '.', 'W', '.', '.', '.', '.'}
    };
    test(board1, 4, 3, 'B', true);

    vector<vector<char>> board2 = {
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', 'W', '.', '.', '.', '.'},
        {'.', '.', '.', 'W', '.', '.', '.', '.'},
        {'.', '.', '.', 'W', '.', '.', '.', '.'},
        {'W', 'B', 'B', '.', 'W', 'W', 'W', 'B'},
        {'.', '.', '.', 'B', '.', '.', '.', '.'},
        {'.', '.', '.', 'B', '.', '.', '.', '.'},
        {'.', '.', '.', 'W', '.', '.', '.', '.'}
    };
    test(board2, 4, 4, 'B', true);

    vector<vector<char>> board3 = {
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', 'B', '.', '.', '.', '.'},
        {'.', '.', '.', 'W', '.', '.', '.', '.'},
        {'.', '.', '.', 'B', '.', '.', '.', '.'},
        {'W', 'B', 'B', '.', 'W', 'W', 'W', 'B'},
        {'.', '.', '.', 'B', '.', '.', '.', '.'},
        {'.', '.', '.', 'B', '.', '.', '.', '.'},
        {'.', '.', '.', 'W', '.', '.', '.', '.'}
    };
    test(board3, 4, 5, 'W', false);

    vector<vector<char>> board4 = {
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', 'B', '.', '.', '.', '.'},
        {'.', '.', '.', 'B', '.', '.', '.', '.'},
        {'.', '.', '.', 'W', '.', '.', '.', '.'},
        {'W', 'B', 'B', '.', 'W', 'W', 'W', 'B'},
        {'.', '.', '.', 'B', '.', '.', '.', '.'},
        {'.', '.', '.', 'B', '.', '.', '.', '.'},
        {'.', '.', '.', 'W', '.', '.', '.', '.'}
    };
    test(board4, 4, 4, 'W', false);

    vector<vector<char>> board5 = {
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', 'W', '.', '.', '.', '.'},
        {'.', '.', '.', 'B', '.', '.', '.', '.'},
        {'.', '.', '.', 'W', '.', '.', '.', '.'},
        {'W', 'B', 'B', '.', 'W', 'W', 'W', 'B'},
        {'.', '.', '.', 'B', '.', '.', '.', '.'},
        {'.', '.', '.', 'B', '.', '.', '.', '.'},
        {'.', '.', '.', 'W', '.', '.', '.', '.'}
    };
    test(board5, 4, 4, 'B', true);

    vector<vector<char>> board6 = {
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', 'B', '.', '.', '.', '.'},
        {'.', '.', '.', 'W', '.', '.', '.', '.'},
        {'.', '.', '.', 'B', '.', '.', '.', '.'},
        {'W', 'B', 'B', '.', 'W', 'W', 'W', 'B'},
        {'.', '.', '.', 'B', '.', '.', '.', '.'},
        {'.', '.', '.', 'B', '.', '.', '.', '.'},
        {'.', '.', '.', 'W', '.', '.', '.', '.'}
    };
    test(board6, 4, 4, 'W', false);

    return 0;
}
