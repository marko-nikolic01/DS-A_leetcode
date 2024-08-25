#include <iostream>
#include <vector>

using namespace std;

int pivotIndex(vector<int>& nums) {
    int sum = 0;

    int n = nums.size();
    for(int i = 0; i < n; ++i) {
        sum += nums[i];
    }

    int halfSum = 0;
    for(int i = 0; i < n; halfSum += nums[i++]) {
        if(halfSum * 2 == sum - nums[i]) {
            return i;
        }
    }

    return -1;
}

void printTestCase(vector<int>& nums, int expected) {
    cout << "Input: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << pivotIndex(nums) << endl;

    cout << endl;
}

int main() {
    vector<int> test1 = {1, 7, 3, 6, 5, 6};
    vector<int> test2 = {1, 2, 3};
    vector<int> test3 = {2, 1, -1};
    vector<int> test4 = {1, 1, 1, 1, 1, 1};
    vector<int> test5 = {1, 2, 3, 4, 5, 6};

    printTestCase(test1, 3);
    printTestCase(test2, -1);
    printTestCase(test3, 0);
    printTestCase(test4, -1);
    printTestCase(test5, -1);

    return 0;
}
