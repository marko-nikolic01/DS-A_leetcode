#include <iostream>
#include <vector>

using namespace std;

int maximumXOR(vector<int>& nums) {
    int xorSum = 0;

    for(int i = nums.size() - 1; i > -1; --i) {
        xorSum |= nums[i];
    }

    return xorSum;
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

    cout << "Result: " << maximumXOR(nums) << endl;

    cout << endl;
}

int main() {
    test({3, 2, 4, 6}, 7);
    test({1, 2, 3, 9, 2}, 11);
    test({0}, 0);
    test({7, 7, 7}, 7);
    test({5, 1, 12, 3}, 15);

    return 0;
}
