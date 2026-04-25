#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool maxDistance(vector<long>& arr, long& limit, int& side, int& k) {
    long end;
    long cur;

    short j;
    vector<long>::iterator it;
    short n = arr.size();
    for(short i = 0; i < n; ++i) {
        end = arr[i] + ((long)side << 2) - limit;
        cur = arr[i];

        for(j = k; j > 0; --j) {
            it = ranges::lower_bound(arr, cur + limit);

            if(it == arr.end() || *it > end) {
                cur = -1;

                break;
            }

            cur = *it;
        }

        if(cur >= 0) {
            return true;
        }
    }

    return false;
}

int maxDistance(int side, vector<vector<int>>& points, int k) {
    vector<long> arr;
    long lo = 1;
    long hi = side;
    long mid;
    int ans = 0;

    short n = points.size();
    for(short i = 0; i < n; ++i) {
        if(points[i][0] == 0) {
            arr.push_back(points[i][1]);
        } else if(points[i][1] == side) {
            arr.push_back(side + points[i][0]);
        } else if(points[i][0] == side) {
            arr.push_back((long)3 * side - points[i][1]);
        } else {
            arr.push_back((long)4 * side - points[i][0]);
        }
    }

    sort(arr.begin(), arr.end());

    --k;
    while(lo <= hi) {
        mid = (lo + hi) >> 1;

        if(maxDistance(arr, mid, side, k)) {
            lo = mid + 1;
            ans = mid;
        } else {
            hi = mid - 1;
        }
    }

    return ans;
}

void test(int side, vector<vector<int>> points, int k, int expected) {
    cout << "Side: " << side << endl;

    cout << "Points: ";
    for(vector<int> point : points) {
        cout << "[" << point[0] << ", " << point[1] << "] ";
    }
    cout << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxDistance(side, points, k) << endl;

    cout << endl;
}

int main() {
    test(2, {{0, 2}, {2, 0}, {2, 2}, {0, 0}}, 4, 2);
    test(2, {{0, 0}, {1, 2}, {2, 0}, {2, 2}, {2, 1}}, 4, 1);
    test(2, {{0, 0}, {0, 1}, {0, 2}, {1, 2}, {2, 0}, {2, 2}, {2, 1}}, 5, 1);
    test(10, {{0, 0}, {10, 0}, {10, 10}, {0, 10}}, 2, 10);
    test(3, {{0, 0}, {1, 0}, {2, 0}, {3, 0}}, 2, 3);

    return 0;
}
