#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> findFarmland(vector<vector<int>>& land) {
    vector<vector<int>> farmland;

    int n = land[0].size() - 1;

    for (int i = land.size() - 1; i > -1; --i) {
        for (int j = n; j > -1; --j) {
            if (land[i][j] == 1) {
                int upperX = i;
                int upperY = j;

                land[i][j] = -1;

                while (upperX > 0 && land[upperX - 1][j] == 1) {
                    land[--upperX][j] = -1;
                }

                while (upperY > 0 && land[i][upperY - 1] == 1) {
                    land[i][--upperY] = -1;
                }

                for (int x = i - 1; x >= upperX; --x) {
                    for (int y = j - 1; y >= upperY; --y) {
                        land[x][y] = -1;
                    }
                }

                farmland.push_back({upperX, upperY, i, j});
                j = upperY;
            }
        }
    }

    return farmland;
}

void runTest(vector<vector<int>> land, vector<vector<int>> expected) {
    cout << "Farmland:" << endl;
    for (const auto& row : land) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    cout << "Expected: ";
    for (auto res : expected) {
        cout << "[" << res[0] << ", " << res[1] << ", " << res[2] << ", " << res[3] << "], ";
    }
    cout << endl;

    cout << "Result: ";
    for (auto res : findFarmland(land)) {
        cout << "[" << res[0] << ", " << res[1] << ", " << res[2] << ", " << res[3] << "], ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    vector<vector<int>> test1 = {
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 0, 1, 1},
        {0, 0, 1, 1}
    };
    vector<vector<int>> expected1 = {{2, 2, 3, 3}, {0, 0, 1, 1}};
    runTest(test1, expected1);

    vector<vector<int>> test2 = {
        {0, 0, 0},
        {0, 0, 0}
    };
    vector<vector<int>> expected2 = {};
    runTest(test2, expected2);

    vector<vector<int>> test3 = {
        {0, 0, 1},
        {0, 0, 0}
    };
    vector<vector<int>> expected3 = {{0, 2, 0, 2}};
    runTest(test3, expected3);

    vector<vector<int>> test4 = {
        {1, 1, 1},
        {1, 1, 1},
        {0, 0, 0},
        {0, 0, 1}
    };
    vector<vector<int>> expected4 = {{3, 2, 3, 2}, {0, 0, 1, 2}};
    runTest(test4, expected4);

    vector<vector<int>> test5 = {
        {1, 1, 1},
        {1, 1, 1}
    };
    vector<vector<int>> expected5 = {{0, 0, 1, 2}};
    runTest(test5, expected5);

    return 0;
}
