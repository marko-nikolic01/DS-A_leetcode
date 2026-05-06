#include <iostream>
#include <vector>

using namespace std;

vector<int> countOppositeParity(vector<int>& nums) {
    short odd = 0;
    short even = 0;

    for(short i = nums.size() - 1; i > -1; --i) {
        if((nums[i] & 1) < 1) {
            nums[i] = odd;
            ++even;
        } else {
            nums[i] = even;
            ++odd;
        }
    }

    return nums;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, vector<int> expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Expected: ";
    printArray(expected);

    cout << "Result: ";
    printArray(countOppositeParity(nums));

    cout << endl;
}

int main() {
    test({1, 2, 3, 4}, {2, 1, 1, 0});
    test({1}, {0});
    test({2}, {0});
    test({2, 4, 6}, {0, 0, 0});
    test({1, 3, 5}, {0, 0, 0});
    test({1, 2}, {1, 0});

    return 0;
}
