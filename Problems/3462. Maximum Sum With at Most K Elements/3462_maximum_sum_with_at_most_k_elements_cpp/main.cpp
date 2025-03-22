#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
    vector<pair<int, short>> elements;

    int i = 0;
    short m = grid.size();
    long n = grid[0].size() - 1;
    for(--m; m > -1; --m) {
        for(i = n; i > -1; --i) {
            elements.push_back({grid[m][i], m});
        }
    }

    sort(elements.begin(), elements.end(), [](const pair<int, short>& a, const pair<int, short>& b) {
        return a.first > b.first;
    });

    i = -1;
    n = 0;

    while(k > 0) {
        if(--limits[elements[++i].second] > -1) {
            n += elements[i].first;

            --k;
        }
    }

    return n;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> grid, vector<int> limits, int k, int expected) {
    cout << "Matrix:" << endl;
    printMatrix(grid);

    cout << "Limits: ";
    printArray(limits);

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxSum(grid, limits, k) << endl;

    cout << endl;
}

int main() {
    test({{1, 2}, {3, 4}}, {1, 2}, 2, 7);
    test({{5, 3, 7}, {8, 2, 6}}, {2, 2}, 3, 21);
    test({{10, 20}, {30, 40}}, {0, 2}, 2, 70);
    test({{5, 2}, {4, 6}}, {2, 2}, 2, 11);
    test({{1, 2}, {3, 4}}, {1, 1}, 2, 6);

    return 0;
}
