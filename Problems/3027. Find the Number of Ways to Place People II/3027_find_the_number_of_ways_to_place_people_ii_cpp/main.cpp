#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int numberOfPairs(vector<vector<int>>& points) {
    sort(points.begin(), points.end());

    short n = points.size();
    vector<pair<int, short>> vertical(n);

    short i;
    for(i = --n; i > -1; --i) {
        vertical[i] = {points[i][1], i};
    }

    sort(vertical.begin(), vertical.end());

    short pairs = 0;
    short leftI;
    short rightI;
    bool isPairValid;

    short j;
    short k;
    for(i = n; i > 0; --i) {
        for(j = i - 1; j > -1; --j) {
            if(vertical[i].first != vertical[j].first && points[vertical[i].second][0] > points[vertical[j].second][0]) {
                continue;
            }

            isPairValid = true;

            if(vertical[i].second < vertical[j].second) {
                leftI = vertical[i].second;
                rightI = vertical[j].second;
            } else {
                leftI = vertical[j].second;
                rightI = vertical[i].second;
            }

            for(k = leftI - 1; isPairValid && k > -1 && points[k][0] == points[leftI][0]; --k) {
                if(points[k][1] >= vertical[j].first && points[k][1] <= vertical[i].first) {
                    isPairValid = false;
                    break;
                }
            }

            for(k = rightI + 1; isPairValid && k <= n && points[k][0] == points[rightI][0]; ++k) {
                if(points[k][1] >= vertical[j].first && points[k][1] <= vertical[i].first) {
                    isPairValid = false;
                    break;
                }
            }

            for(++leftI; isPairValid && leftI < rightI; ++leftI) {
                if(points[leftI][1] >= vertical[j].first && points[leftI][1] <= vertical[i].first) {
                    isPairValid = false;
                    break;
                }
            }

            if(isPairValid) {
                ++pairs;
            }
        }
    }

    return pairs;
}

void test(vector<vector<int>> points, int expected) {
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
    test({{3, 5}, {6, 3}, {6, 0}}, 2);
    test({{1, 4}, {4, 1}, {2, 2}}, 2);

    return 0;
}
