#include <iostream>
#include <vector>

using namespace std;

int maxCount(int m, int n, vector<vector<int>>& ops) {
    int minX = 0;
    int minY = 0;

    int size = ops.size();
    if(size == 0) {
        return m * n;
    }

    for(int i = 0; i < size; ++i) {
        if(minX == 0 || ops[i][0] < minX) {
            minX = ops[i][0];
        }

        if(minY == 0 || ops[i][1] < minY) {
            minY = ops[i][1];
        }
    }

    return minX * minY;
}

void runTestCase(int m, int n, vector<vector<int>> ops, int expected) {
    int result = maxCount(m, n, ops);

    // Print the matrix dimensions
    cout << "Matrix dimensions: " << m << " x " << n << endl;

    // Print operations
    cout << "Operations: [";
    for (size_t i = 0; i < ops.size(); ++i) {
        cout << "[" << ops[i][0] << ", " << ops[i][1] << "]";
        if (i < ops.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    cout << "Expected: " << expected << endl;
    cout << "Result: " << result << endl;
    cout << endl;
}

int main() {
    cout << "Test Cases:\n";

    runTestCase(3, 3, {{2, 2}, {3, 3}}, 4);
    runTestCase(3, 3, {{2, 2}, {2, 2}}, 4);
    runTestCase(3, 3, {}, 9);
    runTestCase(5, 4, {{3, 3}, {2, 2}}, 4);
    runTestCase(5, 5, {{1, 4}, {4, 1}}, 1);

    return 0;
}
