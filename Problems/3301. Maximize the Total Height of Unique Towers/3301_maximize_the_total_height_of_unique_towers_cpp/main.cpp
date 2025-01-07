#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long maximumTotalSum(vector<int>& maximumHeight) {
    sort(maximumHeight.begin(), maximumHeight.end());

    long heightSum = maximumHeight.back();
    int heightCap = heightSum;

    int i = maximumHeight.size() - 2;
    for(i; i > -1 && heightCap > 1; --i) {
        if(maximumHeight[i] < heightCap) {
            heightCap = maximumHeight[i];
            heightSum += heightCap;
        } else {
            heightSum += --heightCap;
        }
    }

    return i < 0 ? heightSum : -1;
}

void test(vector<int> maximumHeight, long long expected) {
    cout << "Maximum heights: ";
    for (int maxHeight : maximumHeight) {
        cout << maxHeight << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maximumTotalSum(maximumHeight) << endl;

    cout << endl;
}

int main() {
    test({2, 3, 4, 3}, 10);
    test({15, 10}, 25);
    test({2, 2, 1}, -1);
    test({5, 5, 5, 5, 5}, 15);
    test({1, 1, 1, 1}, -1);

    return 0;
}
