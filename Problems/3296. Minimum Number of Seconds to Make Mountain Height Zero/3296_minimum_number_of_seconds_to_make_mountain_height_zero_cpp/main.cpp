#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
    long seconds = 0;
    int maxWorkerTimes = *max_element(workerTimes.begin(), workerTimes.end());
    long l = 1;
    long r = (long)maxWorkerTimes * mountainHeight * (mountainHeight + 1) >> 1;
    long middle;
    long count;
    long work;

    int i;
    int n = workerTimes.size();
    while(l <= r) {
        middle = (l + r) >> 1;
        count = 0;

        for(i = 0; i < n; ++i) {
            count += (-1.0 + sqrt(1 + (middle / workerTimes[i]) * 8)) / 2 + 0.000000001;
        }

        if(count >= mountainHeight) {
            seconds = middle;
            r = --middle;
        } else {
            l = ++middle;
        }
    }

    return seconds;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(int mountainHeight, vector<int> workerTimes, int expected) {
    cout << "Mountain height: " << mountainHeight << endl;

    cout << "Worker times: ";
    printArray(workerTimes);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minNumberOfSeconds(mountainHeight, workerTimes) << endl;

    cout << endl;
}

int main() {
    test(4, {2, 1, 1}, 3);
    test(10, {3, 2, 2, 4}, 12);
    test(5, {1}, 15);
    test(1, {1000000}, 1000000);
    test(6, {1, 1, 1}, 3);

    return 0;
}
