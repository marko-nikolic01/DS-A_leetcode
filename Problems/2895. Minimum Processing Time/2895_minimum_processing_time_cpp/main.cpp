#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
    sort(processorTime.begin(), processorTime.end());
    sort(tasks.begin(), tasks.end(), greater<int>());

    int n = processorTime.size();

    int time = 0;

    for(int i = 0; i < n; ++i) {
        if(processorTime[i] + tasks[4 * i] > time) {
            time = processorTime[i] + tasks[4 * i];
        }
    }

    return time;
}

void testMinProcessingTime(vector<int>& processorTime, vector<int>& tasks, int expected) {
    cout << "Processor times: ";
    for (int time : processorTime) {
        cout << time << " ";
    }
    cout << endl;

    cout << "Tasks: ";
    for (int task : tasks) {
        cout << task << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minProcessingTime(processorTime, tasks) << endl;

    cout << endl;
}

int main() {
    vector<int> processorTime1 = {1, 3, 2};
    vector<int> tasks1 = {5, 2, 7, 3, 4, 6, 8, 2, 1, 9, 10, 11};
    testMinProcessingTime(processorTime1, tasks1, 12);

    vector<int> processorTime2 = {2, 1, 4, 3};
    vector<int> tasks2 = {10, 8, 7, 6, 5, 4, 3, 2, 1, 9, 12, 15};
    testMinProcessingTime(processorTime2, tasks2, 16);

    vector<int> processorTime3 = {5, 5, 5};
    vector<int> tasks3 = {3, 2, 1, 4, 6, 7, 8, 5, 10, 11, 12, 13};
    testMinProcessingTime(processorTime3, tasks3, 18);

    vector<int> processorTime4 = {1, 2, 3, 4};
    vector<int> tasks4 = {8, 7, 6, 5, 4, 3, 2, 1, 12, 11, 10, 9};
    testMinProcessingTime(processorTime4, tasks4, 13);

    vector<int> processorTime5 = {4, 3, 1};
    vector<int> tasks5 = {2, 5, 8, 4, 1, 3, 7, 6, 10, 12, 14, 9};
    testMinProcessingTime(processorTime5, tasks5, 15);

    vector<int> processorTime6 = {2, 2, 2, 2};
    vector<int> tasks6 = {12, 10, 9, 7, 4, 6, 3, 1, 8, 11, 5, 13};
    testMinProcessingTime(processorTime6, tasks6, 15);

    vector<int> processorTime7 = {6, 5, 4, 3};
    vector<int> tasks7 = {15, 12, 10, 11, 14, 9, 8, 7, 6, 5, 4, 3};
    testMinProcessingTime(processorTime7, tasks7, 18);

    vector<int> processorTime8 = {8, 10};
    vector<int> tasks8 = {2, 2, 3, 1, 8, 7, 4, 5};
    testMinProcessingTime(processorTime8, tasks8, 16);

    vector<int> processorTime9 = {10, 20};
    vector<int> tasks9 = {2, 3, 1, 2, 5, 8, 4, 3};
    testMinProcessingTime(processorTime9, tasks9, 23);

    return 0;
}
