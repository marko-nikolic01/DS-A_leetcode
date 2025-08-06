#include <iostream>
#include <vector>

using namespace std;

int maxCollectedFruits(vector<vector<int>>& fruits) {
    int collectedFruits = 0;

    short i;
    short n = fruits.size();
    for(i = 0; i < n; ++i) {
        collectedFruits += fruits[i][i];
        fruits[i][i] = 0;
    }

    short boundary;
    short previousBoundary = --n;
    short nextBoundary;
    int previousFruits;

    for(i = 1; i <= n; ++i) {
        boundary = max<short>(i, n - i);
        nextBoundary = boundary;

        for(boundary; boundary <= n; ++boundary) {
            previousFruits = 0;

            if(boundary - 1 >= previousBoundary && fruits[boundary - 1][i - 1] > previousFruits) {
                previousFruits = fruits[boundary - 1][i - 1];
            }

            if(boundary >= previousBoundary && fruits[boundary][i - 1] > previousFruits) {
                previousFruits = fruits[boundary][i - 1];
            }

            if(boundary < n && fruits[boundary + 1][i - 1] > previousFruits) {
                previousFruits = fruits[boundary + 1][i - 1];
            }

            fruits[boundary][i] += previousFruits;
        }

        previousBoundary = nextBoundary;
    }

    collectedFruits += fruits[n][n];
    previousBoundary = n;

    for(i = n >> 1; i <= n; ++i) {
        fruits[i][i] = 0;
    }

    for(i = 1; i <= n; ++i) {
        boundary = max<short>(i, n - i);
        nextBoundary = boundary;

        for(boundary; boundary <= n; ++boundary) {
            previousFruits = 0;

            if(boundary - 1 >= previousBoundary && fruits[i - 1][boundary - 1] > previousFruits) {
                previousFruits = fruits[i - 1][boundary - 1];
            }

            if(boundary >= previousBoundary && fruits[i - 1][boundary] > previousFruits) {
                previousFruits = fruits[i - 1][boundary];
            }

            if(boundary < n && fruits[i - 1][boundary + 1] > previousFruits) {
                previousFruits = fruits[i - 1][boundary + 1];
            }

            fruits[i][boundary] += previousFruits;
        }

        previousBoundary = nextBoundary;
    }

    collectedFruits += fruits[n][n];

    return collectedFruits;
}

void printMatrix(vector<vector<int>> matrix) {
    for(vector<int> row : matrix) {
        for(int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
}

void test(vector<vector<int>> fruits, int expected) {
    cout << "Fruits:" << endl;
    printMatrix(fruits);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxCollectedFruits(fruits) << endl;

    cout << endl;
}

int main() {
    test({{1, 2, 3, 4}, {5, 6, 8, 7}, {9, 10, 11, 12}, {13, 14, 15, 16}}, 100);
    test({{1, 1}, {1, 1}}, 4);
    test({{8, 9, 9, 7, 1}, {12, 18, 16, 13, 12}, {8, 13, 1, 5, 13}, {10, 13, 14, 13, 2}, {20, 0, 6, 5, 3}}, 124);
    test({{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, 0);
    test({{0, 0, 0}, {0, 0, 0}, {0, 0, 99}}, 99);

    return 0;
}
