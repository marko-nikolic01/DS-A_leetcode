#include <iostream>
#include <vector>

using namespace std;

int longestMonotonicSubarray(vector<int>& nums) {
    short length = 1;

    short increasingStreak = 1;
    short decreasingStreak = 1;

    for(short i = nums.size() - 2; i > -1; --i) {
        if(nums[i] > nums[i + 1]) {
            decreasingStreak = 1;

            if(++increasingStreak > length) {
                length = increasingStreak;
            }
        } else if(nums[i] < nums[i + 1]) {
            increasingStreak = 1;

            if(++decreasingStreak > length) {
                length = decreasingStreak;
            }
        } else {
            increasingStreak = 1;
            decreasingStreak = 1;
        }
    }

    return length;
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

    cout << "Result: " << longestMonotonicSubarray(nums) << endl;

    cout << endl;
}

int main() {
    test({1, 4, 3, 3, 2}, 2);
    test({3, 3, 3, 3}, 1);
    test({3, 2, 1}, 3);
    test({1, 2, 3, 4, 5}, 5);
    test({5, 4, 3, 2, 1}, 5);
    test({1, 3, 2, 4, 3, 5}, 2);
    test({10, 20, 30, 25, 15, 5, 6, 7, 8}, 4);
    test({1}, 1);

    return 0;
}
