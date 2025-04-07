#include <iostream>
#include <vector>

using namespace std;

bool canPartition(vector<int>& nums) {
    int sum = 0;

    int i;
    short n = nums.size();
    for(i = 0; i < n; ++i) {
        sum += nums[i];
    }

    if((sum & 1) > 0) {
        return false;
    }

    sum >>= 1;
    vector<bool> canGetSum(sum + 1, false);
    canGetSum[0] = true;

    for(--n; n > -1; --n) {
        for(i = sum; i >= nums[n]; --i) {
            canGetSum[i] = canGetSum[i] || canGetSum[i - nums[n]];
        }

        if(canGetSum[sum]) {
            return true;
        }
    }

    return false;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, bool expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (canPartition(nums) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test({1, 5, 11, 5}, true);
    test({1, 2, 3, 5}, false);
    test({2, 2, 3, 5}, false);
    test({3, 3, 3, 4, 5}, true);
    test({1, 1, 1, 1, 1, 1}, true);

    return 0;
}
