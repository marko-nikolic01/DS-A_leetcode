#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    vector<vector<pair<short, short>>> ranges(n, vector<pair<short, short>>(n, {0, 0}));
    short value;

    short i = queries.size();
    short j = queries.size();
    for(--i; i > -1; --i) {
        for(j = queries[i][0]; j <= queries[i][2]; ++j) {
            ++ranges[j][queries[i][1]].first;
            ++ranges[j][queries[i][3]].second;
        }
    }

    for(i = --n; i > -1; --i) {
        value = 0;

        for(j = n; j > -1; --j) {
            value += ranges[i][j].second;
            matrix[i][j] = value;
            value -= ranges[i][j].first;
        }
    }

    return matrix;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(int n, vector<vector<int>> queries, vector<vector<int>> expected) {
    cout << "n: " << n << endl;

    cout << "Queries: ";
    for(vector<int> query : queries) {
        cout << "[" << query[0] << ", " << query[1] << ", " << query[2] << ", " << query[3] << "] ";
    }
    cout << endl;

    cout << "Expected:" << endl;
    printMatrix(expected);

    cout << "Result:" << endl;
    printMatrix(rangeAddQueries(n, queries));

    cout << endl;
}

int main() {
    test(3, {{1, 1, 2, 2}, {0, 0, 1, 1}}, {{1, 1, 0}, {1, 2, 1}, {0, 1, 1}});
    test(2, {{0, 0, 1, 1}}, {{1, 1}, {1, 1}});
    test(4, {{0, 0, 0, 0}, {0, 0, 0, 0}, {3, 3, 3, 3}}, {{2, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 1}});
    test(5, {{2, 0, 2, 4}, {0, 3, 4, 3}}, {{0, 0, 0, 1, 0}, {0, 0, 0, 1, 0}, {1, 1, 1, 2, 1}, {0, 0, 0, 1, 0}, {0, 0, 0, 1, 0}});
    test(4, {{0, 0, 3, 3}, {1, 1, 2, 2}, {0, 1, 3, 2}}, {{1, 2, 2, 1}, {1, 3, 3, 1}, {1, 3, 3, 1}, {1, 2, 2, 1}});

    return 0;
}
