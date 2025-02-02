#include <iostream>
#include <vector>

using namespace std;

bool check(vector<int>& nums) {
    short i = nums.size() - 2;

    while(i > -1 && nums[i] <= nums[i + 1]) {
        --i;
    }

    if(i < 0) {
        return true;
    }

    while(--i > -1) {
        if(nums[i] > nums[i + 1]) {
            return false;
        }
    }

    return nums[0] >= nums.back();
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, bool expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Expected: " << (expected ? "true" : "false") << endl;

    cout << "Result: " << (check(nums) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test({3, 4, 5, 1, 2}, true);
    test({2, 1, 3, 4}, false);
    test({1, 2, 3}, true);
    test({6, 10, 6}, true);
    test({1}, true);
    test({2, 1, 4}, false);
    test({4, 3, 1, 6}, false);

    return 0;
}
