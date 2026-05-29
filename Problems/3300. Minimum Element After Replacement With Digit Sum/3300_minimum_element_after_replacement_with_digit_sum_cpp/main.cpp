#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int minElement(vector<int>& nums) {
    short minimumDigitSum = SHRT_MAX;
    short digitSum;

    for(short i = nums.size() - 1; i > -1; --i) {
        digitSum = 0;

        while(nums[i] > 0) {
            digitSum += nums[i] % 10;
            nums[i] /= 10;
        }

        if(digitSum < minimumDigitSum) {
            minimumDigitSum = digitSum;
        }
    }

    return minimumDigitSum;
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

    cout << "Result: " << minElement(nums) << endl;

    cout << endl;
}

int main() {
    test({10, 12, 13, 14}, 1);
    test({1, 2, 3, 4}, 1);
    test({999, 19, 199}, 10);
    test({9999}, 36);
    test({19, 28, 37, 46}, 10);

    return 0;
}
