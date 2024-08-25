#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
    int a = 0;
    int b = nums.size() - 1;

    while (a <= b) {
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
    for (int n : nums) {
        cout << n << " ";
    }
    cout << endl;

    cout << "Target: " << target << endl;

    cout << "Expected: " << expected << endl;

    int result = search(nums, target);
    cout << "Result: " << result << endl;

    cout << endl;
}

int main() {
    runTest({-1, 0, 3, 5, 9, 12}, 9, 4);

    runTest({-1, 0, 3, 5, 9, 12}, 2, -1);

    runTest({1, 2, 3, 4, 5, 6}, 4, 3);

    runTest({2, 4, 6, 8, 10}, 8, 3);

    runTest({1, 3, 5, 7, 9, 11, 13, 15}, 11, 5);

    runTest({1, 3, 5, 7, 9}, 10, -1);

    return 0;
}
