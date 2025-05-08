#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
    int n = plantTime.size();
    vector<int> sorted(n);

    int i;
    for(i = --n; i > -1; --i) {
        sorted[i] = i;
    }

    sort(sorted.begin(), sorted.end(), [&](int a, int b) {
        return growTime[a] < growTime[b];
    });

    int time = -1;
    i = -1;

    for(n; n > -1; --n) {
        i += plantTime[sorted[n]];
        time = max(time, i + ++growTime[sorted[n]]);
    }

    return time;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> plantTime, vector<int> growTime, int expected) {
    cout << "Plant times: ";
    printArray(plantTime);

    cout << "Grow times: ";
    printArray(growTime);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << earliestFullBloom(plantTime, growTime) << endl;

    cout << endl;
}


int main() {
    test({1, 4, 3}, {2, 3, 1}, 9);
    test({1, 2, 3, 2}, {2, 1, 2, 1}, 9);
    test({1}, {1}, 2);
    test({2, 2, 2}, {2, 2, 2}, 8);
    test({3, 1, 2}, {1, 3, 2}, 7);

    return 0;
}
