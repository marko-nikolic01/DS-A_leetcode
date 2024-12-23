#include <iostream>
#include <vector>

using namespace std;

void totalNQueens(int n, int row, int& nQueens, vector<bool>& columns, vector<bool>& forwardDiagonals, vector<bool>& backwardDiagonals) {
    if(row == n - 1) {
        for(int i = 0; i < n; ++i) {
            if(!columns[i] && !forwardDiagonals[row + i] && !backwardDiagonals[n + row - i - 1]) {
                ++nQueens;
            }
        }
    } else {
        for(int i = 0; i < n; ++i) {
            if(!columns[i] && !forwardDiagonals[row + i] && !backwardDiagonals[n + row - i - 1]) {
                columns[i] = true;
                forwardDiagonals[row + i] = true;
                backwardDiagonals[n + row - i - 1] = true;

                totalNQueens(n, row + 1, nQueens, columns, forwardDiagonals, backwardDiagonals);

                columns[i] = false;
                forwardDiagonals[row + i] = false;
                backwardDiagonals[n + row - i - 1] = false;
            }
        }
    }
}

int totalNQueens(int n) {
    int nQueens = 0;

    vector<bool> columns(n, false);
    vector<bool> forwardDiagonals(2 * n - 1, false);
    vector<bool> backwardDiagonals(2 * n - 1, false);

    totalNQueens(n, 0, nQueens, columns, forwardDiagonals, backwardDiagonals);

    return nQueens;
}

void test(int n, int expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << totalNQueens(n) << endl;

    cout << endl;
}

int main()
{
    test(1, 1);
    test(2, 0);
    test(3, 0);
    test(4, 2);
    test(5, 10);
    test(6, 4);
    test(7, 40);
    test(8, 92);
    test(9, 352);

    return 0;
}
