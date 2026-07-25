#include <iostream>
#include <vector>

using namespace std;

vector<string> createGrid(int m, int n) {
    vector<string> grid(m, string(n--, '#'));

    while(--m > -1) {
        grid[m][n] = '.';
    }

    while(n > -1) {
        grid[0][n--] = '.';
    }

    return grid;
}

void printMatrix(vector<string> matrix) {
    for(string row : matrix) {
        for(char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(int m, int n, vector<string> expected) {
    cout << "m: " << m << endl;

    cout << "n: " << n << endl;

    cout << "Expected:" << endl;
    printMatrix(expected);

    cout << "Result:" << endl;
    printMatrix(createGrid(m, n));

    cout << endl;
}

int main() {
    test(2, 3, {"...", "##."});
    test(3, 3, {"...", "##.", "##."});
    test(1, 4, {"...."});
    test(4, 1, {".", ".", ".", "."});
    test(4, 5, {".....", "####.", "####.", "####."});

    return 0;
}
