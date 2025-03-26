#include <iostream>
#include <vector>

using namespace std;

bool carPooling(vector<vector<int>>& trips, int capacity) {
    vector<int> capacityChanges(1001, 0);

    short i = trips.size();
    for(--i; i > -1; --i) {
        capacityChanges[trips[i][1]] -= trips[i][0];
        capacityChanges[trips[i][2]] += trips[i][0];
    }

    for(i = 0; i < 1001; ++i) {
        capacity += capacityChanges[i];

        if(capacity < 0) {
            return false;
        }
    }

    return true;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<vector<int>> trips, int capacity, bool expected) {
    cout << "Trips: ";
    for(vector<int> trip : trips) {
        cout << "[" << trip[0] << ", " << trip[1] << ", " << trip[2] << "] ";
    }
    cout << endl;

    cout << "Capacity: " << capacity << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (carPooling(trips, capacity) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test({{2, 1, 5}, {3, 3, 7}}, 4, false);
    test({{2, 1, 5}, {3, 3, 7}}, 5, true);
    test({{9, 0, 1}, {3, 3, 7}}, 4, false);
    test({{5, 2, 8}, {3, 3, 7}, {4, 5, 9}}, 10, false);
    test({{1, 0, 5}, {2, 2, 7}, {3, 3, 8}}, 6, true);
    test({{1, 0, 2}, {1, 1, 3}, {1, 2, 4}}, 2, true);

    return 0;
}
