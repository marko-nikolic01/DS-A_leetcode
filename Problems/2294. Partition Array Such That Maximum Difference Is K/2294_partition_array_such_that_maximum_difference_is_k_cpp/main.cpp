#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partitionArray(vector<int>& nums, int k) {
    int partitions = 0;
    int start = 100001;

    sort(nums.begin(), nums.end());

    for(int i = nums.size() - 1; i > -1; --i) {
        if(nums[i] < start) {
            ++partitions;
            start = nums[i] - k;
        }
    }

    return partitions;
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

    cout << "Result: " << partitionArray(nums, k) << endl;

    cout << endl;
}

int main() {
    test({3, 6, 1, 2, 5}, 2, 2);
    test({1, 2, 3}, 1, 2);
    test({2, 2, 4, 5}, 0, 3);
    test({1, 10, 20, 30, 40}, 5, 5);
    test({5, 5, 5, 5, 5}, 0, 1);

    return 0;
}
