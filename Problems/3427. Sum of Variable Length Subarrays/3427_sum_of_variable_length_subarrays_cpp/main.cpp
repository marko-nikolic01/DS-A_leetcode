#include <iostream>
#include <vector>

using namespace std;

int subarraySum(vector<int>& nums) {
    int sum = nums[0];

    short n = nums.size();
    for(short i = 1; i < n; ++i) {
        if(i - nums[i] > 0) {
            sum -= nums[i - nums[i] - 1];
        }

        nums[i] += nums[i - 1];
        sum += nums[i];
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

    cout << "Result: " << subarraySum(nums) << endl;

    cout << endl;
}

int main() {
    test({2, 3, 1}, 11);
    test({3, 1, 1, 2}, 13);
    test({1, 1, 1, 1}, 7);
    test({4, 4, 4}, 24);
    test({1, 2, 3, 4}, 20);

    return 0;
}
