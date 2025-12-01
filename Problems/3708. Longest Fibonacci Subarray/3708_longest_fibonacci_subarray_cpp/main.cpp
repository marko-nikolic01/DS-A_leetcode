#include <iostream>
#include <vector>

using namespace std;

int longestSubarray(vector<int>& nums) {
    int subarray = 2;
    int currentSubarray = 2;

    int n = nums.size();
    for(int i = 2; i < n; ++i) {
        if(nums[i] == nums[i - 1] + nums[i - 2]) {
            if(++currentSubarray > subarray) {
                subarray = currentSubarray;
            }
        } else {
            currentSubarray = 2;
        }
    }

    return subarray;
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

    cout << "Result: " << longestSubarray(nums) << endl;

    cout << endl;
}

int main() {
    test({1, 1, 1, 1, 2, 3, 5, 1}, 5);
    test({5, 2, 7, 9, 16}, 5);
    test({1000000000, 1000000000, 1000000000}, 2);
    test({1, 1, 1, 2}, 3);
    test({3, 4, 7, 11, 18, 29, 47}, 7);

    return 0;
}
