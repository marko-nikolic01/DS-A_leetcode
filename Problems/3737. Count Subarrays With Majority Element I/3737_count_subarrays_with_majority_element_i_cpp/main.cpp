#include <iostream>
#include <vector>

using namespace std;

int countMajoritySubarrays(vector<int>& nums, int target) {
    int subarrays = nums[0] == target ? 1 : 0;

    nums[0] = 0;

    short i;
    short n = nums.size();
    for(i = 1; i < n; ++i) {
        nums[i] = nums[i] == target ? subarrays++ : subarrays;
    }

    nums.push_back(subarrays);
    subarrays = 0;

    for(n; n > 0; --n) {
        for(i = n - 1; i > -1; --i) {
            if(nums[n] - nums[i] > ((n - i) >> 1)) {
                ++subarrays;
            }
        }
    }

    return subarrays;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int target, int expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Target: " << target << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << countMajoritySubarrays(nums, target) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 2, 3}, 2, 5);
    test({1, 1, 1, 1}, 1, 10);
    test({1, 2, 3}, 4, 0);
    test({2}, 2, 1);
    test({1, 2, 1, 2, 2}, 2, 8);

    return 0;
}
