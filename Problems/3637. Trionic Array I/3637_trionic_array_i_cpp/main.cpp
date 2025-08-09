#include <iostream>
#include <vector>

using namespace std;

bool isTrionic(vector<int>& nums) {
    short i;
    short n = nums.size();
    for(i = --n - 1; i > -1; --i) {
        if(nums[i] >= nums[i + 1]) {
            break;
        }
    }

    if(i == --n) {
        return false;
    }

    n = ++i;
    for(--i; i > -1; --i) {
        if(nums[i] <= nums[i + 1]) {
            break;
        }
    }

    if(i == --n) {
        return false;
    }

    n = ++i;
    for(--i; i > -1; --i) {
        if(nums[i] >= nums[i + 1]) {
            break;
        }
    }

    return i < 0 && i < --n;
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

    cout << "Result: " << (isTrionic(nums) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test({1, 3, 5, 4, 2, 6}, true);
    test({2, 1, 3}, false);
    test({4, 1, 5, 2, 3}, false);
    test({1, 2, 3, 2, 1, 2, 3}, true);
    test({1, 2, 3, 4, 3, 2, 1}, false);

    return 0;
}
