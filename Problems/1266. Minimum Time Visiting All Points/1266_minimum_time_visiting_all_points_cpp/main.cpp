#include <iostream>
#include <vector>

using namespace std;

int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int time = 0;

    for(short i = points.size() - 2; i > -1; --i) {
        time += max(abs(points[i][0] - points[i + 1][0]), abs(points[i][1] - points[i + 1][1]));
    }

    return time;
}

void test(vector<vector<int>> points, int expected) {
    cout << "Points: ";
    for(vector<int> point : points) {
        cout << "[" << point[0] << ", " << point[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minTimeToVisitAllPoints(points) << endl;

    cout << endl;
}

int main() {
    test({{1, 1}, {3, 4}, {-1, 0}}, 7);
    test({{3, 2}, {-2, 2}}, 5);
    test({{0, 0}, {0, 0}}, 0);
    test({{0, 0}, {1, 1}, {2, 2}, {3, 3}}, 3);
    test({{-5, -5}, {-3, -2}, {0, 0}, {2, -1}}, 8);

    return 0;
}
