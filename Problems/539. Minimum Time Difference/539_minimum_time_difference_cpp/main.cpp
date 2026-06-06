#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMinDifference(vector<string>& timePoints) {
    short n = timePoints.size();
    vector<short> times(n);

    short i;
    for(i = --n; i > -1; --i) {
        times[i] = 60 * (10 * (timePoints[i][0] - '0') + timePoints[i][1] - '0') + 10 * (timePoints[i][3] - '0') + timePoints[i][4] - '0';
    }

    sort(times.begin(), times.end());
    i = 1440 - times[n] + times[0];

    while(--n > -1) {
        if(times[n + 1] - times[n] < i) {
            i = times[n + 1] - times[n];
        }
    }

    return i;
}

void printArray(vector<string> array) {
    for(string a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<string> timePoints, int expected) {
    cout << "Time points: ";
    printArray(timePoints);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << findMinDifference(timePoints) << endl;

    cout << endl;
}

int main() {
    test({"23:59", "00:00"}, 1);
    test({"00:00", "23:59", "00:00"}, 0);
    test({"01:01", "02:01", "03:00"}, 59);
    test({"05:31", "22:08", "00:35"}, 147);
    test({"12:30", "12:31", "12:32", "12:33"}, 1);

    return 0;
}
