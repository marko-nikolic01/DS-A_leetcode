#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long maximumScore(vector<vector<int>>& grid) {
    int n = grid[0].size();
    if(n == 1) {
        return 0;
    }

    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n + 1, vector<long long>(n + 1, 0)));
    vector<vector<long long>> prevMax(n + 1, vector<long long>(n + 1, 0));
    vector<vector<long long>> prevSuffixMax(n + 1, vector<long long>(n + 1, 0));
    vector<vector<long long>> colSum(n, vector<long long>(n + 1, 0));

    for(int c = 0; c < n; c++) {
        for(int r = 1; r <= n; r++) {
            colSum[c][r] = colSum[c][r - 1] + grid[r - 1][c];
        }
    }

    for(int i = 1; i < n; i++) {
        for(int currH = 0; currH <= n; currH++) {
            for(int prevH = 0; prevH <= n; prevH++) {
                if(currH <= prevH) {
                    long long extraScore = colSum[i][prevH] - colSum[i][currH];
                    dp[i][currH][prevH] = max(dp[i][currH][prevH], prevSuffixMax[prevH][0] + extraScore);
                } else {
                    long long extraScore = colSum[i - 1][currH] - colSum[i - 1][prevH];
                    dp[i][currH][prevH] = max({dp[i][currH][prevH], prevSuffixMax[prevH][currH], prevMax[prevH][currH] + extraScore});
                }
            }
        }

        for(int currH = 0; currH <= n; currH++) {
            prevMax[currH][0] = dp[i][currH][0];
            for(int prevH = 1; prevH <= n; prevH++) {
                long long penalty = (prevH > currH) ? (colSum[i][prevH] - colSum[i][currH]) : 0;
                prevMax[currH][prevH] = max(prevMax[currH][prevH - 1], dp[i][currH][prevH] - penalty);
            }

            prevSuffixMax[currH][n] = dp[i][currH][n];
            for(int prevH = n - 1; prevH >= 0; prevH--) {
                prevSuffixMax[currH][prevH] = max(prevSuffixMax[currH][prevH + 1], dp[i][currH][prevH]);
            }
        }
    }

    long long ans = 0;
    for(int k = 0; k <= n; k++) {
        ans = max({ans, dp[n - 1][n][k], dp[n - 1][0][k]});
    }

    return ans;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> grid, long long expected) {
    cout << "Matrix:" << endl;
    printMatrix(grid);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maximumScore(grid) << endl;

    cout << endl;
}

int main() {
    test({{0, 0, 0, 0, 0}, {0, 0, 3, 0, 0}, {0, 1, 0, 0, 0}, {5, 0, 0, 3, 0}, {0, 0, 0, 0, 2}}, 11);
    test({{10, 9, 0, 0, 15}, {7, 1, 0, 8, 0}, {5, 20, 0, 11, 0}, {0, 0, 0, 1, 2}, {8, 12, 1, 10, 3}}, 94);
    test({{1, 2}, {3, 4}}, 6);
    test({{5}}, 0);
    test({{1, 0, 1}, {0, 1, 0}, {1, 0, 1}}, 4);

    return 0;
}
