#include <iostream>
#include <vector>

using namespace std;

int repeatedNTimes(vector<int>& nums) {
    for(short i = nums.size() - 4; i > -1; --i) {
        if(nums[i] == nums[i + 1] || nums[i] == nums[i + 2] || nums[i] == nums[i + 3]) {
            return nums[i];
        } else if(nums[i + 1] == nums[i + 2] || nums[i + 1] == nums[i + 3]) {
            return nums[++i];
        } else if(nums[i + 2] == nums[i + 3]) {
            return nums[i + 2];
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

    cout << "Result: " << repeatedNTimes(nums) << endl;

    cout << endl;
}

int main()
{
    test({1, 2, 3, 3}, 3);
    test({2, 1, 2, 5, 3, 2}, 2);
    test({5, 1, 5, 2, 5, 3, 5, 4}, 5);
    test({9, 9, 8, 9, 7, 6, 5, 9}, 9);

    return 0;
}
