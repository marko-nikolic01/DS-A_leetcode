#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int maximumAmount(vector<vector<int>>& coins) {
    short n = coins[0].size();
    vector profit(++n, vector<int>(3, -1000000000));

    short i;
    for(i = 0; i < 3; ++i) {
        profit[1][i] = 0;
    }

    short j;
    short m = coins.size();
    for(i = 0; i < m; ++i) {
        for(int j = 1; j < n; ++j) {
            profit[j][2] = max({profit[j - 1][2] + coins[i][j - 1], profit[j][2] + coins[i][j - 1], profit[j - 1][1], profit[j][1]});
            profit[j][1] = max({profit[j - 1][1] + coins[i][j - 1], profit[j][1] + coins[i][j - 1], profit[j - 1][0], profit[j][0]});
            profit[j][0] = max(profit[j - 1][0], profit[j][0]) + coins[i][j - 1];
        }
    }

    return profit[--n][2];
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> coins, int expected) {
    cout << "Coins:" << endl;
    printMatrix(coins);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maximumAmount(coins) << endl;

    cout << endl;
}

int main() {
    test({{0, 1, -1}, {1, -2, 3}, {2, -3, 4}}, 8);
    test({{10, 10, 10}, {10, 10, 10}}, 40);
    test({{-7, 12, 12, 13}, {-6, 19, 19, -6}, {9, -2, -10, 16}, {-4, 14, -10, -9}}, 60);
    test({{-5}}, 0);
    test({{1, 2}, {3, 4}}, 8);

    return 0;
}
