#include <iostream>
#include <vector>

using namespace std;

int longestSubarray(vector<int>& nums) {
    int maxStreak = 0;
    int streak = 0;
    int max = 0;

    for(int i = nums.size() - 1; i > -1; --i) {
        if(nums[i] > max) {
            maxStreak = 1;
            streak = 1;
            max = nums[i];
        } else if(nums[i] == max) {
            if(++streak > maxStreak) {
                maxStreak = streak;
            }
        } else {
            streak = 0;
        }
    }

    return maxStreak;
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

    cout << "Result: " << longestSubarray(nums) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 3, 3, 2, 2}, 2);
    test({1, 2, 3, 4}, 1);
    test({5, 5, 5, 1, 5, 5}, 3);
    test({1, 3, 3, 3, 2}, 3);
    test({7, 7, 6, 7, 7, 7, 5}, 3);

    return 0;
}
