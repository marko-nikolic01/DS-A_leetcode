#include <iostream>
#include <vector>

using namespace std;

bool canAliceWin(vector<int>& nums) {
    if(nums[0] > 9) {
        nums[0] = -nums[0];
    }

    for(int i = nums.size() - 1; i > 0; --i) {
        if(nums[i] > 9) {
            nums[0] -= nums[i];
        } else {
            nums[0] += nums[i];
        }
    }

    return nums[0] != 0;
}

void test(vector<int> nums, bool expected) {
    cout << "Input: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (canAliceWin(nums) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test({10, 3, 2}, true);
    test({9, 9, 10}, true);
    test({1, 2, 3, 4, 10}, false);
    test({11, 23, 9, 9, 8, 6, 2}, false);
    test({1}, true);
    test({10}, true);

    return 0;
}
