#include <iostream>
#include <vector>

using namespace std;

int maximumProduct(vector<int>& nums) {
    int max1 = nums[0];
    int max2 = -1001;
    int max3 = -1001;

    int min1 = nums[0];
    int min2 = 1001;

    int n = nums.size();
    for(int i = 1; i < n; ++i) {
        if(nums[i] > max1) {
            max3 = max2;
            max2 = max1;
            max1 = nums[i];
        } else if(max2 == -1001 || nums[i] > max2) {
            max3 = max2;
            max2 = nums[i];
        } else if(max3 == -1001 || nums[i] > max3) {
            max3 = nums[i];
        }

        if(nums[i] < min1) {
            min2 = min1;
            min1 = nums[i];
        } else if(min2 == 1001 || nums[i] < min2) {
            min2 = nums[i];
        }
    }

    if(max1 * max2 * max3 > max1 * min1 * min2) {
        return max1 * max2 * max3;
    }
    return max1 * min1 * min2;
}

void testMaximumProduct(vector<int> nums, int expected) {
    int result = maximumProduct(nums);
    cout << "Input: ";
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;
    cout << "Result: " << result << endl;
    cout << endl;
}

int main() {
    testMaximumProduct({1, 2, 3}, 6); // Expected: 6
    testMaximumProduct({1, 2, 3, 4}, 24); // Expected: 24
    testMaximumProduct({-1, -2, -3, -4}, -6); // Expected: -6
    testMaximumProduct({-10, -10, 5, 2}, 500); // Expected: 500
    testMaximumProduct({1, -4, 3, -6, 7, 0}, 168); // Expected: 168

    return 0;
}
