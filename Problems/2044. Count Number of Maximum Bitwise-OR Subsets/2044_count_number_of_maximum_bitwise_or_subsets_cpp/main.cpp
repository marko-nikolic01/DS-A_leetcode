#include <iostream>
#include <vector>

using namespace std;

int countMaxOrSubsets(vector<int>& nums) {
    int maxOr = 0;

    int i;
    int n = nums.size();
    for(i = --n; i > -1; --i) {
        maxOr |= nums[i];
    }

    int numberOfBadSubsets = 0;
    int count;

    for(int mask = maxOr; mask > 0; mask = --mask & maxOr){
        count = 0;

        for(i = n; i > -1; --i) {
            if((nums[i] & mask) < 1) {
                ++count;
            }
        }

        numberOfBadSubsets += (__builtin_popcount(mask) % 2 ? 1 : -1) * ((1 << count) - 1);
    }

    return (1 << ++n) - ++numberOfBadSubsets;
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

    cout << "Result: " << countMaxOrSubsets(nums) << endl;

    cout << endl;
}

int main() {
    test({3, 1}, 2);
    test({2, 2, 2}, 7);
    test({3, 2, 1, 5}, 6);
    test({1, 2, 4}, 1);
    test({8, 1, 2, 4}, 1);

    return 0;
}
