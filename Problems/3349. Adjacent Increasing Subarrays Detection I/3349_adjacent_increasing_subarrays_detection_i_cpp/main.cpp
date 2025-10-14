#include <iostream>
#include <vector>

using namespace std;

bool hasIncreasingSubarrays(vector<int>& nums, int k) {
    short previous = nums[0];
    short streak = 1;

    nums[0] = 1;

    short n = nums.size();
    for(short i = 1; i < n; ++i) {
        if(nums[i] > previous) {
            ++streak;
        } else {
            streak = 1;
        }

        if(streak >= k && i - k > -1 && nums[i - k] >= k) {
            return true;
        }

        previous = nums[i];
        nums[i] = streak;
    }

    return false;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int k, bool expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "k: " << k << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (hasIncreasingSubarrays(nums, k) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test({2, 5, 7, 8, 9, 2, 3, 4, 3, 1}, 3, true);
    test({1, 2, 3, 4, 4, 4, 4, 5, 6, 7}, 5, false);
    test({-15, 19}, 1, true);
    test({19, 5}, 1, true);
    test({1, 2, 3, 1, 2, 3, 1, 2}, 3, true);
    test({3, 2, 1}, 2, false);

    return 0;
}
