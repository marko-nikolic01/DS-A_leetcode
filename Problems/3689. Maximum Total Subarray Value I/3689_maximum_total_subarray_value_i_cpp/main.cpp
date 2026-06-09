#include <iostream>
#include <vector>

using namespace std;

long long maxTotalValue(vector<int>& nums, int k) {
    int minimum = nums[0];
    int maximum = minimum;

    for(unsigned short i = nums.size() - 1; i > 0; --i) {
        if(nums[i] < minimum) {
            minimum = nums[i];
        } else if(nums[i] > maximum) {
            maximum = nums[i];
        }
    }

    return (long)k * (maximum - minimum);
}

void printArray(vector<int> array) {
    for(int a : array) {
        cout << a << " ";
    }
    cout << endl;
}

void test(vector<int> nums, int k, long long expected) {
    cout << "Array: ";
    printArray(nums);

    cout << "k: " << k << endl;

    cout << "Expected: " << expected << endl;

    cout << "Result: " << maxTotalValue(nums, k) << endl;

    cout << endl;
}

int main() {
    test({1, 3, 2}, 2, 4);
    test({4, 2, 5, 1}, 3, 12);
    test({7}, 5, 0);
    test({3, 3, 3, 3}, 4, 0);
    test({0, 1000000000}, 100000, 100000000000000);

    return 0;
}
