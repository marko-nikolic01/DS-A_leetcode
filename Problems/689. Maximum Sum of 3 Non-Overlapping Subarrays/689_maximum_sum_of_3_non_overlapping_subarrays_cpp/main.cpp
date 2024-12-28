#include <iostream>
#include <vector>

using namespace std;

vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    int n = nums.size() - k;
    vector<int> subarraySums(++n);

    subarraySums[0] = 0;
    for(int i = 0; i < k; ++i) {
        subarraySums[0] += nums[i];
    }

    n += k - 1;
    for(int i = k; i < n; ++i) {
        subarraySums[i - k + 1] = subarraySums[i - k] + nums[i] - nums[i - k];
    }

    n -= 3 * k;

    vector<int> maxLeftSums(++n);
    int max = 0;
    for(int i = 0; i < n; ++i) {
        if(subarraySums[i] > subarraySums[max]) {
            max = i;
        }
        maxLeftSums[i] = max;
    }

    vector<int> maxRightSums(n);
    max = subarraySums.size() - 1;
    for(int i = n - 1; i > -1; --i) {
        if(subarraySums[2 * k + i] >= subarraySums[max]) {
            max = 2 * k + i;
        }
        maxRightSums[i] = max;
    }

    nums.resize(3);
    max = 0;
    for(int i = 0; i < n; ++i) {
        if(subarraySums[maxLeftSums[i]] + subarraySums[i + k] + subarraySums[maxRightSums[i]] > max) {
            max = subarraySums[maxLeftSums[i]] + subarraySums[i + k] + subarraySums[maxRightSums[i]];
            nums[0] = maxLeftSums[i];
            nums[1] = i + k;
            nums[2] = maxRightSums[i];
        }
    }

    return nums;
}

void test(vector<int> nums, int k, vector<int> expected) {
    cout << "Input: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "k: " << k << endl;

    cout << "Expected: ";
    for (int e : expected) {
        cout << e << " ";
    }
    cout << endl;

    cout << "Result: ";
    for (int result : maxSumOfThreeSubarrays(nums, k)) {
        cout << result << " ";
    }
    cout << endl;

    cout << endl;
}

int main() {
    test({17,8,14,11,13,9,4,19,20,6,1,20,6,5,19,8,5,16,20,17}, 5, {0, 7, 14});
    test({1,2,1,2,1,2,1,2,1}, 2, {0, 2, 4});
    test({1,2,1,2,6,7,5,1}, 2, {0, 3, 5});
    test({1, 1, 1, 1, 1, 1, 1, 1, 1}, 3, {0, 3, 6});
    test({10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, 2, {0, 2, 4});
    test({1, 3, 1, 3, 1, 3, 1, 3}, 2, {0, 2, 4});
    test({1, 4, 2, 3, 5, 6, 7, 8}, 3, {1, 4, 2});
    test({1, 1, 1, 1, 1, 1, 1, 1, 1}, 3, {0, 3, 6});
    test({1, 2, 3, 4, 5}, 1, {2, 3, 4});

    return 0;
}
