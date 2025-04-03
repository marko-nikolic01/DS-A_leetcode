#include <iostream>
#include <vector>

using namespace std;

long long maximumTripletValue(vector<int>& nums) {
    long value = 0;
    int maximum = nums[0];
    int maximumDifference = 0;

    int n = nums.size();
    for(int i = 1; i < n; ++i) {
        value = max(value, (long)maximumDifference * nums[i]);
        maximumDifference = max(maximumDifference, maximum - nums[i]);
        maximum = max(maximum, nums[i]);
    }

    return value;
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, long long expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maximumTripletValue(nums) << endl;

    cout << endl;
}

int main() {
    test({12, 6, 1, 2, 7}, 77);
    test({1, 10, 3, 4, 19}, 133);
    test({1, 2, 3}, 0);
    test({5, 5, 5, 5, 5}, 0);
    test({100, 50, 25, 10, 5}, 1250);
    test({1000000, 500000, 250000, 100000, 1}, 125000000000);

    return 0;
}
