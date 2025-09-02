#include <iostream>
#include <vector>

using namespace std;

int numberOfPairs(vector<vector<int>>& points) {
    short pairs = 0;
    bool valid;

    short j;
    short k;
    short n = points.size();
    for(short i = n - 1; i > -1; --i) {
        for(j = n - 1; j > -1; --j) {
            if(i == j || !(points[i][0] <= points[j][0] && points[i][1] >= points[j][1])) {
                continue;
            }

            if(n == 2) {
                ++pairs;
                continue;
            }

            valid = true;

            for(k = n - 1; k > -1; --k) {
                if(k == i || k == j) {
                    continue;
                }

                if(points[k][0] >= points[i][0] && points[k][0] <= points[j][0] && points[k][1] <= points[i][1] && points[k][1] >= points[j][1]) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                ++pairs;
            }
        }
    }
    return pairs;
}

void test(vector<vector<int>> points, double expected) {
    cout << "Points: ";
    for(vector<int> point : points) {
        cout << "[" << point[0] << ", " << point[1] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << numberOfPairs(points) << endl;

    cout << endl;
}

int main() {
    test({{1, 1}, {2, 2}, {3, 3}}, 0);
    test({{6, 2}, {4, 4}, {2, 6}}, 2);
    test({{3, 1}, {1, 3}, {1, 1}}, 2);
    test({{0, 0}, {0, 1}, {1, 0}, {1, 1}}, 4);
    test({{5, 5}, {3, 3}, {2, 6}, {6, 2}}, 4);

    return 0;
}
