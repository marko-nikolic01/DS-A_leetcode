#include <iostream>
#include <vector>

using namespace std;

int waysToSplitArray(vector<int>& nums) {
    int n = nums.size();
    long sum = 0;

    for(int i = 0; i < n; ++i) {
        sum += nums[i];
    }

    long currentSum = 0;
    int splits = 0;

    for(--n; n > 0; --n) {
        currentSum += nums[n];
        sum -= nums[n];

        if(currentSum <= sum) {
            ++splits;
        }
    }

    return splits;
}

void test(vector<int> nums, int expected) {
    cout << "Input: ";
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << waysToSplitArray(nums) << endl;

    cout << endl;
}

int main() {
    test({10, 4, -8, 7}, 2);
    test({2, 3, 1, 0}, 2);
    test({1, 2}, 0);
    test({1000, -100, -1000, 500}, 2);
    test({-1, -2, -3, -4}, 2);
    test({1, 2, 3, 4}, 1);
    test({0, 0, 0, 0}, 3);
    test({100000, -50000, 200000, -100000}, 2);

    return 0;
}
