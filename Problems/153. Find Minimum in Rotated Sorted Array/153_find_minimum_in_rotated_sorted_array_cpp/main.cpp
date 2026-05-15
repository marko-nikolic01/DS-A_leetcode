#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int>& nums) {
    short n = nums.size();
    if(nums[0] < nums[--n]) {
        return nums[0];
    }

    short left = 0;
    short right = n;
    short middle = -1;

    while(left < right) {
        middle = (left + right) >> 1;

        if(nums[middle] > nums[n]) {
            if(nums[middle + 1] < nums[middle]) {
                break;
            }

            left = ++middle;
        } else {
            right = --middle;
        }
    }

    return nums[++middle];
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

    cout << "Result: " << findMin(nums) << endl;

    cout << endl;
}

int main() {
    test({3, 4, 5, 1, 2}, 1);
    test({4, 5, 6, 7, 0, 1, 2}, 0);
    test({11, 13, 15, 17}, 11);
    test({2, 1}, 1);
    test({1}, 1);

    return 0;
}
