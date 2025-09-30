#include <iostream>
#include <vector>

using namespace std;

void numOfWays(vector<int>& ways, vector<int>& previousWays, vector<vector<short>>& previousValidRows) {
    short i;
    for(i = 0; i < 12; ++i) {
        ways[i] = 0;
    }

    short j;
    for(i = 0; i < 12; ++i) {
        for(j = previousValidRows[i].size() - 1; j > -1; --j) {
            ways[i] = (ways[i] + previousWays[previousValidRows[i][j]]) % 1000000007;
        }
    }
}

int numOfWays(vector<int>& ways) {
    int wayCount = 0;

    short i;
    for(i = 0; i < 12; ++i) {
        wayCount = (wayCount + ways[i]) % 1000000007;
    }

    return wayCount;
}

int numOfWays(int n) {
    vector<vector<short>> previousValidRows {
        {1, 2, 4, 5, 10},
        {0, 3, 6, 8, 11},
        {0, 3, 6, 7},
        {1, 2, 7, 10},
        {0, 6, 8, 9},
        {0, 6, 7, 9, 10},
        {1, 2, 4, 5, 11},
        {2, 3, 5, 11},
        {1, 4, 9, 10},
        {4, 5, 8, 11},
        {0, 3, 5, 8, 11},
        {1, 6, 7, 9, 10}
    };
    vector<int> ways(12);
    vector<int> previousWays(12, 1);
    bool iteration = true;

    while(--n > 0) {
        if(iteration) {
            numOfWays(ways, previousWays, previousValidRows);
        } else {
            numOfWays(previousWays, ways, previousValidRows);
        }

        iteration = !iteration;
    }

    return iteration ? numOfWays(previousWays) : numOfWays(ways);
}

void printMatrix(vector<vector<short>> matrix) {
    for(vector<short> row : matrix) {
        for(short cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(int n, int expected) {
    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numOfWays(n) << endl;

    cout << endl;
}

int main() {
    test(1, 12);
    test(5000, 30228214);
    test(2, 54);
    test(3, 246);
    test(7, 106494);

    return 0;
}
