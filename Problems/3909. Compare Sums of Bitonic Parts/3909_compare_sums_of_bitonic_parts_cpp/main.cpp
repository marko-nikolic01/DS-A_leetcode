#include <iostream>
#include <vector>

using namespace std;

int compareBitonicSums(vector<int>& nums) {
    long sum = 0;

    int i = nums.size();
    while(--i > 0 && nums[i] < nums[i - 1]) {
        sum += nums[i];
    }

    while(--i > -1) {
        sum -= nums[i];
    }

    return sum < 0 ? 0 : (sum > 0 ? 1 : -1);
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

    cout << "Result: " << compareBitonicSums(nums) << endl;

    cout << endl;
}

int main() {
    test({1, 3, 2, 1}, 1);
    test({2, 4, 5, 2}, 0);
    test({1, 2, 4, 3}, -1);
    test({1, 2, 3, 10, 1}, 0);
    test({1, 1000000000, 999999999, 3, 2, 1}, 1);
}
