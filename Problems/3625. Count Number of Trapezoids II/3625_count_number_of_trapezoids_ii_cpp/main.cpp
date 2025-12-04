#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

int countTrapezoids(vector<vector<int>>& points) {
    int trapezoids = 0;
    unordered_map<float, vector<float>> slopeToIntercept;
    unordered_map<int, vector<float>> middleToSlope;
    map<float, int> count;
    int dx;
    int dy;
    float k;
    float b;
    int middle;
    int sum;

    int j;
    int n = points.size();
    for(int i = 0; i < n; ++i) {
        for(j = i + 1; j < n; ++j) {
            dx = points[i][0] - points[j][0];
            dy = points[i][1] - points[j][1];

            if(points[j][0] == points[i][0]) {
                k = 1000000007;
                b = points[i][0];
            } else {
                k = (float)(points[j][1] - points[i][1]) / (points[j][0] - points[i][0]);
                b = (float)(points[i][1] * dx - points[i][0] * dy) / dx;
            }

            middle = (points[i][0] + points[j][0]) * 10000 + (points[i][1] + points[j][1]);
            slopeToIntercept[k].push_back(b);
            middleToSlope[middle].push_back(k);
        }
    }

    map<float, int>::iterator jt;
    for(unordered_map<float, vector<float>>::iterator it = slopeToIntercept.begin(); it != slopeToIntercept.end(); ++it) {
        if(it->second.size() == 1) {
            continue;
        }

        sum = 0;
        count.clear();

        for(j = it->second.size() - 1; j > -1; --j) {
            ++count[it->second[j]];
        }

        for(jt = count.begin(); jt != count.end(); ++jt) {
            trapezoids += sum * jt->second;
            sum += jt->second;
        }
    }

    for(unordered_map<int, vector<float>>::iterator it = middleToSlope.begin(); it != middleToSlope.end(); ++it) {
        if(it->second.size() == 1) {
            continue;
        }

        sum = 0;
        count.clear();

        for(j = it->second.size() - 1; j > -1; --j) {
            ++count[it->second[j]];
        }

        for(jt = count.begin(); jt != count.end(); ++jt) {
            trapezoids -= sum * jt->second;
            sum += jt->second;
        }
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
    test({{-3, 2}, {3, 0}, {2, 3}, {3, 2}, {2, -3}}, 2);
    test({{0, 0}, {1, 0}, {0, 1}, {2, 1}}, 1);
    test({{1, 0}, {2, 0}, {3, 0}, {2, 2}, {3, 2}}, 3);
    test({{0, 0}, {1, 0}, {0, 1}, {2, 1}}, 1);
    test({{0, 0}, {1, 1}, {2, 2}, {3, 3}}, 0);
    test({{1, 0}, {2, 0}, {3, 0}, {1, 5}, {2, 5}, {3, 5}}, 9);
    test({{0, 0}, {3, 0}, {1, 1}, {2, 1}, {3, 1}, {0, 2}, {4, 2}}, 10);

    return 0;
}
