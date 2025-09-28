#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> windowMaximums(n - k + 1);
    priority_queue<pair<short, int>> window;
    int iMaximum = 0;

    int i;
    for(i = 0; i < k; ++i) {
        window.push({nums[i], i});
    }

    windowMaximums[0] = window.top().first;

    for(i; i < n; ++i) {
        window.push({nums[i], i});

        while(window.top().second <= i - k) {
            window.pop();
        }

        windowMaximums[++iMaximum] = window.top().first;
    }

    return windowMaximums;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int k, vector<int> expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "k: " << k << endl;

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(maxSlidingWindow(nums, k));

    cout << endl;
}

int main() {
    test({1, 3, -1, -3, 5, 3, 6, 7}, 3, {3, 3, 5, 5, 6, 7});
    test({1}, 1, {1});
    test({9, 11}, 2, {11});
    test({4, -2}, 1, {4, -2});
    test({1, 3, 1, 2, 0, 5}, 3, {3, 3, 2, 5});

    return 0;
}
