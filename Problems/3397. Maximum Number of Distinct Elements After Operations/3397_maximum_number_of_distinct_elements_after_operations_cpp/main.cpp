#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxDistinctElements(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());

    int distinctElements = 0;

    int previous = nums.back() + 10000000001;
    int streak = 1;
    for(int i = nums.size() - 2; i > -1; --i) {
        if(nums[i] == nums[i + 1]) {
            ++streak;
        } else {
            if(nums[i + 1] + k + 1 < previous) {
                previous = nums[i + 1] + k + 1;
            }
            int lower = nums[i + 1] - k - 1;

            if(streak < previous - lower) {
                distinctElements += streak;
                previous = previous - streak;
            } else {
                distinctElements += previous - lower - 1;
                previous = ++lower;
            }

            streak = 1;
        }
    }

    if(nums[0] + k + 1 < previous) {
        previous = nums[0] + k + 1;
    }
    int lower = nums[0] - k  - 1;

    distinctElements += streak < previous - lower ? streak : previous - lower - 1;

    return distinctElements;
}

void test(vector<int> nums, int k, int expected) {
    cout << "Input: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxDistinctElements(nums, k) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 2, 3, 3, 4}, 2, 6);
    test({4, 4, 4, 4}, 1, 3);
    test({56, 56, 54, 54}, 0, 2);
    test({6, 7, 6, 6, 7}, 1, 4);
    test({31, 31, 30, 31, 30, 29}, 2, 6);
    test({10, 10, 10, 5, 10}, 1, 4);

    return 0;
}
