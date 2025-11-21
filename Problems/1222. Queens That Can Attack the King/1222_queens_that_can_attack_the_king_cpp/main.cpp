#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
    vector<vector<bool>> board(8, vector<bool>(8, false));
    short x;
    short y;

    for(x = queens.size() - 1; x > -1; --x) {
        board[queens[x][0]][queens[x][1]] = true;
    }

    short iQueen = -1;
    for(x = king[0] - 1; x > -1; --x) {
        if(board[x][king[1]]) {
            queens[++iQueen][0] = x;
            queens[iQueen][1] = king[1];
            break;
        }
    }

    for(x = king[0] + 1; x < 8; ++x) {
        if(board[x][king[1]]) {
            queens[++iQueen][0] = x;
            queens[iQueen][1] = king[1];
            break;
        }
    }

    for(y = king[1] - 1; y > -1; --y) {
        if(board[king[0]][y]) {
            queens[++iQueen][0] = king[0];
            queens[iQueen][1] = y;
            break;
        }
    }

    for(y = king[1] + 1; y < 8; ++y) {
        if(board[king[0]][y]) {
            queens[++iQueen][0] = king[0];
            queens[iQueen][1] = y;
            break;
        }
    }

    for(x = king[0] - 1, y = king[1] - 1; x > -1 && y > -1; --x, --y) {
        if(board[x][y]) {
            queens[++iQueen][0] = x;
            queens[iQueen][1] = y;
            break;
        }
    }

    for(x = king[0] - 1, y = king[1] + 1; x > -1 && y < 8; --x, ++y) {
        if(board[x][y]) {
            queens[++iQueen][0] = x;
            queens[iQueen][1] = y;
            break;
        }
    }

    for(x = ++king[0], y = king[1] - 1; x < 8 && y > -1; ++x, --y) {
        if(board[x][y]) {
            queens[++iQueen][0] = x;
            queens[iQueen][1] = y;
            break;
        }
    }

    for(x = king[0], y = ++king[1]; x < 8 && y < 8; ++x, ++y) {
        if(board[x][y]) {
            queens[++iQueen][0] = x;
            queens[iQueen][1] = y;
            break;
        }
    }

    queens.resize(++iQueen);

    return queens;
}

void test(vector<vector<int>> queens, vector<int> king, vector<vector<int>> expected) {
    cout << "Queens: ";
    for(vector<int> queen : queens) {
        cout << "[" << queen[0] << ", " << queen[1] << "] ";
    }
    cout << endl;

    cout << "King: " << "[" << king[0] << ", " << king[1] << "]" << endl;

    cout << "Expected: ";
    for(vector<int> e : expected) {
        cout << "[" << e[0] << ", " << e[1] << "] ";
    }
    cout << endl;

    cout << "Result: ";
    for(vector<int> result : queensAttacktheKing(queens, king)) {
        cout << "[" << result[0] << ", " << result[1] << "] ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    test({{0, 1}, {1, 0}, {4, 0}, {0, 4}, {3, 3}, {2, 4}}, {0, 0}, {{1, 0}, {0, 1}, {3, 3}});
    test({{0, 0}, {1, 1}, {2, 2}, {3, 4}, {3, 5}, {4, 4}, {4, 5}}, {3, 3}, {{3, 4}, {2, 2}, {4, 4}});
    test({{7, 7}}, {0, 0}, {{7, 7}});
    test({{0, 7}, {7, 0}, {7, 7}, {0, 0}}, {3, 5}, {});
    test({{3, 6}, {3, 1}, {6, 3}, {1, 3}, {5, 5}, {1, 1}}, {3, 3}, {{1, 3}, {6, 3}, {3, 1}, {3, 6}, {1, 1}, {5, 5}});

    return 0;
}
