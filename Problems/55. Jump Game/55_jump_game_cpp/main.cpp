#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int>& nums) {
    int maxJump = 0;

    int n = nums.size();
    for(int i = 0; i < n - 1; ++i) {
        if(nums[i] >= --maxJump) {
            maxJump = nums[i];
        }

        if(maxJump == 0) {
            return false;
        } else if(i + maxJump > n - 2) {
            return true;
        }
    }

    return true;
}

void runTest(vector<int>& nums, bool expected) {
    cout << "Input: ";
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result:   " << (canJump(nums) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    vector<int> test1 = {2, 3, 1, 1, 4};
    runTest(test1, true);

    vector<int> test2 = {3, 2, 1, 0, 4};
    runTest(test2, false);

    vector<int> test3 = {0};
    runTest(test3, true);

    vector<int> test4 = {2, 0, 0};
    runTest(test4, true);

    vector<int> test5 = {1, 1, 0, 1};
    runTest(test5, false);

    return 0;
}
