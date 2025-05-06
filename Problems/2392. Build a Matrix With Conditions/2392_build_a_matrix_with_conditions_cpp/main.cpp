#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
    vector<vector<int>> matrix(k, vector<int>(k, 0));

    vector<vector<short>> dependencies(k);
    vector<short> conditions(k, 0);

    short i;
    for(i = colConditions.size() - 1; i > -1; --i) {
        dependencies[--colConditions[i][1]].push_back(--colConditions[i][0]);
        ++conditions[colConditions[i][0]];
    }

    short nextTraversal = 0;
    for(i = k - 1; i > -1; --i) {
        if(conditions[i] < 1) {
            matrix[0][nextTraversal++] = i;
        }
    }

    vector<short> columns(k);
    short current = k;

    short iTraversal = 0;
    short nTraversal = nextTraversal;
    while(iTraversal < nTraversal) {
        columns[matrix[0][iTraversal]] = --current;

        for(i = dependencies[matrix[0][iTraversal]].size() - 1; i > -1; --i) {
            if(--conditions[dependencies[matrix[0][iTraversal]][i]] < 1) {
                matrix[0][nextTraversal++] = dependencies[matrix[0][iTraversal]][i];
                ++nTraversal;
            }
        }

        dependencies[matrix[0][iTraversal]].resize(0);
        matrix[0][iTraversal++] = 0;
    }

    if(nTraversal < k) {
        return {};
    }

    for(i = rowConditions.size() - 1; i > -1; --i) {
        dependencies[--rowConditions[i][1]].push_back(--rowConditions[i][0]);
        ++conditions[rowConditions[i][0]];
    }

    nextTraversal = 0;
    for(i = k - 1; i > -1; --i) {
        if(conditions[i] < 1) {
            matrix[0][nextTraversal++] = i;
        }
    }

    current = k--;

    iTraversal = 0;
    nTraversal = nextTraversal;
    while(iTraversal < nTraversal && iTraversal < k) {
        matrix[--current][columns[matrix[0][iTraversal]]] = matrix[0][iTraversal] + 1;

        for(i = dependencies[matrix[0][iTraversal]].size() - 1; i > -1; --i) {
            if(--conditions[dependencies[matrix[0][iTraversal]][i]] < 1) {
                matrix[0][nextTraversal++] = dependencies[matrix[0][iTraversal]][i];
                ++nTraversal;
            }
        }

        matrix[0][iTraversal++] = 0;
    }

    if(nTraversal < k) {
        return {};
    }

    current = matrix[0][iTraversal];
    matrix[0][iTraversal] = 0;
    matrix[0][columns[current]] = current + 1;

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

void test(int k, vector<vector<int>> rowConditions, vector<vector<int>> colConditions, vector<vector<int>> expected) {
    cout << "k: " << k << endl;

    cout << "Row conditions: ";
    for(vector<int> rowCondition : rowConditions) {
        cout << "[" << rowCondition[0] << ", " << rowCondition[1] << "] ";
    }
    cout << endl;

    cout << "Column conditions: ";
    for(vector<int> colCondition : colConditions) {
        cout << "[" << colCondition[0] << ", " << colCondition[1] << "] ";
    }
    cout << endl;

    cout << "Expected:" << endl;
    printMatrix(expected);

    cout << "Result:" << endl;
    printMatrix(buildMatrix(k, rowConditions, colConditions));

    cout << endl;
}

int main() {
    vector<vector<int>> row1 = {{1, 2}, {3, 2}};
    vector<vector<int>> col1 = {{2, 1}, {3, 2}};
    vector<vector<int>> expected1 = {
        {3, 0, 0},
        {0, 0, 1},
        {0, 2, 0}
    };
    test(3, row1, col1, expected1);

    vector<vector<int>> row2 = {{1, 2}, {2, 3}, {3, 1}};
    vector<vector<int>> col2 = {{2, 1}};
    vector<vector<int>> expected2 = {};
    test(3, row2, col2, expected2);

    vector<vector<int>> row3 = {{1, 2}};
    vector<vector<int>> col3 = {{1, 2}};
    vector<vector<int>> expected3 = {
        {1, 0},
        {0, 2}
    };
    test(2, row3, col3, expected3);

    vector<vector<int>> row4 = {
        {1,2},{7,3},{4,3},{5,8},{7,8},{8,2},{5,8},{3,2},{1,3},
        {7,6},{4,3},{7,4},{4,8},{7,3},{7,5}
    };
    vector<vector<int>> col4 = {
        {5,7},{2,7},{4,3},{6,7},{4,3},{2,3},{6,2}
    };
    vector<vector<int>> expected4 = {
        {0, 0, 0, 0, 0, 0, 7, 0},
        {0, 0, 4, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 5, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 3, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 8},
        {0, 2, 0, 0, 0, 0, 0, 0},
        {6, 0, 0, 0, 0, 0, 0, 0}
    };
    test(8, row4, col4, expected4);

    vector<vector<int>> row5 = {{1, 2}};
    vector<vector<int>> col5 = {{1, 2}, {2, 3}, {3, 1}};
    vector<vector<int>> expected5 = {};
    test(3, row5, col5, expected5);

    return 0;
}
