#include <iostream>
#include <vector>


using namespace std;

vector<vector<int>> generate(int rowNum) {
    if(rowNum == 0) {
        return {};
    }

    if(rowNum == 1) {
        return {{1}};
    }

    vector<vector<int>> triangle = generate(rowNum - 1);
    int n = triangle.size() - 1;
    vector<int> row = {1};
    for(int i = 1; i < rowNum - 1; ++i) {
        row.push_back(triangle[n][i - 1] + triangle[n][i]);
    }
    row.push_back(1);
    triangle.push_back(row);

    return triangle;
}

vector<int> getRow(int rowIndex) {
    vector<vector<int>> triangle = generate(rowIndex + 1);
    int n = triangle.size();

    if(n == 0) {
        return {};
    }
    return triangle[--n];
}

void printTestCase(int rowIndex, const vector<int>& expected) {
    vector<int> result = getRow(rowIndex);

    cout << "Test case for row " << rowIndex << ":" << endl;
    cout << "Expected: ";
    for (int val : expected) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Result: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    cout << (result == expected ? "PASS" : "FAIL") << endl;
    cout << "------------------------" << endl;
}

int main() {
    printTestCase(0, {1});
    printTestCase(1, {1, 1});
    printTestCase(2, {1, 2, 1});
    printTestCase(3, {1, 3, 3, 1});
    printTestCase(4, {1, 4, 6, 4, 1});
    printTestCase(5, {1, 5, 10, 10, 5, 1});

    return 0;
}
