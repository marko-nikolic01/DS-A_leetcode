#include <iostream>
#include <vector>

using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int subarrays = 0;
    int product = 1;

    short right = nums.size();
    for(short i = --right; i > -1; --i) {
        product *= nums[i];

        while(product >= k && right >= i) {
            product /= nums[right--];
        }

        if(product < k) {
            subarrays += right - i + 1;
        }
    }

    return subarrays;
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

    cout << "Result: " << numSubarrayProductLessThanK(nums, k) << endl;

    cout << endl;
}

int main() {
    test({10, 5, 2, 6}, 100, 8);
    test({1, 2, 3}, 0, 0);
    test({1, 1, 1}, 2, 6);
    test({5, 10, 20}, 50, 3);
    test({100}, 100, 0);

    return 0;
}
