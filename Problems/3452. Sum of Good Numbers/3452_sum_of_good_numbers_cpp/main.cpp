#include <iostream>
#include <vector>

using namespace std;

int sumOfGoodNumbers(vector<int>& nums, int k) {
    int sum = 0;

    short n = nums.size();
    for(short i = --n; i > -1; --i) {
        if((i < k || nums[i] > nums[i - k]) && (n - i < k || nums[i] > nums[i + k])) {
            sum += nums[i];
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

    cout << "Result: " << sumOfGoodNumbers(nums, k) << endl;

    cout << endl;
}

int main() {
    test({1, 3, 2, 1, 5, 4}, 2, 12);
    test({2, 1}, 1, 2);
    test({1, 5, 2, 4, 1}, 1, 9);
    test({3, 3, 3, 3}, 2, 0);
    test({1, 2, 10, 2, 1}, 1, 10);

    return 0;
}
