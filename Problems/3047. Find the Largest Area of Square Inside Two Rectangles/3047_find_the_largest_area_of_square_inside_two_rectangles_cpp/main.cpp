#include <iostream>
#include <vector>

using namespace std;

long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
    int maxSide = 0;
    int width;
    int height;

    short j;
    short n = bottomLeft.size();
    for(short i = 0; i < n; ++i) {
        for(j = i + 1; j < n; ++j) {
            width = min(topRight[i][0], topRight[j][0]) - max(bottomLeft[i][0], bottomLeft[j][0]);
            height = min(topRight[i][1], topRight[j][1]) - max(bottomLeft[i][1], bottomLeft[j][1]);
            maxSide = max(maxSide, min(width, height));
        }
    }

    return (long)maxSide * maxSide;
}

void test(vector<vector<int>> bottomLeft, vector<vector<int>> topRight, long long expected) {
    cout << "Bottom lefts: ";
    for(vector<int> bl : bottomLeft) {
        cout << "[" << bl[0] << ", " << bl[1] << "] ";
    }
    cout << endl;

    cout << "Top rights: ";
    for(vector<int> tr : topRight) {
        cout << "[" << tr[0] << ", " << tr[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << largestSquareArea(bottomLeft, topRight) << endl;

    cout << endl;
}

int main() {
    test({{1, 1}, {2, 2}, {3, 1}}, {{3, 3}, {4, 4}, {6, 6}}, 1);
    test({{1, 1}, {1, 3}, {1, 5}}, {{5, 5}, {5, 7}, {5, 9}}, 4);
    test({{1, 1}, {2, 2}, {1, 2}}, {{3, 3}, {4, 4}, {3, 4}}, 1);
    test({{1, 1}, {3, 3}, {3, 1}}, {{2, 2}, {4, 4}, {4, 2}}, 0);
    test({{1, 1}, {2, 2}, {1, 1}, {2, 1}}, {{5, 5}, {4, 4}, {3, 3}, {5, 2}}, 4);

    return 0;
}
