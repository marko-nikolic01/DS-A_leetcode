#include <iostream>
#include <vector>

using namespace std;

int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    vector<int> rows(m, n);
    vector<int> columns(n, m);

    vector<int> locations(m * n);

    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            locations[--mat[i][j]] = i * n + j;
        }
    }

    m *= n;
    for(int i = 0; i < m; ++i) {
        if(--rows[locations[--arr[i]] / n] < 1 || --columns[locations[arr[i]] % n] < 1) {
            return i;
        }
    }

    return 0;
}

void printMatrix(vector<vector<int>>& matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void runTest(vector<int>& arr, vector<vector<int>>& mat, int expected) {
    cout << "Array: ";
    for(int a : arr) {
        cout << a << " ";
    }
    cout << endl;

    cout << "Matrix:" << endl;
    printMatrix(mat);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << firstCompleteIndex(arr, mat) << endl;

    cout << endl;
}

int main() {
    vector<int> arr1 = {1, 3, 4, 2};
    vector<vector<int>> mat1 = {{1, 4}, {2, 3}};
    runTest(arr1, mat1, 2);

    vector<int> arr2 = {2, 8, 7, 4, 1, 3, 5, 6, 9};
    vector<vector<int>> mat2 = {{3, 2, 5}, {1, 4, 6}, {8, 7, 9}};
    runTest(arr2, mat2, 3);

    vector<int> arr3 = {5, 1, 2, 3, 4, 6};
    vector<vector<int>> mat3 = {{1, 2}, {3, 4}, {5, 6}};
    runTest(arr3, mat3, 2);

    vector<int> arr4 = {9, 6, 3, 8, 5, 2, 7, 4, 1};
    vector<vector<int>> mat4 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    runTest(arr4, mat4, 2);

    vector<int> arr5 = {4, 1, 2, 3};
    vector<vector<int>> mat5 = {{1, 2}, {3, 4}};
    runTest(arr5, mat5, 2);

    return 0;
}
