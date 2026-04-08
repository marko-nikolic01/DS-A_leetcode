#include <iostream>
#include <vector>

using namespace std;

int firstUniqueEven(vector<int>& nums) {
    vector<short> occurrences(101, 0);

    short i;
    short n = nums.size();
    for(i = --n; i > -1; --i) {
        ++occurrences[nums[i]];
    }

    while(++i <= n) {
        if((nums[i] & 1) < 1 && occurrences[nums[i]] == 1) {
            return nums[i];
        }
    }

    return -1;
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

    cout << "Result: " << firstUniqueEven(nums) << endl;

    cout << endl;
}

int main() {
    test({3, 4, 2, 5, 4, 6}, 2);
    test({4, 4}, -1);
    test({1, 3, 5, 7}, -1);
    test({6, 3, 5, 2, 2}, 6);
    test({1, 10, 3, 10, 4, 6}, 4);
    test({42}, 42);

    return 0;
}
