#include <iostream>
#include <vector>

using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    for(int i = triangle.size() - 2; i > -1; --i) {
        for(int j = i; j > -1; --j) {
            triangle[i][j] += triangle[i + 1][j] < triangle[i + 1][j + 1] ? triangle[i + 1][j] : triangle[i + 1][j + 1];
        }
    }

    return triangle[0][0];
}

void printTriangle(const vector<vector<int>>& triangle) {
    for (const auto& row : triangle) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

void runTest(vector<vector<int>> triangle, int expected) {
    cout << "Triangle:" << endl;
    printTriangle(triangle);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minimumTotal(triangle) << endl;

    cout << endl;
}

int main() {
    vector<vector<int>> triangle1 = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };
    runTest(triangle1, 11);

    vector<vector<int>> triangle2 = {
        {-10}
    };
    runTest(triangle2, -10);

    vector<vector<int>> triangle3 = {
        {1},
        {2, 3},
        {3, 6, 7},
        {4, 5, 6, 7}
    };
    runTest(triangle3, 10);

    vector<vector<int>> triangle4 = {
        {1},
        {1, 2},
        {1, 2, 3},
        {1, 2, 3, 4}
    };
    runTest(triangle4, 4);

    vector<vector<int>> triangle5 = {
        {1},
        {1, 2},
        {2, 1, 3},
        {4, 2, 1, 3},
        {4, 1, 5, 2, 3}
    };
    runTest(triangle5, 6);

    return 0;
}
