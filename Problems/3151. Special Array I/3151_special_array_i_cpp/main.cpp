#include <iostream>
#include <vector>

using namespace std;

bool isArraySpecial(vector<int>& nums) {
    nums.back() &= 1;

    for(short i = nums.size() - 2; i > -1; --i) {
        nums[i] &= 1;

        if(nums[i] == nums[i + 1]) {
            return false;
        }
    }

    return true;
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

    cout << "Result: " << (isArraySpecial(nums) ? "true" : "false") << endl;

    cout << endl;
}

int main() {
    test({1}, true);
    test({2, 1, 4}, true);
    test({4, 3, 1, 6}, false);
    test({5, 2, 7, 8, 9}, true);
    test({2, 3, 4, 5, 6, 7}, true);
    test({10, 1, 20, 3, 30, 5}, true);
    test({7, 9, 11}, false);
    test({8, 1, 2, 3, 4, 5, 6, 7}, true);
    test({2}, true);

    return 0;
}
