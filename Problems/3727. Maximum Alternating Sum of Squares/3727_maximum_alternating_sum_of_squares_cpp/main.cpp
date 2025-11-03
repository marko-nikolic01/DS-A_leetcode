#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long maxAlternatingSum(vector<int>& nums) {
    long sum = 0;

    int i;
    int n = nums.size();
    for(i = 0; i < n; ++i) {
        if(nums[i] < 0) {
            nums[i] = -nums[i];
        }
    }

    sort(nums.begin(), nums.end());

    for(i = 0; i < --n; ++i) {
        sum += nums[n] * nums[n] - nums[i] * nums[i];
    }

    return i == n ? sum + nums[i] * nums[i] : sum;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, long long expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxAlternatingSum(nums) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 3}, 12);
    test({1, -1, 2, -2, 3, -3}, 16);
    test({5, 5, 5, 5}, 0);
    test({-4, -3, -2, -1}, 20);
    test({10, -10, 8, -8, 1}, 199);

    return 0;
}
