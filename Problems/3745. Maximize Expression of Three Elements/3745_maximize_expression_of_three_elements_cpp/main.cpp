#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximizeExpressionOfThree(vector<int>& nums) {
    sort(nums.begin(), nums.end(), greater<int>());

    return nums[0] + nums[1] - nums.back();
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

    cout << "Result: " << maximizeExpressionOfThree(nums) << endl;

    cout << endl;
}

int main() {
    test({1, 4, 2, 5}, 8);
    test({-2, 0, 5, -2, 4}, 11);
    test({-4, -8, -10}, -2);
    test({-5, -2, -9, -1}, 6);
    test({0, 0, 0}, 0);

    return 0;
}
