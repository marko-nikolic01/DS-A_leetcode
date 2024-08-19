#include <iostream>
#include <vector>

using namespace std;

int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    int n = timeSeries.size();

    int poisonDuration = duration;

    for(int i = 1; i < n; ++i) {
        poisonDuration += duration;
        if(timeSeries[i] - timeSeries[i - 1] < duration) {
            poisonDuration -= duration - timeSeries[i] + timeSeries[i - 1];
        }
    }

    return poisonDuration;
}


void runTestCase(vector<int> timeSeries, int duration, int expected) {
    int result = findPoisonedDuration(timeSeries, duration);
    cout << "Time Series: [";
    for(int i = 0; i < timeSeries.size(); ++i) {
        cout << timeSeries[i];
        if(i < timeSeries.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    cout << "Duration: " << duration << endl;
    cout << "Expected: " << expected << endl;
    cout << "Result: " << result << endl;
    cout << endl << endl;
}

int main() {
    runTestCase({1, 4}, 2, 4);
    runTestCase({1, 2}, 2, 3);
    runTestCase({1, 2, 3, 4, 5}, 5, 9);
    runTestCase({1, 10}, 4, 8);
    runTestCase({17}, 2, 2);

    return 0;
}
