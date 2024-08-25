#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int value = image[sr][sc];
    if(value == color) {
        return image;
    }

    queue<int> cells;
    cells.push(sr);
    cells.push(sc);

    int rows = image.size();
    int columns = image[0].size();

    image[sr][sc] = color;

    while(!cells.empty()) {
        sr = cells.front();
        cells.pop();

        sc = cells.front();
        cells.pop();

        if(sr > 0 && image[sr - 1][sc] == value) {
            image[sr - 1][sc] = color;
            cells.push(sr - 1);
            cells.push(sc);
        }

        if(sr < rows - 1 && image[sr + 1][sc] == value) {
            image[sr + 1][sc] = color;
            cells.push(sr + 1);
            cells.push(sc);
        }

        if(sc > 0 && image[sr][sc - 1] == value) {
            image[sr][sc - 1] = color;
            cells.push(sr);
            cells.push(sc - 1);
        }

        if(sc < columns - 1 && image[sr][sc + 1] == value) {
            image[sr][sc + 1] = color;
            cells.push(sr);
            cells.push(sc + 1);
        }
    }

    return image;
}

vector<vector<int>> floodFillRecursive(vector<vector<int>>& image, int sr, int sc, int color) {
    int value = image[sr][sc];
    if(value == color) {
        return image;
    }

    int rows = image.size();
    int columns = image[0].size();

    image[sr][sc] = color;

    if(sr > 0 && image[sr - 1][sc] == value) {
        floodFill(image, sr - 1, sc, color);
    }

    if(sr < rows - 1 && image[sr + 1][sc] == value) {
        floodFill(image, sr + 1, sc, color);
    }

    if(sc > 0 && image[sr][sc - 1] == value) {
        floodFill(image, sr, sc - 1, color);
    }

    if(sc < columns - 1 && image[sr][sc + 1] == value) {
        floodFill(image, sr, sc + 1, color);
    }

    return image;
}

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

void testFloodFill(const vector<vector<int>>& inputImage, int sr, int sc, int color, const vector<vector<int>>& expected, bool recursive) {
    vector<vector<int>> image = inputImage;
    vector<vector<int>> result = recursive ? floodFillRecursive(image, sr, sc, color) : floodFill(image, sr, sc, color);

    cout << "Image:" << endl;
    printMatrix(inputImage);
    cout << "Starting Point: (" << sr << ", " << sc << ")" << endl;
    cout << "Color: " << color << endl;

    cout << "Expected:" << endl;
    printMatrix(expected);

    cout << "Result:" << endl;
    printMatrix(result);
    cout << endl;
}

int main() {
    vector<vector<int>> image1 = {{1,1,1},{1,1,0},{1,0,1}};
    vector<vector<int>> expected1 = {{2,2,2},{2,2,0},{2,0,1}};

    vector<vector<int>> image2 = {{0,0,0},{0,1,0},{0,0,0}};
    vector<vector<int>> expected2 = {{0,0,0},{0,2,0},{0,0,0}};

    vector<vector<int>> image3 = {{1,1,1},{1,1,1},{1,1,1}};
    vector<vector<int>> expected3 = {{2,2,2},{2,2,2},{2,2,2}};

    vector<vector<int>> image4 = {{1,1,1},{1,1,1},{1,1,1}};
    vector<vector<int>> expected4 = {{1,1,1},{1,1,1},{1,1,1}};

    cout << "Iterative: " << endl << endl;
    testFloodFill(image1, 1, 1, 2, expected1, false);
    testFloodFill(image2, 1, 1, 2, expected2, false);
    testFloodFill(image3, 0, 0, 2, expected3, false);
    testFloodFill(image4, 0, 0, 1, expected4, false);
    cout << "---------------------------------------------------------" << endl;

    cout << "Recursive: " << endl << endl;
    testFloodFill(image1, 1, 1, 2, expected1, true);
    testFloodFill(image2, 1, 1, 2, expected2, true);
    testFloodFill(image3, 0, 0, 2, expected3, true);
    testFloodFill(image4, 0, 0, 1, expected4, true);

    return 0;
}
