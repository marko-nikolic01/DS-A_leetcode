#include <iostream>
#include <vector>

using namespace std;

void countBattleships(vector<vector<char>>& board, int x, int y) {
    board[x][y] = 'O';

    if(x > 0 && board[x - 1][y] == 'X') {
        countBattleships(board, x - 1, y);
        return;
    }

    if(y > 0 && board[x][y - 1] == 'X') {
        countBattleships(board, x, y - 1);
    }
}

int countBattleships(vector<vector<char>>& board) {
    int battleships = 0;

    int n = board[0].size() - 1;

    for(int i = board.size() - 1; i > -1; --i) {
        for(int j = n; j > -1; --j) {
            if(board[i][j] == 'X') {
                countBattleships(board, i, j);
                battleships++;
            }
        }
    }

    return battleships;
}

void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << ' ';
        }
        cout << endl;
    }
}

void test(vector<vector<char>> board, int expected) {
    cout << "Board:" << endl;
    printBoard(board);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countBattleships(board) << endl;

    cout << endl;
}

int main() {
    vector<vector<char>> board1 = {
        {'X', '.', '.', 'X'},
        {'.', '.', '.', 'X'},
        {'.', '.', '.', 'X'}
    };
    test(board1, 2);

    vector<vector<char>> board2 = {
        {'X', 'X', '.', 'X'},
        {'.', '.', '.', 'X'},
        {'.', '.', '.', 'X'}
    };
    test(board2, 2);

    vector<vector<char>> board3 = {
        {'.', '.', '.', '.'},
        {'.', 'X', 'X', '.'},
        {'.', '.', '.', '.'}
    };
    test(board3, 1);

    vector<vector<char>> board4 = {
        {'X', '.', 'X', '.', 'X'}
    };
    test(board4, 3);

    vector<vector<char>> board5 = {
        {'.', '.', '.'},
        {'.', '.', '.'},
        {'.', '.', '.'}
    };
    test(board5, 0);

    vector<vector<char>> board6 = {
        {'X'}
    };
    test(board6, 1);

    vector<vector<char>> board7 = {
        {'.'}
    };
    test(board7, 0);

    return 0;
}
