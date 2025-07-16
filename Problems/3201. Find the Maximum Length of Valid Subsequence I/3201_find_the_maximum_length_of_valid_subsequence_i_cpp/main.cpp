#include <iostream>
#include <vector>

using namespace std;

int maximumLength(vector<int>& nums) {
    int even;
    int odd;
    int evenOdd = 1;
    bool nextEvenOdd;

    int n = nums.size();
    if((nums[--n] & 1) < 1) {
        even = 1;
        odd = 0;
        nextEvenOdd = false;
    } else {
        even = 0;
        odd = 1;
        nextEvenOdd = true;
    }

    for(--n; n > -1; --n) {
        if((nums[n] & 1) < 1) {
            ++even;

            if(nextEvenOdd) {
                ++evenOdd;
                nextEvenOdd = false;
            }
        } else {
            ++odd;

            if(!nextEvenOdd) {
                ++evenOdd;
                nextEvenOdd = true;
            }
        }
    }

    return max(even, max(odd, evenOdd));
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

    cout << "Result: " << maximumLength(nums) << endl;

    cout << endl;
}

int main() {
    test({1, 2, 3, 4}, 4);
    test({1, 2, 1, 1, 2, 1, 2}, 6);
    test({2, 4, 6, 8, 10}, 5);
    test({1, 3}, 2);
    test({1, 2, 4, 5, 7, 8}, 4);

    return 0;
}
