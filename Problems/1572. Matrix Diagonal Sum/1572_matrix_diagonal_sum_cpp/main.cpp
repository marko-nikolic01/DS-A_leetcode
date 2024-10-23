#include <iostream>
#include <vector>

using namespace std;

int diagonalSum(vector<vector<int>>& mat) {
    int n = mat.size();

    int sum = n % 2 == 0 ? 0 : -mat[n / 2][n / 2];

    for(int i = 0; i < n; ++i) {
        sum += mat[i][i] + mat[i][n - i - 1];
    }

    return sum;
}

void printMatrix(const vector<vector<int>>& mat) {
    for (const auto& row : mat) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>>& mat, int expected) {
    cout << "Matrix:" << endl;
    printMatrix(mat);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << diagonalSum(mat) << endl;

    cout << endl;
}

int main()
{
    vector<vector<int>> mat1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    test(mat1, 25);

    vector<vector<int>> mat2 = {
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1}
    };
    test(mat2, 8);

    vector<vector<int>> mat3 = {
        {5}
    };
    test(mat3, 5);

    vector<vector<int>> mat4 = {
        {1, 2},
        {3, 4}
    };
    test(mat4, 10);

    return 0;
}
