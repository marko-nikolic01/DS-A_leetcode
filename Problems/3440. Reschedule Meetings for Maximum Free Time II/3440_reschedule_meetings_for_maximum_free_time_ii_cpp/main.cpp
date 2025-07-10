#include <iostream>
#include <vector>

using namespace std;

int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
    int freeTime = 0;

    int left;
    int right;
    int t1 = 0;
    int t2 = 0;

    int n = startTime.size();
    for(int i = 0; i < n; ++i) {
        left = i == 0 ? 0 : endTime[i - 1];
        right = i == n - 1 ? eventTime : startTime[i + 1];

        if(endTime[i] - startTime[i] <= t1) {
            freeTime = max(freeTime, right - left);
        }

        t1 = max(t1, startTime[i] - (i == 0 ? 0 : endTime[i - 1]));
        freeTime = max(freeTime, right - left - (endTime[i] - startTime[i]));

        left = i == n - 1 ? 0 : endTime[n - i - 2];
        right = i == 0 ? eventTime : startTime[n - i];

        if(endTime[n - i - 1] - startTime[n - i - 1] <= t2) {
            freeTime = max(freeTime, right - left);
        }

        t2 = max(t2, (i == 0 ? eventTime : startTime[n - i]) - endTime[n - i - 1]);
    }

    return freeTime;
}


void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(int eventTime, vector<int> startTime, vector<int> endTime, int expected) {
    cout << "Event time: " << eventTime << endl;

    cout << "Start times: ";
    printArray(startTime);

    cout << "End times: ";
    printArray(endTime);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxFreeTime(eventTime, startTime, endTime) << endl;

    cout << endl;
}


int main() {
    test(5, {1, 3}, {2, 5}, 2);
    test(10, {0, 7, 9}, {1, 8, 10}, 7);
    test(10, {0, 3, 7, 9}, {1, 4, 8, 10}, 6);
    test(5, {0, 1, 2, 3, 4}, {1, 2, 3, 4, 5}, 0);
    test(12, {1, 4, 8, 11}, {2, 5, 9, 12}, 6);

    return 0;
}
