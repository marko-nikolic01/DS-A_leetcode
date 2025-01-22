#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    queue<pair<short, short>> sources;

    short x;
    short y;

    short m = mat.size();
    short n = mat[0].size();
    for(x = 0; x < m; ++x) {
        for(y = 0; y < n; ++y) {
            if(mat[x][y] < 1) {
                sources.push({x, y});
            } else {
                mat[x][y] = -1;
            }
        }
    }

    --m;
    --n;
    while(!sources.empty()) {
        tie(x, y) = sources.front();
        sources.pop();

        if(x > 0 && mat[x - 1][y] < 0) {
            mat[x - 1][y] = mat[x][y] + 1;
            sources.push({x - 1, y});
        }

        if(x < m && mat[x + 1][y] < 0) {
            mat[x + 1][y] = mat[x][y] + 1;
            sources.push({x + 1, y});
        }

        if(y > 0 && mat[x][y - 1] < 0) {
            mat[x][y - 1] = mat[x][y] + 1;
            sources.push({x, y - 1});
        }

        if(y < n && mat[x][y + 1] < 0) {
            mat[x][y + 1] = mat[x][y] + 1;
            sources.push({x, y + 1});
        }
    }

    return mat;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> mat, vector<vector<int>> expected) {
    cout << "Matrix:" << endl;
    printMatrix(mat);

    cout << "Expected:" << endl;
    printMatrix(expected);

    cout << "Result:" << endl;
    printMatrix(updateMatrix(mat));

    cout << endl;
}

int main() {
    vector<vector<int>> input1 = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    vector<vector<int>> expected1 = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    test(input1, expected1);

    vector<vector<int>> input2 = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    vector<vector<int>> expected2 = {{0, 0, 0}, {0, 1, 0}, {1, 2, 1}};
    test(input2, expected2);

    vector<vector<int>> input3 = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vector<vector<int>> expected3 = {{2, 1, 2}, {1, 0, 1}, {2, 1, 2}};
    test(input3, expected3);

    vector<vector<int>> input4 = {{0}};
    vector<vector<int>> expected4 = {{0}};
    test(input4, expected4);

    vector<vector<int>> input5 = {{1, 1, 1}, {0, 1, 0}, {1, 1, 1}};
    vector<vector<int>> expected5 = {{1, 2, 1}, {0, 1, 0}, {1, 2, 1}};
    test(input5, expected5);

    vector<vector<int>> input6 = {{1, 0, 1, 1}, {1, 1, 1, 0}, {1, 1, 1, 1}, {0, 1, 1, 1}};
    vector<vector<int>> expected6 = {{1, 0, 1, 1}, {2, 1, 1, 0}, {1, 2, 2, 1}, {0, 1, 2, 2}};
    test(input6, expected6);

    return 0;
}
