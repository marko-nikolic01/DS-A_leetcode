#include <iostream>
#include <vector>

using namespace std;

int minOperations(vector<int>& nums) {
    int operations = 0;

    for(int i = nums.size() - 1; i > 1; --i) {
        if(nums[i] < 1) {
            nums[i - 1] ^= 1;
            nums[i - 2] ^= 1;

            ++operations;
        }
    }

    return nums[0] < 1 || nums[1] < 1 ? -1 : operations;
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

    cout << "Result: " << minOperations(nums) << endl;

    cout << endl;
}

int main() {
    test({0,1,1,1,0,0}, 3);
    test({0,1,1,1}, -1);
    test({1,1,1,1,1}, 0);
    test({0,0,0,0,0,0}, 2);
    test({1,0,1,0,1,0,1}, 3);
    test({0,0,1,0,1,1,0,0,1}, -1);

    return 0;
}
