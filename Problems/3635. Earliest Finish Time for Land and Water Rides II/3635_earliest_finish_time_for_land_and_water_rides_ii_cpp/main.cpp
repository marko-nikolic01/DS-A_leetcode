#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
    int earliestLand = INT_MAX;
    int earliestWater = INT_MAX;
    int earliestLandWater = INT_MAX;

    unsigned short i;
    unsigned short nLand = landStartTime.size();
    unsigned short nWater = waterStartTime.size();
    for(i = 0; i < nLand; ++i) {
        if(landStartTime[i] + landDuration[i] < earliestLand) {
            earliestLand = landStartTime[i] + landDuration[i];
        }
    }

    for(i = 0; i < nWater; ++i) {
        if(waterStartTime[i] + waterDuration[i] < earliestWater) {
            earliestWater = waterStartTime[i] + waterDuration[i];
        }

        if(waterStartTime[i] < earliestLand) {
            waterStartTime[i] = earliestLand;
        }

        if(waterStartTime[i] + waterDuration[i] < earliestLandWater) {
            earliestLandWater = waterStartTime[i] + waterDuration[i];
        }
    }

    for(i = 0; i < nLand; ++i) {
        if(landStartTime[i] < earliestWater) {
            landStartTime[i] = earliestWater;
        }

        if(landStartTime[i] + landDuration[i] < earliestLandWater) {
            earliestLandWater = landStartTime[i] + landDuration[i];
        }
    }

    return earliestLandWater;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> landStartTime, vector<int> landDuration, vector<int> waterStartTime, vector<int> waterDuration, int expected) {
    cout << "Land ride start times: ";
    printArray(landStartTime);

    cout << "Land ride durations: ";
    printArray(landDuration);

    cout << "Water ride start times: ";
    printArray(waterStartTime);

    cout << "Water ride durations: ";
    printArray(waterDuration);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration) << endl;

    cout << endl;
}

int main() {
    test({2, 8}, {4, 1}, {6}, {3}, 9);
    test({5}, {3}, {1}, {10}, 14);
    test({4}, {3}, {1, 3}, {20, 2}, 8);
    test({1}, {2}, {10}, {5}, 15);
    test({1, 1}, {1, 10}, {1, 1}, {1, 10}, 3);

    return 0;
}
