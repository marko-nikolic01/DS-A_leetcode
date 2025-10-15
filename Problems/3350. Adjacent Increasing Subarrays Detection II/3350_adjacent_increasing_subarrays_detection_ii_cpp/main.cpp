#include <iostream>
#include <vector>

using namespace std;

int maxIncreasingSubarrays(vector<int>& nums) {
    int streak = 1;
    int streak1 = 0;
    int streak2 = 1;

    for(int i = nums.size() - 2; i > -1; --i) {
        if(nums[i] < nums[i + 1]) {
            ++streak2;
        } else {
            streak = max(streak, max(streak2 >> 1, min(streak1, streak2)));
            streak1 = streak2;
            streak2 = 1;
        }
    }
    streak = max(streak, max(streak2 >> 1, min(streak1, streak2)));

    return streak;
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

    cout << "Result: " << maxIncreasingSubarrays(nums) << endl;

    cout << endl;
}

int main() {
    test({2, 5, 7, 8, 9, 2, 3, 4, 3, 1}, 3);
    test({1, 2, 3, 4, 4, 4, 4, 5, 6, 7}, 2);
    test({-15, -13, 4, 7}, 2);
    test({1, 2, 3, 4, 5, 6}, 3);
    test({5, 6, 7, 1, 2, 3, 4, 5, 1, 2}, 3);

    return 0;
}
