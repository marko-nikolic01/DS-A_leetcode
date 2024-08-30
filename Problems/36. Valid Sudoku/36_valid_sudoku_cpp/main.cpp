#include <iostream>
#include <vector>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
    for (int i = 0; i < 9; ++i) {
        vector<bool> row(9, false);
        vector<bool> column(9, false);
        vector<bool> cell(9, false);

        for (int j = 0; j < 9; ++j) {
            if (board[i][j] != '.') {
                if (row[board[i][j] - '1']) {
                    return false;
                }
                row[board[i][j] - '1'] = true;
            }

            if (board[j][i] != '.') {
                if (column[board[j][i] - '1']) {
                    return false;
                }
                column[board[j][i] - '1'] = true;
            }

            int rowIndex = 3 * (i / 3) + j / 3;
            int colIndex = 3 * (i % 3) + j % 3;
            if (board[rowIndex][colIndex] != '.') {
                if (cell[board[rowIndex][colIndex] - '1']) {
                    return false;
                }
                cell[board[rowIndex][colIndex] - '1'] = true;
            }
        }
    }

    return true;
}

void printBoard(vector<vector<char>>& board) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void runTest(vector<vector<char>> board, bool expected) {
    cout << "Board:" << endl;
    printBoard(board);

    bool result = isValidSudoku(board);

    cout << "Expected: " << (expected ? "true" : "false") << endl;
    cout << "Result: " << (result ? "true" : "false") << endl;
    cout << endl;
}

int main() {
    vector<vector<char>> board1 = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    runTest(board1, true);

    vector<vector<char>> board2 = {
        {'8', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    runTest(board2, false);

    return 0;
}
