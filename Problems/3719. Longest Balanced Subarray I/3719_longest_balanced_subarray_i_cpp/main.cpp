#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int longestBalanced(vector<int>& nums) {
    short length = 0;
    unordered_map<int, short> odd;
    unordered_map<int, short> even;

    short j;
    short n = nums.size();
    for(short i = 0; i < n; ++i) {
        odd.clear();
        even.clear();

        for(j = i; j < n; ++j) {
            if((nums[j] & 1) < 1) {
                ++even[nums[j]];
            } else {
                ++odd[nums[j]];
            }

            if(odd.size() == even.size() && j - i + 1 > length) {
                length = j - i + 1;
            }
        }
    }

    return length;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int k, int expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << longestBalanced(nums) << endl;

    cout << endl;
}

int main() {
    test({2, 5, 4, 3}, 0, 4);
    test({3, 2, 2, 5, 4}, 0, 5);
    test({1, 2, 3, 2}, 0, 3);
    test({2, 4, 6}, 0, 0);
    test({1, 2}, 0, 2);

    return 0;
}
