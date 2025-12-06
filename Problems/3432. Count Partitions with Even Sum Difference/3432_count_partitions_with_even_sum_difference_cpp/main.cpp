#include <iostream>
#include <vector>

using namespace std;

int countPartitions(vector<int>& nums) {
    short sum = 0;

    short n = nums.size();
    for(short i = --n; i > -1; --i) {
        sum += nums[i];
    }

    return (sum & 1) < 1 ? n : 0;
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

    cout << "Result: " << countPartitions(nums) << endl;

    cout << endl;
}

int main() {
    test({10, 10, 3, 7, 6}, 4);
    test({1, 2, 2}, 0);
    test({2, 4, 6, 8}, 3);
    test({5, 1, 7, 4, 5}, 4);
    test({3, 5, 7, 9}, 3);

    return 0;
}
