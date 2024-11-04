#include <iostream>
#include <vector>

using namespace std;

int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
    vector<vector<short>> board(m, vector<short> (n, 0));

    int k = walls.size();
    int unguarded = m * n - k;

    for(--k; k > -1; --k) {
        board[walls[k][0]][walls[k][1]] = 1;
    }

    k = guards.size();
    unguarded -= k;

    for(--k; k > -1; --k) {
        board[guards[k][0]][guards[k][1]] = 2;
    }

    k = guards.size();

    for(--k; k > -1; --k) {
        for (int i = guards[k][0] - 1; i > -1; --i) {
            if (board[i][guards[k][1]] == 0) {
                board[i][guards[k][1]] = 3;
                unguarded--;
            } else if(board[i][guards[k][1]] != 3) {
                break;
            }
        }

        for (int i = guards[k][0] + 1; i < m; ++i) {
            if (board[i][guards[k][1]] == 0) {
                board[i][guards[k][1]] = 3;
                unguarded--;
            } else if(board[i][guards[k][1]] != 3) {
                break;
            }
        }

        for (int i = guards[k][1] - 1; i > -1; --i) {
            if (board[guards[k][0]][i] == 0) {
                board[guards[k][0]][i] = 3;
                unguarded--;
            } else if(board[guards[k][0]][i] != 3) {
                break;
            }
        }

        for (int i = guards[k][1] + 1; i < n; ++i) {
            if (board[guards[k][0]][i] == 0) {
                board[guards[k][0]][i] = 3;
                unguarded--;
            } else if(board[guards[k][0]][i] != 3) {
                break;
            }
        }
    }

    return unguarded;
}

void test(int m, int n, vector<vector<int>> guards, vector<vector<int>> walls, int expected) {
    cout << "m: " << m << endl;

    cout << "n: " << n << endl;

    cout << "Guards: ";
    for (auto& guard : guards) {
        cout << "[" << guard[0] << ", " << guard[1] << "] ";
    }
    cout << endl;

    cout << "Walls: ";
    for (auto& wall : walls) {
        cout << "[" << wall[0] << ", " << wall[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countUnguarded(m, n, guards, walls) << endl;

    cout << endl;
}

int main() {
    test(4, 6, {{0, 0}, {1, 3}}, {{0, 1}, {2, 2}, {1, 5}}, 10);
    test(5, 5, {{0, 0}}, {{2, 2}}, 15);
    test(3, 3, {{1, 1}}, {{0, 0}, {0, 2}, {2, 0}, {2, 2}}, 0);
    test(4, 4, {{1, 1}, {2, 2}}, {{0, 0}, {3, 3}}, 2);
    test(3, 4, {{0, 1}}, {{2, 1}}, 6);

    return 0;
}
