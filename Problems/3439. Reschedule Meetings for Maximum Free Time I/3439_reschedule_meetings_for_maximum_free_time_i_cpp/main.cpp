#include <iostream>
#include <vector>

using namespace std;

int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
    int freeTime = 0;
    int time = 0;
    int left;
    int right;

    int n = startTime.size();
    for(int i = 0; i < n; ++i) {
        time += endTime[i] - startTime[i];
        left = i <= k - 1 ? 0 : endTime[i - k];
        right = i == n - 1 ? eventTime : startTime[i + 1];
        freeTime = max(freeTime, right - left - time);

        if (i >= k - 1) {
            time -= endTime[i - k + 1] - startTime[i - k + 1];
        }
    }

    return freeTime;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(int eventTime, int k, vector<int> startTime, vector<int> endTime, int expected) {
    cout << "Event time: " << eventTime << endl;

    cout << "k: " << k << endl;

    cout << "Start times: ";
    printArray(startTime);

    cout << "End times: ";
    printArray(endTime);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxFreeTime(eventTime, k, startTime, endTime) << endl;

    cout << endl;
}

int main() {
    test(5, 1, {1, 3}, {2, 5}, 2);
    test(10, 1, {0, 2, 9}, {1, 4, 10}, 6);
    test(5, 2, {0, 1, 2, 3, 4}, {1, 2, 3, 4, 5}, 0);
    test(10, 3, {1, 2, 3}, {2, 4, 5}, 5);
    test(8, 2, {0, 1, 7}, {1, 2, 8}, 5);

    return 0;
}
