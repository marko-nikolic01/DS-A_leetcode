#include <iostream>
#include <vector>

using namespace std;

int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
    short maxArea = 0;
    short maxDiagonal = 0;
    short diagonal;

    for(short i = dimensions.size() - 1; i > -1; --i) {
        diagonal = dimensions[i][0] * dimensions[i][0] + dimensions[i][1] * dimensions[i][1];

        if(diagonal > maxDiagonal) {
            maxArea = dimensions[i][0] * dimensions[i][1];
            maxDiagonal = diagonal;
        } else if(diagonal == maxDiagonal && dimensions[i][0] * dimensions[i][1] > maxArea) {
            maxArea = dimensions[i][0] * dimensions[i][1];
        }
    }

    return maxArea;
}

void test(vector<vector<int>> dimensions, int expected) {
    cout << "Dimensions: ";
    for(vector<int> dimension : dimensions) {
        cout << "[" << dimension[0] << ", " << dimension[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << areaOfMaxDiagonal(dimensions) << endl;

    cout << endl;
}

int main() {
    test({{9, 3}, {8, 6}}, 48);
    test({{3, 4}, {4, 3}}, 12);
    test({{100, 100}, {100, 99}}, 10000);
    test({{5, 12}}, 60);
    test({{6, 8}, {10, 0}, {8, 6}}, 48);

    return 0;
}
