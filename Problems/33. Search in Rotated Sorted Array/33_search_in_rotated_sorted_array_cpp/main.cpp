#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
    int a = 0;
    int b = nums.size() - 1;

    if(nums[a] > nums[b]) {
        int middle;
        while(a <= b) {
            int c = (a + b) / 2;
            if(nums[c] < nums[0]) {
                middle = c;
                b = --c;
            } else {
                a = ++c;
            }
        }

        if(nums[middle] <= target && nums[nums.size() - 1] >= target) {
            a = middle;
            b = nums.size() - 1;
        } else {
            b = middle - 1;
            a = 0;
        }
    }

    while(a <= b) {
        int c = (a + b) / 2;

        if(nums[c] == target) {
            return c;
        } else if(nums[c] > target) {
            b = --c;
        } else {
            a = ++c;
        }
    }

    return -1;
}

void runTest(vector<int> nums, int target, int expected) {
    cout << "Input: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Target: " << target << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << search(nums, target) << endl;

    cout << endl;
}

int main() {
    runTest({4, 5, 6, 7, 0, 1, 2}, 0, 4);

    runTest({4, 5, 6, 7, 0, 1, 2}, 3, -1);

    runTest({4, 5, 6, 7, 0, 1, 2}, 0, 4);

    runTest({4, 5, 6, 7, 0, 1, 2}, 7, 3);

    runTest({1, 2, 3, 4, 5, 6, 7}, 5, 4);

    runTest({1}, 1, 0);

    runTest({1}, 0, -1);

    return 0;
}
