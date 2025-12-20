#include <iostream>
#include <vector>

using namespace std;

int maximumSum(vector<int>& nums) {
    int sum;
    vector<vector<int>> remainders(3, vector<int>(3, 0));

    int i;
    for(i = nums.size() - 1; i > -1; --i) {
        sum = nums[i] % 3;

        if(nums[i] > remainders[sum][0]) {
            remainders[sum][2] = remainders[sum][1];
            remainders[sum][1] = remainders[sum][0];
            remainders[sum][0] = nums[i];
        } else if(nums[i] > remainders[sum][1]) {
            remainders[sum][2] = remainders[sum][1];
            remainders[sum][1] = nums[i];
        } else if(nums[i] > remainders[sum][2]) {
            remainders[sum][2] = nums[i];
        }
    }

    sum = remainders[0][0] > 0 && remainders[1][0] > 0 && remainders[2][0] > 0 ? remainders[0][0] + remainders[1][0] + remainders[2][0] : 0;

    for(i = 0; i < 3; ++i) {
        if(remainders[i][2] > 0 && remainders[i][0] + remainders[i][1] + remainders[i][2] > sum) {
            sum = remainders[i][0] + remainders[i][1] + remainders[i][2];
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
    test({4, 2, 3, 1}, 9);
    test({2, 1, 5}, 0);
    test({2, 8, 2}, 12);
    test({3, 6, 9, 12}, 27);
    test({5, 11, 14, 2, 8, 3}, 33);

    return 0;
}
