#include <iostream>
#include <vector>

using namespace std;

double findMaxAverage(vector<int>& nums, int k) {
    int max;
    int sum = 0;

    for(int i = 0; i < k; ++i) {
        sum += nums[i];
    }
    max = sum;

    int n = nums.size();
    for(int i = k; i < n; ++i) {
        sum += nums[i] - nums[i - k];

        if(sum > max) {
            max = sum;
        }
    }

    return (double)max / k;
}

void runTest(vector<int> nums, int k, double expected) {
    cout << "Input: ";
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "k: " << k << endl;

    double result = findMaxAverage(nums, k);

    cout << "Expected: " << expected << endl;
    cout << "Result: " << result << endl;
    cout << endl;
}

int main() {
    vector<int> nums1 = {1, 12, -5, -6, 50, 3};
    int k1 = 4;
    double expected1 = 12.75000;
    runTest(nums1, k1, expected1);

    vector<int> nums2 = {5, 5, 5, 5};
    int k2 = 2;
    double expected2 = 5.00000;
    runTest(nums2, k2, expected2);

    vector<int> nums3 = {0, 4, 0, 3, 2};
    int k3 = 1;
    double expected3 = 4.00000;
    runTest(nums3, k3, expected3);

    vector<int> nums4 = {-1, -2, -3, -4, -5, -6, -7, -8, -9};
    int k4 = 3;
    double expected4 = -2.00000;
    runTest(nums4, k4, expected4);

    vector<int> nums5 = {10, 2, 3, 5, 7, 1, 0};
    int k5 = 3;
    double expected5 = 5.00000;
    runTest(nums5, k5, expected5);

    return 0;
}
