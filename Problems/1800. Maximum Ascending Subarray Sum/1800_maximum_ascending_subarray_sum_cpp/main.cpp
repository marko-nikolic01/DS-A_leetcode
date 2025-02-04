#include <iostream>
#include <vector>

using namespace std;

int maxAscendingSum(vector<int>& nums) {
    short sum = nums.back();
    short currentSum = sum;

    for(short i = nums.size() - 2; i > -1; --i) {
        if(nums[i] < nums[i + 1]) {
            currentSum += nums[i];
        } else {
            if(currentSum > sum) {
                sum = currentSum;
            }

            currentSum = nums[i];
        }
    }

    return sum > currentSum ? sum : currentSum;
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

    cout << "Result: " << maxAscendingSum(nums) << endl;

    cout << endl;
}

int main(){
    test({10, 20, 30, 5, 10, 50}, 65);
    test({10, 20, 30, 40, 50}, 150);
    test({12, 17, 15, 13, 10, 11, 12}, 33);
    test({100}, 100);
    test({5, 10, 20, 50, 40, 30, 20, 10}, 85);
    test({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 55);
    test({10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, 10);
    test({3, 1, 6, 5, 10, 15, 2, 1}, 30);

    return 0;
}
