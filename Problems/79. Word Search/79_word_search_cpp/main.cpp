#include <iostream>
#include <vector>

using namespace std;

bool exist(vector<vector<char>>& board, const string& word, int letterIndex, int x, int y) {
    if (letterIndex == word.size()) {
        return true;
    }

    int m = board.size();
    int n = board[0].size();

    if (x < 0 || x >= m || y < 0 || y >= n || board[x][y] != word[letterIndex]) {
        return false;
    }

    char temp = board[x][y];
    board[x][y] = ' ';

    bool exists =
        exist(board, word, letterIndex + 1, x + 1, y) ||
        exist(board, word, letterIndex + 1, x - 1, y) ||
        exist(board, word, letterIndex + 1, x, y + 1) ||
        exist(board, word, letterIndex + 1, x, y - 1);

    board[x][y] = temp;

    return exists;
}

bool exist(vector<vector<char>>& board, const string& word) {
    int m = board.size();
    int n = board[0].size();

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (exist(board, word, 0, i, j)) {
                return true;
            }
        }
    }

    return false;
}

void printBoard(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            cout << cell << ' ';
        }
        cout << endl;
    }
}

void runTestCase(vector<vector<char>> board, const string& word, bool expected) {
    cout << "Board:" << endl;
    printBoard(board);

    cout << "Word: " << word << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (exist(board, word) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    vector<vector<char>> board1 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    runTestCase(board1, "ABCCED", true);

    vector<vector<char>> board2 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    runTestCase(board2, "SEE", true);

    vector<vector<char>> board3 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    runTestCase(board3, "ABCB", false);

    vector<vector<char>> board4 = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    runTestCase(board4, "XYZ", false);

    return 0;
}
