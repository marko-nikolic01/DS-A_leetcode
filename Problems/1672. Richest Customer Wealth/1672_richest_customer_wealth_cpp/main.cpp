#include <iostream>
#include <vector>

using namespace std;

int maximumWealth(vector<vector<int>>& accounts) {
    int wealth = 0;
    int currentWealth;

    short j;
    short n = accounts[0].size() - 1;
    for(short i = accounts.size() - 1; i > -1; --i) {
        currentWealth = accounts[i][0];
        for(j = n; j > 0; --j) {
            currentWealth += accounts[i][j];
        }

        if(currentWealth > wealth) {
            wealth = currentWealth;
        }
    }

    return wealth;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> accounts, int expected) {
    cout << "Bank accounts:" << endl;
    printMatrix(accounts);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maximumWealth(accounts) << endl;

    cout << endl;
}

int main() {
    test({{1, 2, 3}, {3, 2, 1}}, 6);
    test({{1, 5}, {7, 3}, {3, 5}}, 10);
    test({{2, 8, 7}, {7, 1, 3}, {1, 9, 5}}, 17);
    test({{10, 10}, {5, 5}, {9, 1}}, 20);
    test({{10, 10, 10}, {15, 15, 15}, {5, 5, 5}}, 45);

    return 0;
}
