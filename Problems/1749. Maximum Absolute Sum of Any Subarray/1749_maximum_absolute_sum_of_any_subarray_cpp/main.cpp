#include <iostream>
#include <vector>

using namespace std;

int maxAbsoluteSum(vector<int>& nums) {
    int sum = 0;

    int min = 0;
    int max = 0;

    for(int i = nums.size() - 1; i > -1; --i) {
        if(nums[i] > 0) {
            if(max > 0) {
                max += nums[i];
            } else {
                max = nums[i];
            }

            min += nums[i];

            if(max > sum) {
                sum = max;
            }
        } else {
            if(min < 0) {
                min += nums[i];
            } else {
                min = nums[i];
            }

            max += nums[i];

            if(-min > sum) {
                sum = -min;
            }
        }
    }

    return sum;
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

    cout << "Result: " << maxAbsoluteSum(nums) << endl;

    cout << endl;
}

int main() {
    test({1, -3, 2, 3, -4}, 5);
    test({2, -5, 1, -4, 3, -2}, 8);
    test({-1, -2, -3, -4, -5}, 15);
    test({5, -2, 3, -1, 2, -3, 4}, 8);
    test({10, -20, 30, -40, 50}, 50);
    test({10000, -9999, 9998, -9997, 9996}, 10000);

    return 0;
}
