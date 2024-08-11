#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
    if(numRows == 0) {
        return {};
    } else if(numRows == 1) {
        return {{1}};
    }

    vector<vector<int>> triangle =  generate(numRows - 1);
    int n = triangle.size() - 1;
    vector<int> row = {1};
    for(int i = 1; i < numRows - 1; ++i) {
        row.push_back(triangle[n][i - 1] + triangle[n][i]);
    }
    row.push_back(1);
    triangle.push_back(row);

    return triangle;
}

void printTriangle(const vector<vector<int>>& triangle) {
    for (const auto& row : triangle) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> expected = {{1}, {1, 1}, {1, 2, 1}, {1, 3, 3, 1}, {1, 4, 6, 4, 1}};
    vector<vector<int>> result = generate(5);

    cout << "Expected:" << endl;
    printTriangle(expected);

    cout << "Result:" << endl;
    printTriangle(result);

    return 0;
}
