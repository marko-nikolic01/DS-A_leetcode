#include <iostream>
#include <vector>

using namespace std;

int alternatingSum(vector<int>& nums) {
    short i;
    short n = nums.size();
    for(i = 1; i < n; i += 2) {
        nums[0] -= nums[i];
    }

    for(i = 2; i < n; i += 2) {
        nums[0] += nums[i];
    }

    return nums[0];
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

    cout << "Result: " << alternatingSum(nums) << endl;

    cout << endl;
}

int main() {
    test({1, 3, 5, 7}, -4);
    test({100}, 100);
    test({2, 4, 6, 8, 10}, 6);
    test({5, 5, 5, 5, 5}, 5);
    test({10, 20, 30, 40, 50, 60}, -30);

    return 0;
}
