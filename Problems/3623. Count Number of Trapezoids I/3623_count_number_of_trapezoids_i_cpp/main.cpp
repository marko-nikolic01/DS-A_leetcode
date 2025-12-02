#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int countTrapezoids(vector<vector<int>>& points) {
    unordered_map<int, int> horizontals;
    int trapezoids = 0;
    long pairs = 0;
    long currentPairs;

    for(pairs = points.size() - 1; pairs > -1; --pairs) {
        ++horizontals[points[pairs][1]];
    }

    ++pairs;
    for(unordered_map<int, int>::iterator it = horizontals.begin(); it != horizontals.end(); ++it) {
        currentPairs = ((long)it->second * (it->second - 1)) >> 1;
        trapezoids = (trapezoids + pairs * currentPairs) % 1000000007;
        pairs += currentPairs;
    }

    return trapezoids;
}

void test(vector<vector<int>> points, int expected) {
    cout << "Points: ";
    for(vector<int> point : points) {
        cout << "[" << point[0] << ", " << point[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countTrapezoids(points) << endl;

    cout << endl;
}

int main() {
    test({{1, 0}, {2, 0}, {3, 0}, {2, 2}, {3, 2}}, 3);
    test({{0, 0}, {1, 0}, {0, 1}, {2, 1}}, 1);
    test({{0, 0}, {1, 1}, {2, 2}, {3, 3}}, 0);
    test({{1, 0}, {2, 0}, {3, 0}, {1, 5}, {2, 5}, {3, 5}}, 9);
    test({{0, 0}, {3, 0}, {1, 1}, {2, 1}, {3, 1}, {0, 2}, {4, 2}}, 7);

    return 0;
}

