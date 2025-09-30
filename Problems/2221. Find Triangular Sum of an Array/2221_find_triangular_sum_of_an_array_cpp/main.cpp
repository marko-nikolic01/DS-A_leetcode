#include <iostream>
#include <vector>

using namespace std;

int triangularSum(vector<int>& nums) {
    short i;
    for(short n = nums.size(); n > 1; --n) {
        for(i = 1; i < n; ++i) {
            nums[i - 1] = (nums[i - 1] + nums[i]) % 10;
        }
    }

    return nums[0];
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

    cout << "Result: " << triangularSum(nums) << endl;

    cout << endl;
}


int main() {
    test({1, 2, 3, 4, 5}, 8);
    test({5}, 5);
    test({0, 3, 3, 4, 1, 2, 6, 4, 9, 3, 5, 1, 7, 7, 3, 0, 3, 2, 5, 1, 9, 0, 2, 6, 3, 9, 2, 5, 9, 2, 6, 4, 2, 9, 7, 2, 0, 3, 0, 1, 1, 2, 7, 8, 6, 4, 4, 5}, 5);
    test({9, 9, 9, 9}, 2);
    test({2, 4, 6, 8, 0}, 6);

    return 0;
}
