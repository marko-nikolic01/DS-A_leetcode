#include <iostream>
#include <vector>

using namespace std;

int minimumDeletions(vector<int>& nums) {
    int min = 0;
    int max = 0;

    int n = nums.size();
    for(int i = 0; i < n; ++i) {
        if(nums[i] < nums[min]) {
            min = i;
        }

        if(nums[i] > nums[max]) {
            max = i;
        }
    }

    if(max < min) {
        int temp = min;
        min = max;
        max = temp;
    }

    int deletions = max + 1;

    if(n - min < deletions) {
        deletions = n - min;
    }

    if(min + 1 + n - max < deletions) {
        deletions = min + 1 + n - max;
    }

    return deletions;
}

void runTest(vector<int> nums, int expected) {
    cout << "Input: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minimumDeletions(nums) << endl;

    cout << endl;
}

int main() {
    runTest({1, 2, 3, 4, 5}, 2);
    runTest({5, 1, 2, 3, 4}, 2);
    runTest({3, 1, 4, 2, 5}, 3);
    runTest({1}, 1);
    runTest({1, 2, 3}, 2);

    return 0;
}
