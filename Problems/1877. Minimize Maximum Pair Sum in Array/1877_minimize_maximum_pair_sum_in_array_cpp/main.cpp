#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int pairSum = 2;

    int n = nums.size();
    for(int i = 0; i < --n; ++i) {
        if(nums[i] + nums[n] > pairSum) {
            pairSum = nums[i] + nums[n];
        }
    }

    return pairSum;
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

    cout << "Result: " << minPairSum(nums) << endl;

    cout << endl;
}

int main() {
    test({3, 5, 2, 3}, 7);
    test({3, 5, 4, 2, 4, 6}, 8);
    test({1, 2}, 3);
    test({1, 1, 1, 1}, 2);
    test({9, 2, 3, 8, 1, 7}, 10);

    return 0;
}
