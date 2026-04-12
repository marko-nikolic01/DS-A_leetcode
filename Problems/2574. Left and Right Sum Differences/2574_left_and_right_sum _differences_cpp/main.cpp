#include <iostream>
#include <vector>

using namespace std;

vector<int> leftRightDifference(vector<int>& nums) {
    int leftSum = 0;
    int rightSum = 0;
    int temp;

    short n = nums.size();
    for(short i = 0; i < n; ++i) {
        leftSum += nums[i];
    }

    while(--n > -1) {
        temp = nums[n];
        leftSum -= temp;
        nums[n] = abs(leftSum - rightSum);
        rightSum += temp;
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
    printArray(leftRightDifference(nums));

    cout << endl;
}

int main() {
    test({10, 4, 8, 3}, {15, 1, 11, 22});
    test({1}, {0});
    test({1, 2, 3}, {5, 2, 3});
    test({100000, 100000, 100000}, {200000, 0, 200000});
    test({5, 1, 3, 2, 4}, {10, 4, 0, 5, 11});

    return 0;
}
