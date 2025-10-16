#include <iostream>
#include <vector>

using namespace std;

int findSmallestInteger(vector<int>& nums, int value) {
    vector<int> remainders(value, 0);
    int missing = 0;

    int i;
    for(i = nums.size() - 1; i > -1; --i) {
        ++remainders[nums[i] > -1 ? nums[i] % value : ((nums[i] % value) + value) % value];
    }

    for(i = 0; remainders[i] > 0; i = ++missing % value) {
        --remainders[i];
    }

    return missing;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int value, int expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Value: " << value << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << findSmallestInteger(nums, value) << endl;

    cout << endl;
}

int main() {
    test({1, -10, 7, 13, 6, 8}, 5, 4);
    test({1, -10, 7, 13, 6, 8}, 7, 2);
    test({0,-3}, 4, 2);
    test({0, 1, 2, 3}, 2, 4);
    test({-1, -2, -3, -4}, 3, 3);
    test({5, 10, 15, 20}, 5, 1);

    return 0;
}
