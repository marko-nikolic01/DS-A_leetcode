#include <iostream>
#include <vector>

using namespace std;

 void solveNQueens(int n, int row, vector<vector<string>>& nQueens, vector<string>& solution, vector<bool>& columns, vector<bool>& forwardDiagonals, vector<bool>& backwardDiagonals) {
    if(row == n - 1) {
        for(int i = 0; i < n; ++i) {
            if(!columns[i] && !forwardDiagonals[row + i] && !backwardDiagonals[n + row - i - 1]) {
                solution[row][i] = 'Q';
                columns[i] = true;
                forwardDiagonals[row + i] = true;
                backwardDiagonals[n + row - i - 1] = true;

                nQueens.push_back(solution);

                solution[row][i] = '.';
                columns[i] = false;
                forwardDiagonals[row + i] = false;
                backwardDiagonals[n + row - i - 1] = false;
            }
        }
    } else {
        for(int i = 0; i < n; ++i) {
            if(!columns[i] && !forwardDiagonals[row + i] && !backwardDiagonals[n + row - i - 1]) {
                solution[row][i] = 'Q';
                columns[i] = true;
                forwardDiagonals[row + i] = true;
                backwardDiagonals[n + row - i - 1] = true;

                solveNQueens(n, row + 1, nQueens, solution, columns, forwardDiagonals, backwardDiagonals);

                solution[row][i] = '.';
                columns[i] = false;
                forwardDiagonals[row + i] = false;
                backwardDiagonals[n + row - i - 1] = false;
            }
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> nQueens;

    vector<bool> columns(n, false);
    vector<bool> forwardDiagonals(2 * n - 1, false);
    vector<bool> backwardDiagonals(2 * n - 1, false);

    vector<string> solution(n, string(n, '.'));

    solveNQueens(n, 0, nQueens, solution, columns, forwardDiagonals, backwardDiagonals);

    return nQueens;
}

void printMatrix(vector<vector<string>> solutions) {
    for (vector<string> solution : solutions) {
        for (string row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }
}

void test(int n, vector<vector<string>> expected) {
    cout << "n: " << n << endl;

    cout << "Expected:" << endl;
    printMatrix(expected);

    cout << "Result:" << endl;
    printMatrix(solveNQueens(n));

    cout << "----------------------------" << endl;
}

int main() {
    test(1, {
        {"Q"}}
    );

    test(2, {});

    test(3, {});

    test(4, {
        {".Q..", "...Q", "Q...", "..Q."},
        {"..Q.", "Q...", "...Q", ".Q.."}
    });

    test(5, {
        {"Q....", "..Q..", "....Q", ".Q...", "...Q."},
        {"Q....", "...Q.", ".Q...", "....Q", "..Q.."},
        {".Q...", "...Q.", "Q....", "..Q..", "....Q"},
        {".Q...", "....Q", "..Q..", "Q....", "...Q."},
        {"..Q..", "Q....", "...Q.", ".Q...", "....Q"},
        {"..Q..", "....Q", ".Q...", "...Q.", "Q...."},
        {"...Q.", "Q....", "..Q..", "....Q", ".Q..."},
        {"...Q.", ".Q...", "....Q", "..Q..", "Q...."},
        {"....Q", ".Q...", "...Q.", "Q....", "..Q.."},
        {"....Q", "..Q..", "Q....", "...Q.", ".Q..."}
    });

    return 0;
}
