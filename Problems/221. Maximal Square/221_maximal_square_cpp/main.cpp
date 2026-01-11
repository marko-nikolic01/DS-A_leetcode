#include <iostream>
#include <vector>

using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
    short area = 0;
    short m = matrix.size();
    short n = matrix[0].size();
    vector<vector<short>> streaks(m + 1, vector<short> (n));
    short streak;
    short side;

    short i;
    short j;
    for(i = 0; i < m; ++i) {
        streak = 0;

        for(j = 0; j < n; ++j) {
            if(matrix[i][j] < '1') {
                streaks[i][j] = 0;
                streak = 0;
            } else {
                streaks[i][j] = ++streak;
            }
        }
    }

    vector<pair<short, short>> currentStreaks;

    for(j = 0; j < n; ++j) {
        streaks[m][j] = 0;
        currentStreaks.resize(0);

        for(i = 0; i <= m; ++i) {
            streak = i;

            while(!currentStreaks.empty() && streaks[i][j] < currentStreaks.back().first) {
                streak = currentStreaks.back().second;
                side = min((short)(i - streak), currentStreaks.back().first);

                if(side > area) {
                    area = side;
                }

                currentStreaks.pop_back();
            }

            if(currentStreaks.empty() || currentStreaks.back().first < streaks[i][j]) {
                currentStreaks.push_back({streaks[i][j], streak});
            }
        }
    }

    return area * area;
}

void printMatrix(vector<vector<char>> matrix) {
    for(vector<char> row : matrix) {
        for(char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<char>> matrix, int expected) {
    cout << "Matrix:" << endl;
    printMatrix(matrix);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maximalSquare(matrix) << endl;

    cout << endl;
}

int main() {
    test({{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}}, 4);
    test({{'0', '1'}, {'1', '0'}}, 1);
    test({{'0'}}, 0);
    test({{'1'}}, 1);
    test({{'1', '0', '1', '1', '0', '1'}, {'1', '1', '1', '1', '1', '1'}, {'0', '1', '1', '0', '1', '1'}, {'1', '1', '1', '0', '1', '0'}, {'0', '1', '1', '1', '1', '1'}, {'1', '1', '0', '1', '1', '1'}}, 4);
    test({{'1', '1', '1', '1'}, {'1', '1', '1', '1'}, {'1', '1', '1', '1'}}, 9);
    test({{'0', '0', '0', '0'}, {'0', '0', '0', '0'}, {'0', '0', '0', '0'}}, 0);

    return 0;
}
