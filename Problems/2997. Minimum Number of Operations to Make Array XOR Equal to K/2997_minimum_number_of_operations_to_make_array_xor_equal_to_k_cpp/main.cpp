#include <iostream>
#include <vector>

using namespace std;

int minOperations(vector<int>& nums, int k) {
    int xorSum = 0;

    for(int i = nums.size() - 1; i > -1; --i) {
        xorSum ^= nums[i];
    }

    nums[0] = 0;

    while(k > 0) {
        if((k & 1) > 0) {
            if((xorSum & 1) < 1) {
                ++nums[0];
            }
        } else if((xorSum & 1) > 0) {
            ++nums[0];
        }

        k >>= 1;
        xorSum >>= 1;
    }

    while(xorSum > 0) {
        if((xorSum & 1) > 0) {
            ++nums[0];
        }

        xorSum >>= 1;
    }

    return nums[0];
}

void test(vector<int> nums, int k, int expected) {
    cout << "Input: ";
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << minOperations(nums, k) << endl;

    cout << endl;
}

int main() {
    test({2, 1, 3, 4}, 1, 2);
    test({2, 0, 2, 0}, 0, 0);
    test({1, 2, 4, 8}, 7, 1);
    test({0, 0, 0}, 1, 1);
    test({5, 9, 12}, 15, 4);

    return 0;
}
