#include <iostream>
#include <vector>

using namespace std;

int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    int temp;

    for(int i = 0; i < n; ++i) {
        if(nums[i] > 0 && nums[i] <= n) {
            if(nums[nums[i] - 1] != nums[i]) {
                temp = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                nums[i--] = temp;
            }
        }
    }

    for(int i = 0; i < n; ++i) {
        if(nums[i] < 1 || --nums[i] != i) {
            return ++i;
        }
    }

    return ++n;
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

    cout << "Result: " << firstMissingPositive(nums) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 0}, 3);
    test({3, 4, -1, 1}, 2);
    test({7, 8, 9, 11, 12}, 1);
    test({2}, 1);
    test({3, 3, 1, 4, 0}, 2);

    return 0;
}
