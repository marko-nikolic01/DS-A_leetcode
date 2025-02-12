#include <iostream>
#include <vector>

using namespace std;

int maximumSum(vector<int>& nums) {
    vector<int> biggestNumbers(81, 0);

    int sum = -1;
    short digitSum;
    int num;

    for(int i = nums.size() - 1; i > -1; --i) {
        digitSum = nums[i] % 10;
        num = nums[i] / 10;

        while(num > 0) {
            digitSum += num % 10;
            num /= 10;
        }

        if(biggestNumbers[--digitSum] > 0) {
            if(biggestNumbers[digitSum] + nums[i] > sum) {
                sum = biggestNumbers[digitSum] + nums[i];
            }

            if(nums[i] > biggestNumbers[digitSum]) {
                biggestNumbers[digitSum] = nums[i];
            }
        } else {
            biggestNumbers[digitSum] = nums[i];
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

    cout << "Result: " << maximumSum(nums) << endl;

    cout << endl;
}

int main() {
    test({18, 43, 36, 13, 7}, 54);
    test({10, 12, 19, 14}, -1);
    test({51, 71, 17, 42}, 93);
    test({99, 11, 22, 33, 44}, -1);
    test({5, 25, 35, 50}, 55);
    test({1000000000, 999999999}, -1);

    return 0;
}
