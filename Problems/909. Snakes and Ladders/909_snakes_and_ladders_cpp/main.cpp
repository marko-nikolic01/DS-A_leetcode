#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();
    vector<int> min_rolls(n * n + 1, -1);
    queue<int> q;
    min_rolls[1] = 0;
    q.push(1);

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        for(int i = 1; i <= 6 && x + i <= n * n; i++) {
            int t = x + i, row = (t - 1) / n, col = (t - 1) % n;
            int v = board[n - 1 - row][row % 2 ? n - 1 - col : col];
            int y = v > 0 ? v : t;

            if(y == n * n) {
                return min_rolls[x] + 1;
            }

            if(min_rolls[y] == -1) {
                min_rolls[y] = min_rolls[x] + 1;
                q.push(y);
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

    cout << "Result: " << snakesAndLadders(board) << endl;

    cout << endl;
}

int main() {
    test({ { -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1 }, { -1, -1, -1, -1, -1, -1 }, { -1, 35, -1, -1, 13, -1 }, { -1, -1, -1, -1, -1, -1 }, { -1, 15, -1, -1, -1, -1 } }, 4);
    test({ { -1, -1 }, { -1, 3 } }, 1);
    test({ { -1, -1, -1 }, { -1, -1, -1 }, { -1, -1, -1 } }, 2);
    test({ { -1, -1, -1 }, { -1, -1, -1 }, { -1, -1, 9 } }, 1);
    test({ { -1, -1, -1 }, { -1, -1, -1 }, { 2, 2, 2 } }, 2);

    return 0;
}
