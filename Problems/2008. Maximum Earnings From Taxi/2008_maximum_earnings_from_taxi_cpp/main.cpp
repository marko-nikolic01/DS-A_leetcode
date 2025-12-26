#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
    long earnings = 0;
    vector<pair<int, long>> previousRides(1, {0, 0});
    short left;
    short right;
    short middle;

    sort(rides.begin(), rides.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] != b[1] ? a[1] > b[1] : a[0] > b[0];
    });

    for(short i = rides.size() - 1; i > -1; --i) {
        rides[i][2] += rides[i][1] - rides[i][0];
        n = previousRides.size();
        left = 0;
        right = --n;

        while(left <= right) {
            middle = (left + right) >> 1;

            if(previousRides[middle].first <= rides[i][0]) {
                if(middle == n || previousRides[middle + 1].first > rides[i][0]) {
                    break;
                }

                left = ++middle;
            } else {
                right = --middle;
            }
        }

        if(previousRides[middle].second + rides[i][2] > earnings) {
            earnings = previousRides[middle].second + rides[i][2];
        }

        if(rides[i][1] > previousRides[n].first) {
            previousRides.push_back({rides[i][1], earnings});
        } else {
            previousRides[n].second = earnings;
        }
    }

    return earnings;
}

void test(int n, vector<vector<int>> rides, long long expected) {
    cout << "n: " << n << endl;

    cout << "Rides: ";
    for(vector<int> ride : rides) {
        cout << "[" << ride[0] << ", " << ride[1] << ", " << ride[2] << "] ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxTaxiEarnings(n, rides) << endl;

    cout << endl;
}

int main() {
    test(5, {{2, 5, 4}, {1, 5, 1}}, 7);
    test(20, {{1, 6, 1}, {3, 10, 2}, {10, 12, 3}, {11, 12, 2}, {12, 15, 2}, {13, 18, 1}}, 20);
    test(10, {{1, 3, 5}, {3, 6, 5}, {6, 10, 5}}, 24);
    test(10, {{1, 10, 1}, {2, 3, 10}, {3, 5, 10}, {5, 7, 10}}, 35);
    test(15, {{2, 4, 3}, {4, 6, 3}, {6, 8, 3}, {1, 10, 15}}, 24);

    return 0;
}
