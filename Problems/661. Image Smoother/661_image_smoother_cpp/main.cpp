#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
    int x = img.size();
    int y = img[0].size();

    vector<vector<int>> smooth = img;

    for(int i = 0; i < x; ++i) {
        for(int j = 0; j < y; ++j) {
            int sum = img[i][j];
            int count = 1;

            if(j > 0) {
                sum += img[i][j - 1];
                count++;
            }

            if(j < y - 1) {
                sum += img[i][j + 1];
                count++;
            }

            if(i > 0) {
                sum += img[i - 1][j];
                count++;

                if(j > 0) {
                    sum += img[i - 1][j - 1];
                    count++;
                }

                if(j < y - 1) {
                    sum += img[i - 1][j + 1];
                    count++;
                }
            }

            if(i < x - 1) {
                sum += img[i + 1][j];
                count++;

                if(j > 0) {
                    sum += img[i + 1][j - 1];
                    count++;
                }

                if(j < y - 1) {
                    sum += img[i + 1][j + 1];
                    count++;
                }
            }

            smooth[i][j] = sum / count;
        }
    }

    return smooth;
}

void printImage(const vector<vector<int>>& img) {
    for (const auto& row : img) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> img1 = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    vector<vector<int>> expected1 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    cout << "Test Case 1:" << endl;
    cout << "Image:" << endl;
    printImage(img1);

    vector<vector<int>> result1 = imageSmoother(img1);

    cout << "Expected:" << endl;
    printImage(expected1);

    cout << "Result:" << endl;
    printImage(result1);
    cout << endl;

    vector<vector<int>> img2 = {
        {100, 200, 100},
        {200, 50, 200},
        {100, 200, 100}
    };

    vector<vector<int>> expected2 = {
        {137, 141, 137},
        {141, 138, 141},
        {137, 141, 137}
    };

    cout << "Test Case 2:" << endl;
    cout << "Image:" << endl;
    printImage(img2);

    vector<vector<int>> result2 = imageSmoother(img2);

    cout << "Expected:" << endl;
    printImage(expected2);

    cout << "Result:" << endl;
    printImage(result2);

    return 0;
}
