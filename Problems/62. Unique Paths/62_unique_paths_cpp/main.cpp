#include <iostream>
#include <vector>

using namespace std;

int uniquePaths(int m, int n) {
    vector<int> paths(m * n);

    paths[m * n - 1] = 1;
    for(int i = 1; i < m; ++i) {
        paths[m * n - i - 1] = paths[m * n - i];
    }

    for(int i = 1; i < n; ++i) {
        paths[(n - i) * m - 1] = paths[(n - i + 1) * m - 1];

        for (int j = 1; j < m; ++j) {
            paths[(n - i) * m - j - 1] = paths[(n - i) * m - j] + paths[(n - i + 1) * m - j - 1];
        }
    }

    return paths[0];
}

void runTest(int m, int n, int expected) {
    cout << "m: " << m << endl;

    cout << "n: " << n << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << uniquePaths(m, n) << endl;

    cout << endl;
}

int main() {
    runTest(3, 7, 28);
    runTest(3, 2, 3);
    runTest(7, 3, 28);
    runTest(3, 3, 6);
    runTest(1, 1, 1);
    runTest(2, 2, 2);

    return 0;
}
