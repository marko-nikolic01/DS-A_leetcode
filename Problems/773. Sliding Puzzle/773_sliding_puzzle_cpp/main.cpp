#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int slidingPuzzle(vector<vector<int>>& board) {
    vector<bool> boards(7465, false);
    vector<short> scores = {0, 1, 6, 36, 216, 1296};

    queue<pair<short, short>> traversal;
    short currentBoard;
    short nextBoard = scores[board[0][1]] + 2 * scores[board[0][2]] + 3 * scores[board[1][0]] + 4 * scores[board[1][1]] + 5 * scores[board[1][2]];
    short moves;

    if(nextBoard == 5910) {
        return 0;
    }

    traversal.push({nextBoard, 0});
    boards[nextBoard] = true;

    short i;
    short j;
    while(!traversal.empty()) {
        currentBoard = traversal.front().first;
        moves = traversal.front().second + 1;
        traversal.pop();

        for(i = 0; i < 2; ++i) {
            for(j = 0; j < 3; ++j) {
                board[i][j] = 0;
            }
        }

        nextBoard = currentBoard;

        for(i = 5; i > 0; --i) {
            j = nextBoard / scores[i];
            board[j / 3][j % 3] = i;
            nextBoard %= scores[i];
        }

        for(i = 0; i < 2; ++i) {
            for(j = 0; j < 3; ++j) {
                if(board[i][j] < 1) {
                    if(i < 1) {
                        nextBoard = currentBoard - 3 * scores[board[1][j]];
                    } else {
                        nextBoard = currentBoard + 3 * scores[board[0][j]];
                    }

                    if(nextBoard == 5910) {
                        return moves;
                    } else if(!boards[nextBoard]) {
                        traversal.push({nextBoard, moves});
                        boards[nextBoard] = true;
                    }

                    if(j < 2) {
                        nextBoard = currentBoard - scores[board[i][j + 1]];

                        if(nextBoard == 5910) {
                            return moves;
                        } else if(!boards[nextBoard]) {
                            traversal.push({nextBoard, moves});
                            boards[nextBoard] = true;
                        }
                    }

                    if(j > 0) {
                        nextBoard = currentBoard + scores[board[i][j - 1]];

                        if(nextBoard == 5910) {
                            return moves;
                        } else if(!boards[nextBoard]) {
                            traversal.push({nextBoard, moves});
                            boards[nextBoard] = true;
                        }
                    }
                }
            }
        }
    }

    return -1;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> board, int expected) {
    cout << "Board:" << endl;
    printMatrix(board);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << slidingPuzzle(board) << endl;

    cout << endl;
}

int main() {
    test({{1, 2, 3}, {4, 0, 5}}, 1);
    test({{1, 2, 3}, {5, 4, 0}}, -1);
    test({{4, 1, 2}, {5, 0, 3}}, 5);
    test({{1, 2, 3}, {4, 5, 0}}, 0);
    test({{1, 2, 3}, {0, 4, 5}}, 2);

    return 0;
}
