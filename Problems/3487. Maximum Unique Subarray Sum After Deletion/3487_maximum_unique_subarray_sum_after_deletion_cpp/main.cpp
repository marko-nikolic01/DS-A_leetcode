#include <iostream>
#include <vector>

using namespace std;

int maxSum(vector<int>& nums) {
    short sum = 0;
    short maxNonPositive = -101;
    vector<bool> used(101, false);

    for(short i = nums.size() - 1; i > -1; --i) {
        if(nums[i] > 0) {
            if(!used[nums[i]]) {
                sum += nums[i];
                used[nums[i]] = true;
            }
        } else if(nums[i] > maxNonPositive) {
            maxNonPositive = nums[i];
        }
    }

    return sum > 0 ? sum : maxNonPositive;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxSum(nums) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 3, 4, 5}, 15);
    test({1, 1, 0, 1, 1}, 1);
    test({1, 2, -1, -2, 1, 0, -1}, 3);
    test({-100}, -100);
    test({-2, -5, -1, -3}, -1);

    return 0;
}
