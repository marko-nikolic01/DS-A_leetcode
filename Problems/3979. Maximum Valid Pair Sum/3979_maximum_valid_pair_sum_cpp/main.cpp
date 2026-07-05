#include <iostream>
#include <vector>

using namespace std;

int maxValidPairSum(vector<int>& nums, int k) {
    int sum = 0;
    int maximum = 0;

    for(int i = nums.size() - 1 - k; i > -1; --i) {
        if(nums[i + k] > maximum) {
            maximum = nums[i + k];
        }

        if(nums[i] + maximum > sum) {
            sum = nums[i] + maximum;
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

void test(vector<int> nums, int k, int expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxValidPairSum(nums, k) << endl;

    cout << endl;
}


int main() {
    test({1, 3, 5, 2, 8}, 2, 13);
    test({5, 1, 9}, 1, 14);
    test({4, 7}, 1, 11);
    test({1, 2, 3, 4, 5}, 4, 6);
    test({10, 1, 1, 1, 1, 20}, 3, 30);

    return 0;
}
