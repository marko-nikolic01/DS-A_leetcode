#include <iostream>
#include <vector>

using namespace std;

void colorTheGrid(vector<vector<short>>& columns, vector<short>& column, int& m, short& i) {
    if(i == m) {
        columns.push_back(column);
    } else {
        for(short color = 0; color < 3; ++color) {
            if(i < 1 || column[i - 1] != color) {
                column[i] = color;
                colorTheGrid(columns, column, m, ++i);
            }
        }
    }

    --i;
}

void colorTheGrid(vector<int>& ways, vector<int>& previousWays, vector<vector<short>>& previousValidColumns, short& n) {
    short i;
    for(i = 0; i < n; ++i) {
        ways[i] = 0;
    }

    short j;
    for(i = 0; i < n; ++i) {
        for(j = previousValidColumns[i].size() - 1; j > -1; --j) {
            ways[i] = (ways[i] + previousWays[previousValidColumns[i][j]]) % 1000000007;
        }
    }
}

int colorTheGrid(vector<int>& ways, short& n) {
    int wayCount = 0;

    for(--n; n > -1; --n) {
        wayCount = (wayCount + ways[n]) % 1000000007;
    }

    return wayCount;
}

int colorTheGrid(int m, int n) {
    vector<vector<short>> columns;
    vector<short> column(m);

    short i = 0;
    colorTheGrid(columns, column, m, i);

    short nColumns = columns.size();
    vector<vector<short>> previousValidColumns(nColumns--);
    bool isPrevious;

    short j;
    short k;
    for(i = 0; i < nColumns; ++i) {
        for(j = i + 1; j <= nColumns; ++j) {
            isPrevious = true;

            for(k = 0; k < m; ++k) {
                isPrevious &= columns[i][k] != columns[j][k];
            }

            if(isPrevious) {
                previousValidColumns[i].push_back(j);
                previousValidColumns[j].push_back(i);
            }
        }
    }

    vector<int> ways(++nColumns);
    vector<int> previousWays(nColumns, 1);
    isPrevious = true;

    while(--n > 0) {
        if(isPrevious) {
            colorTheGrid(ways, previousWays, previousValidColumns, nColumns);
        } else {
            colorTheGrid(previousWays, ways, previousValidColumns, nColumns);
        }

        isPrevious = !isPrevious;
    }

    return isPrevious ? colorTheGrid(previousWays, nColumns) : colorTheGrid(ways, nColumns);
}

void runTest(int m, int n, int expected) {
    cout << "m: " << m << endl;

    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << colorTheGrid(m, n) << endl;

    cout << endl;
}

int main() {
    runTest(1, 1, 3);
    runTest(1, 2, 6);
    runTest(2, 1, 6);
    runTest(2, 2, 18);
    runTest(5, 5, 580986);

    return 0;
}
