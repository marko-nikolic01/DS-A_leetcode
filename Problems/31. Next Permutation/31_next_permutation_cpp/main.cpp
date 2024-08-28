#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size() - 1;

    for(n; n > 0; --n) {
        if(nums[n] > nums[n - 1]) {
            break;
        }
    }

    if(n == 0) {
        sort(nums.begin(), nums.end());
        return;
    }

    int min = n;

    int m = nums.size();
    for(int i = n + 1; i < m; ++i) {
        if(nums[i] < nums[min] && nums[i] > nums[n - 1]) {
            min = i;
        }
    }

    int temp = nums[n - 1];
    nums[n - 1] = nums[min];
    nums[min] = temp;

    sort(nums.begin() + n, nums.end());
}

void runTest(vector<int> nums, vector<int> expected) {
    cout << "Input: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    nextPermutation(nums);

    cout << "Expected: ";
    for (int num : expected) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Result: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    runTest({1, 2, 3}, {1, 3, 2});

    runTest({3, 2, 1}, {1, 2, 3});

    runTest({1, 1, 5}, {1, 5, 1});

    runTest({1, 3, 2}, {2, 1, 3});

    runTest({1}, {1});

    return 0;
}
