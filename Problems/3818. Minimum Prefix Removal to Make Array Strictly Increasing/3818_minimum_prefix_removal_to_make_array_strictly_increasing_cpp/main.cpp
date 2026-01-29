#include <iostream>
#include <vector>

using namespace std;

int minimumPrefixLength(vector<int>& nums) {
    for(int i = nums.size() - 1; i > 0; --i) {
        if(nums[i] <= nums[i - 1]) {
            return i;
        }
    }

    return 0;
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

    cout << "Result: " << minimumPrefixLength(nums) << endl;

    cout << endl;
}

int main() {
    test({1, -1, 2, 3, 3, 4, 5}, 4);
    test({4, 3, -2, -5}, 3);
    test({1, 2, 3, 4}, 0);
    test({5, 4, 3, 2, 1}, 4);
    test({1, 1, 1, 2, 3}, 2);

    return 0;
}
