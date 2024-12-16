#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int duplicateNumbersXOR(vector<int>& nums) {
    int xorSum = 0;

    unordered_set<int> numbers;

    for(int i = nums.size() - 1; i > -1; --i) {
        if(numbers.find(nums[i]) == numbers.end()) {
            numbers.insert(nums[i]);
        } else {
            xorSum ^= nums[i];
        }
    }

    return xorSum;
}

void test(vector<int> nums, int expected) {
    cout << "Input: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << duplicateNumbersXOR(nums) << endl;

    cout << endl;
}

int main() {
    test({4, 1, 2, 4, 3, 5, 5}, 1);
    test({1, 2, 3, 4, 5}, 0);
    test({7, 7, 8, 8, 9, 9, 7, 7}, 6);
    test({6, 6, 6, 6, 6, 6}, 6);
    test({10, 10, 20, 20, 30, 40, 40}, 54);
    test({1, 2}, 0);
    test({42}, 0);

    return 0;
}
