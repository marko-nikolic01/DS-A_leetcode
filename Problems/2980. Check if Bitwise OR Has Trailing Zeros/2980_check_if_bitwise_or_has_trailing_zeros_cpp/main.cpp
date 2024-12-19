#include <iostream>
#include <vector>

using namespace std;

bool hasTrailingZeros(vector<int>& nums) {
    for(int i = nums.size() - 1; i > -1; --i) {
        if((nums[i] & 1) == 0) {
            for(--i; i > -1; --i) {
                if((nums[i] & 1) == 0) {
                    return true;
                }
            }
            return false;
        }
    }
    return false;
}

void test(vector<int> nums, bool expected) {
    cout << "Input: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (hasTrailingZeros(nums) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test({1, 2}, false);
    test({1, 2, 4}, true);
    test({3, 5, 7, 8}, false);
    test({6, 2}, true);
    test({3, 5, 7}, false);
    test({2, 4, 6, 8}, true);
    test({9, 1, 3, 2}, false);
    test({10, 15, 18, 21, 24, 27, 30}, true);
    test({1, 3, 5, 7, 9, 11, 13}, false);
    test({8, 10, 14, 16, 18, 20, 3}, true);
    test({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, true);
    test({1, 1, 1, 1, 1, 1, 1, 2}, false);

    return 0;
}
