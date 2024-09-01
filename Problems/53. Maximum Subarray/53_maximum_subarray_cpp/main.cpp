#include <iostream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int n =  nums.size() - 1;

    int sum = 0;
    int maxSum = nums[n];

    for(n; n > -1; --n) {
        if(sum < 0) {
            sum = 0;
        }

        sum += nums[n];

        if(sum > maxSum) {
            maxSum = sum;
        }
    }

    return maxSum;
}

void runTest(vector<int> nums, int expected) {
    cout << "Input: [";
    for(int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if(i < nums.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxSubArray(nums) << endl;

    cout << endl;
}

int main() {
    runTest({-2, 1, -3, 4, -1, 2, 1, -5, 4}, 6);
    runTest({1}, 1);
    runTest({5, 4, -1, 7, 8}, 23);
    runTest({-1, -2, -3, -4}, -1);
    runTest({-1, -1, 5, -1, -1}, 5);

    return 0;
}
