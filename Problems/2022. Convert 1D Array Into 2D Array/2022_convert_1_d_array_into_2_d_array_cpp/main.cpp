#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
    int nOriginal = original.size();

    if(nOriginal != m * n) {
        return {};
    }

    vector<vector<int>> matrix (m, vector<int> (n--));

    for(--m; m > -1; --m) {
        int temp = n;
        for(n; n > -1; --n) {
            matrix[m][n] = original[--nOriginal];
        }
        n = temp;
    }

    return matrix;
}

void print2DArray(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

void testCase(vector<int>& original, int m, int n, const vector<vector<int>>& expected) {
    cout << "1D array: ";
    for (int val : original) {
        cout << val << " ";
    }
    cout << endl;

    cout << "m = " << m << endl;

    cout << "n = " << n << endl;

    cout << "Expected:" << endl;
    print2DArray(expected);

    cout << "Result:" << endl;
    print2DArray(construct2DArray(original, m, n));

    cout << endl;
}

int main() {
    vector<int> original1 = {1, 2, 3, 4, 5, 6};
    vector<vector<int>> expected1 = {{1, 2}, {3, 4}, {5, 6}};
    testCase(original1, 3, 2, expected1);

    vector<int> original2 = {1, 2, 3, 4, 5, 6};
    vector<vector<int>> expected2 = {};
    testCase(original2, 2, 4, expected2);

    vector<int> original3 = {1, 2, 3, 4};
    vector<vector<int>> expected3 = {{1, 2, 3, 4}};
    testCase(original3, 1, 4, expected3);

    vector<int> original4 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<vector<int>> expected4 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    testCase(original4, 3, 3, expected4);

    vector<int> original5 = {1};
    vector<vector<int>> expected5 = {{1}};
    testCase(original5, 1, 1, expected5);

    vector<int> original6 = {1};
    vector<vector<int>> expected6 = {};
    testCase(original6, 1, 2, expected6);

    return 0;
}
