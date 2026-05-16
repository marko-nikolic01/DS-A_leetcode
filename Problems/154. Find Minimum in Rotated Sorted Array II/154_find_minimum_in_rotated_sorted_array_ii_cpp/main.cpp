#include <iostream>
#include <vector>

using namespace std;

short findMin(vector<int>& nums, short left, short right) {
    return (left == right || nums[left] < nums[right]) ? nums[left] : min(findMin(nums, left, (left + right) >> 1), findMin(nums, ((left + right) >> 1) + 1, right));
}

int findMin(vector<int>& nums) {
    return findMin(nums, 0, nums.size() - 1);
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
    test({1, 3, 5}, 1);
    test({2, 2, 2, 0, 1}, 0);
    test({3, 4, 5, 1, 2}, 1);
    test({4, 5, 6, 7, 0, 1, 2}, 0);
    test({11, 13, 15, 17}, 11);
    test({2, 1}, 1);
    test({1}, 1);

    return 0;
}
