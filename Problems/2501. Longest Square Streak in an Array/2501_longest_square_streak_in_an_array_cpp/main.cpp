#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int longestSquareStreak(vector<int>& nums, unordered_map<int, int>& numbers, int num) {
    if(num > 46340 || numbers.find(num * num) == numbers.end()) {
        numbers[num] = 1;
        return 1;
    }

    numbers[num] = numbers[num * num] > -1 ? numbers[num * num] : longestSquareStreak(nums, numbers, num * num);

    return ++numbers[num];
}

int longestSquareStreak(vector<int>& nums) {
    unordered_map<int, int> numbers;

    for(int i = nums.size() - 1; i > -1; --i) {
        numbers[nums[i]] = -1;
    }

    int longestStreak = 0;

    for(int i = nums.size() - 1; i > -1; --i) {
        if(numbers[nums[i]] == -1) {
            int streak = longestSquareStreak(nums, numbers, nums[i]);
            if(streak > longestStreak) {
                longestStreak = streak;
            }
        }
    }

    return longestStreak > 1 ? longestStreak : -1;
}

void test(vector<int> nums, int expected) {
    cout << "Input: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << longestSquareStreak(nums) << endl;

    cout << endl;
}

int main() {
    test({2, 4, 16}, 3);
    test({3, 5, 7, 9}, 2);
    test({3, 9, 81, 6561}, 4);
    test({2, 3, 10}, -1);
    test({10, 100, 10000, 5, 25, 625}, 3);

    return 0;
}
