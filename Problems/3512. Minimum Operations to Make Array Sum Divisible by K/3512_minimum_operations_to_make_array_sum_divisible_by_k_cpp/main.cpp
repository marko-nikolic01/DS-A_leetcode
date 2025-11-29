#include <iostream>
#include <vector>

using namespace std;

int minOperations(vector<int>& nums, int k) {
    for(short i = nums.size() - 1; i > 0; --i) {
        nums[0] += nums[i];
    }

    return nums[0] % k;
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

    cout << "Result: " << minOperations(nums, k) << endl;

    cout << endl;
}

int main() {
    test({3, 9, 7}, 5, 4);
    test({4, 1, 3}, 4, 0);
    test({3, 2}, 6, 5);
    test({10, 20, 30}, 10, 0);
    test({7}, 4, 3);

    return 0;
}
