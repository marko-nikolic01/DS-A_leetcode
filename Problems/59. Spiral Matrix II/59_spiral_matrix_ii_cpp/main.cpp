#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));

    int minX = 0;
    int maxX = n;
    int minY = -1;
    int maxY = n - 1;

    int stepX = 0;
    int stepY = 1;

    int number = 1;

    int x = 0;
    int y = -1;

    while(number <= n * n) {
        x += stepX;
        y += stepY;

        matrix[x][y] = number++;

        if(x == minX && y == maxY) {
            stepX++;
            stepY--;
            maxX--;
        } else if(x == maxX && y == maxY) {
            stepX--;
            stepY--;
            minY++;
        } else if(x == maxX && y == minY) {
            stepX--;
            stepY++;
            minX++;
        } else if(x == minX && y == minY) {
            stepX++;
            stepY++;
            maxY--;
        }
    }

    return matrix;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& num : row) {
            cout << num << "\t";
        }
        cout << endl;
    }
}

void testGenerateMatrix(int n) {
    cout << "n = " << n << endl;
    vector<vector<int>> result = generateMatrix(n);
    printMatrix(result);
    cout << endl;
}

int main() {
    testGenerateMatrix(1);

    testGenerateMatrix(2);

    testGenerateMatrix(3);

    testGenerateMatrix(4);

    testGenerateMatrix(5);

    return 0;
}
