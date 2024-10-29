#include <iostream>
#include <vector>

using namespace std;

int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
    int distance = 10000;
    int point = -1;

    for(int i = points.size() - 1; i > -1; --i) {
        if(points[i][0] == x) {
            points[i][0] = abs(points[i][1] - y);
            if(points[i][0] <= distance) {
                distance = points[i][0];
                point = i;
            }
        } else if(points[i][1] == y) {
            points[i][0] = abs(points[i][0] - x);
            if(points[i][0] <= distance) {
                distance = points[i][0];
                point = i;
            }
        }
    }

    return point;
}

void test(int x, int y, vector<vector<int>> points, int expected) {
    cout << "Points: [";
    for (auto& point : points) {
        cout << "[" << point[0] << ", " << point[1] << "] ";
    }
    cout << "]" << endl;

    cout << "x: " << x << endl;

    cout << "y: " << y << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << nearestValidPoint(x, y, points) << endl;

    cout << endl;
}

int main() {
    test(3, 4, {{1, 2}, {3, 2}, {3, 4}}, 2);
    test(3, 4, {{3, 4}, {3, 5}, {2, 4}}, 0);
    test(3, 4, {{2, 3}, {3, 3}, {4, 4}}, 1);
    test(3, 4, {{1, 2}, {2, 3}, {4, 5}}, -1);
    test(3, 4, {{3, 7}, {3, 5}, {3, 6}, {1, 4}, {4, 4}}, 1);

    return 0;
}
