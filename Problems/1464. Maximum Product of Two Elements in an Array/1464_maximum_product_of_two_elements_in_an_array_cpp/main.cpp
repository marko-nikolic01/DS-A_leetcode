#include <iostream>
#include <vector>

using namespace std;

int maxProduct(vector<int>& nums) {
    short maximum1 = nums[0];
    short maximum2 = 0;

    for(short i = nums.size() - 1; i > 0; --i) {
        if(nums[i] >= maximum1) {
            maximum2 = maximum1;
            maximum1 = nums[i];
        } else if(nums[i] > maximum2) {
            maximum2 = nums[i];
        }
    }

    return --maximum1 * --maximum2;
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

    cout << "Result: " << maxProduct(nums) << endl;

    cout << endl;
}

int main() {
    test({3, 4, 5, 2}, 12);
    test({1, 5, 4, 5}, 16);
    test({3, 7}, 12);
    test({10, 2, 5, 2}, 36);
    test({1, 1}, 0);

    return 0;
}
