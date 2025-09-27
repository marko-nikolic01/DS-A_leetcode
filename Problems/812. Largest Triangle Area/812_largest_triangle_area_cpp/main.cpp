#include <iostream>
#include <vector>

using namespace std;

double largestTriangleArea(vector<vector<int>>& points) {
    double maxArea = 0;
    double area;

    short j;
    short k;
    short n = points.size();
    for(short i = --n; i > 1; --i) {
        for(j = i - 1; j > 0; --j) {
            for(k = j - 1; k > -1; --k) {
                area = abs(points[i][0] * (points[j][1] - points[k][1]) + points[j][0] * (points[k][1] - points[i][1]) + points[k][0] * (points[i][1] - points[j][1])) / 2.;

                if(area > maxArea) {
                    maxArea = area;
                }
            }
        }
    }

    return maxArea;
}

void test(vector<vector<int>> points, double expected) {
    cout << "Points: ";
    for(vector<int> point : points) {
        cout << "[" << point[0] << " " << point[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << largestTriangleArea(points) << endl;

    cout << endl;
}

int main() {
    test({{0, 0}, {0, 1}, {1, 0}, {0, 2}, {2, 0}}, 2);
    test({{1, 0}, {0, 0}, {0, 1}}, 0.5);
    test({{4, 6}, {6, 5}, {3, 1}}, 5.5);
    test({{0, 0}, {1, 1}, {2, 2}}, 0);
    test({{0, 0}, {0, 10}, {10, 0}}, 50);

    return 0;
}
