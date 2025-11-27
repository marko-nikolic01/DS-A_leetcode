#include <iostream>
#include <vector>
#include <climits>

using namespace std;

long long maxSubarraySum(vector<int>& nums, int k) {
    long sum = 0;
    long maximumSum = LONG_LONG_MIN;
    vector<long> kSum(k, LONG_LONG_MAX >> 1);

    kSum[k - 1] = 0;

    int n = nums.size();
    for(int i = 0; i < n; ++i) {
        sum += nums[i];
        maximumSum = max(maximumSum, sum - kSum[i % k]);
        kSum[i % k] = min(kSum[i % k], sum);
    }

    return maximumSum;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int k, long long expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxSubarraySum(nums, k) << endl;

    cout << endl;
}

int main() {
    test({1, 2}, 1, 3);
    test({-1, -2, -3, -4, -5}, 4, -10);
    test({-5, 1, 2, -3, 4}, 2, 4);
    test({3, -1, 4, -2, 5, -3, 6}, 3, 9);
    test({-1000000000}, 1, -1000000000);

    return 0;
}
