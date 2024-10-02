#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
    int n = image[0].size();

    for(int i = image.size() - 1; i > -1; --i) {
        for(int j = 0; j < n / 2; ++j) {
            int temp = image[i][j];
            image[i][j] = image[i][n - j - 1] ^ 1;
            image[i][n - j - 1] = temp ^ 1;
        }
    }

    if(n % 2 == 1) {
        for(int i = image.size() - 1; i > -1; --i) {
            image[i][n / 2] = image[i][n / 2] ^ 1;
        }
    }

    return image;
}

void printImage(const vector<vector<int>>& image) {
    for (const auto& row : image) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

void testFlipAndInvertImage(vector<vector<int>> image, const vector<vector<int>>& expected) {
    cout << "Input:" << endl;
    printImage(image);

    cout << "Expected:" << endl;
    printImage(expected);

    cout << "Result:" << endl;
    printImage(flipAndInvertImage(image));

    cout << endl;
}

int main() {
    vector<vector<int>> image1 = {{1, 1, 0}, {1, 0, 1}, {0, 0, 0}};
    vector<vector<int>> expected1 = {{1, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    testFlipAndInvertImage(image1, expected1);

    vector<vector<int>> image2 = {{1, 1, 1}, {1, 0, 0}, {0, 1, 1}};
    vector<vector<int>> expected2 = {{0, 0, 0}, {1, 1, 0}, {0, 0, 1}};
    testFlipAndInvertImage(image2, expected2);

    vector<vector<int>> image3 = {{1}};
    vector<vector<int>> expected3 = {{0}};
    testFlipAndInvertImage(image3, expected3);

    vector<vector<int>> image4 = {{1, 0}, {0, 1}};
    vector<vector<int>> expected4 = {{1, 0}, {0, 1}};
    testFlipAndInvertImage(image4, expected4);

    vector<vector<int>> image5 = {{1, 0, 0}, {0, 1, 1}, {1, 1, 0}};
    vector<vector<int>> expected5 = {{1, 1, 0}, {0, 0, 1}, {1, 0, 0}};
    testFlipAndInvertImage(image5, expected5);

    return 0;
}
