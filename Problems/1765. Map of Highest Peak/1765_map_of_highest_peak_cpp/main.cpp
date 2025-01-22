#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    queue<pair<short, short>> sources;

    short x;
    short y;

    short m = isWater.size();
    short n = isWater[0].size();
    for(x = 0; x < m; ++x) {
        for(y = 0; y < n; ++y) {
            if(isWater[x][y] > 0) {
                isWater[x][y] = 0;
                sources.push({x, y});
            } else {
                isWater[x][y] = -1;
            }
        }
    }

    --m;
    --n;
    while(!sources.empty()) {
        tie(x, y) = sources.front();
        sources.pop();

        if(x > 0 && isWater[x - 1][y] < 0) {
            isWater[x - 1][y] = isWater[x][y] + 1;
            sources.push({x - 1, y});
        }

        if(x < m && isWater[x + 1][y] < 0) {
            isWater[x + 1][y] = isWater[x][y] + 1;
            sources.push({x + 1, y});
        }

        if(y > 0 && isWater[x][y - 1] < 0) {
            isWater[x][y - 1] = isWater[x][y] + 1;
            sources.push({x, y - 1});
        }

        if(y < n && isWater[x][y + 1] < 0) {
            isWater[x][y + 1] = isWater[x][y] + 1;
            sources.push({x, y + 1});
        }
    }

    return isWater;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> isWater, vector<vector<int>> expected) {
    cout << "Is water:" << endl;
    printMatrix(isWater);

    cout << "Expected:" << endl;
    printMatrix(expected);

    cout << "Result:" << endl;
    printMatrix(highestPeak(isWater));

    cout << endl;
}

int main() {
    vector<vector<int>> input1 = {{0, 1}, {0, 0}};
    vector<vector<int>> expected1 = {{1, 0}, {2, 1}};
    test(input1, expected1);

    vector<vector<int>> input2 = {{0, 0, 1}, {1, 0, 0}, {0, 0, 0}};
    vector<vector<int>> expected2 = {{1, 1, 0}, {0, 1, 1}, {1, 2, 2}};
    test(input2, expected2);

    vector<vector<int>> input3 = {{1, 0, 0}, {0, 0, 0}, {0, 0, 1}};
    vector<vector<int>> expected3 = {{0, 1, 2}, {1, 2, 1}, {2, 1, 0}};
    test(input3, expected3);

    vector<vector<int>> input4 = {{1}};
    vector<vector<int>> expected4 = {{0}};
    test(input4, expected4);

    vector<vector<int>> input5 = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    vector<vector<int>> expected5 = {{2, 1, 2}, {1, 0, 1}, {2, 1, 2}};
    test(input5, expected5);

    vector<vector<int>> input6 = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vector<vector<int>> expected6 = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    test(input6, expected6);

    return 0;
}
