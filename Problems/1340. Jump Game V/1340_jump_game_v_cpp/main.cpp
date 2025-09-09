#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxJumps(vector<int>& arr, int d) {
    int n = arr.size();
    vector<short> leftFirstGreatest(n);
    vector<short> rightFirstGreatest(n);
    vector<short> firstGreatest;

    short i;
    for(i = 0; i < n; ++i) {
        while(!firstGreatest.empty()) {
            if(arr[firstGreatest.back()] >= arr[i] || firstGreatest.back() < i - d) {
                break;
            }

            firstGreatest.pop_back();
        }

        leftFirstGreatest[i] = firstGreatest.empty() ? max(i - d, 0) : max(firstGreatest.back() + 1, i - d);

        firstGreatest.push_back(i);
    }

    firstGreatest.resize(0);

    for(i = --n; i > -1; --i) {
        while(!firstGreatest.empty()) {
            if(arr[firstGreatest.back()] >= arr[i] || firstGreatest.back() > i + d) {
                break;
            }

            firstGreatest.pop_back();
        }

        rightFirstGreatest[i] = firstGreatest.empty() ? min(i + d, n) : min(firstGreatest.back() - 1, i + d);

        firstGreatest.push_back(i);
    }

    vector<pair<int, short>> sortedHeights(++n);

    for(i = 0; i < n; ++i) {
        sortedHeights[i] = {arr[i], i};
    }

    sort(sortedHeights.begin(), sortedHeights.end());

    vector<short> jumps(n, 1);
    short maxJumps = 1;

    for(--n; n > -1; --n) {
        i = sortedHeights[n].second;
        if(++jumps[i] > maxJumps && leftFirstGreatest[i] < rightFirstGreatest[i]) {
            maxJumps = jumps[i];
        }

        for(leftFirstGreatest[i]; leftFirstGreatest[i] <= rightFirstGreatest[i]; ++leftFirstGreatest[i]) {
            if(jumps[i] > jumps[leftFirstGreatest[i]]) {
                jumps[leftFirstGreatest[i]] = jumps[i];
            }
        }
    }

    return maxJumps;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> arr, int d, int expected) {
    cout << "Array: ";
    printArray(arr);

    cout << "d: " << d << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxJumps(arr, d) << endl;

    cout << endl;
}

int main() {
    test({6, 4, 14, 6, 8, 13, 9, 7, 10, 6, 12}, 2, 4);
    test({3, 3, 3, 3, 3}, 3, 1);
    test({7, 6, 5, 4, 3, 2, 1}, 1, 7);
    test({40, 98, 14, 22, 45, 71, 20, 19, 26, 9, 29, 64, 76, 66, 32, 79, 14, 83, 62, 39, 69, 25, 92, 79, 70, 34, 22, 19, 41, 26, 5, 82, 38}, 6, 9);
    test({1, 3, 2}, 2, 2);

    return 0;
}
